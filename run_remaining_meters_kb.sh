#!/usr/bin/env bash
# Continue the 3 m / 4 m mono KB jobs one at a time.  Generated output is
# copied into an unambiguous per-camera directory after each successful run.
set -euo pipefail

PROJECT=/home/root1/lzx_ws/project/lidar_camera_ros_ws
DATASETS=/home/root1/lzx_ws/datasets
CONTAINER=ros-melodic
TARGET=/data/aprilgrid_6_6.yaml

ensure_container() {
  docker start "$CONTAINER" >/dev/null 2>&1 || true
}

wait_for_current_kalibr() {
  while docker exec "$CONTAINER" pgrep -f kalibr_calibrate_cameras >/dev/null 2>&1; do
    sleep 30
  done
}

archive_if_successful() {
  local root=$1 side=$2 stem=$3
  local output="$root/kalibr_kb_$side"
  local log="$output/run.log"
  ensure_container
  if ! grep -q 'Calibration complete\.' "$log"; then
    echo "$(date -Is) $stem $side did not complete; see $log" >&2
    return 1
  fi
  cp "$root/$stem-camchain.yaml" "$output/camchain.yaml"
  cp "$root/$stem-results-cam.txt" "$output/results-cam.txt"
  cp "$root/$stem-report-cam.pdf" "$output/report-cam.pdf"
  echo "$(date -Is) archived $stem $side"
}

start_kb() {
  local name=$1 side=$2
  local root="/data/$name"
  local stem="${name}_mono8_ros1"
  local topic="/vimbax_camera_${side}/image_raw"
  local output="$root/kalibr_kb_$side"
  ensure_container
  docker exec -d "$CONTAINER" bash -lc "mkdir -p '$output' && cd '$output' && source /ros_entrypoint.sh && source /catkin_ws/devel/setup.bash && exec env PYTHONUNBUFFERED=1 OMP_NUM_THREADS=1 OPENBLAS_NUM_THREADS=1 MKL_NUM_THREADS=1 NUMEXPR_NUM_THREADS=1 MPLBACKEND=Agg taskset -c 0 xvfb-run -a -s '-screen 0 1024x768x24 -nolisten tcp' rosrun kalibr kalibr_calibrate_cameras --bag '$root/$stem.bag' --target '$TARGET' --models pinhole-equi --topics '$topic' --no-shuffle --mi-tol -1 --dont-show-report --verbose > run.log 2>&1"
  wait_for_current_kalibr
  archive_if_successful "$root" "$side" "$stem"
}

# The caller starts this while 3m-right is already active.
wait_for_current_kalibr
archive_if_successful /data/aprilgrid-9-4-3-METERS right aprilgrid-9-4-3-METERS_mono8_ros1

name=aprilgrid-9-4-4-METERS
mkdir -p "$DATASETS/$name"
python3 "$PROJECT/convert_stereo_pngs_to_mono8_ros1_bag.py" \
  "$PROJECT/$name" "$DATASETS/$name/${name}_mono8_ros1.bag"

start_kb "$name" left
start_kb "$name" right
echo "$(date -Is) all remaining METERS KB jobs completed"
