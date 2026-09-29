#!/usr/bin/env bash
# Re-run only the Kalibr models that did not start in the first baseline pass.
set -u

ROOT=/home/root1/lzx_ws/datasets/aprilgrid-9-4-3-METERS
ROOT_C=/data/aprilgrid-9-4-3-METERS
BAG="$ROOT_C/aprilgrid-9-4-3-METERS_right_mono8_ros1.bag"
TOPIC=/vimbax_camera_right/image_raw
TARGET=/data/aprilgrid_6_6.yaml
RUNNER_LOG="$ROOT/kalibr_missing_models_20260909_runner.log"
exec >>"$RUNNER_LOG" 2>&1

run_one() {
  local label="$1" model="$2"
  local out="$ROOT/kalibr_${label}_right_20260909_r2"
  local out_c="$ROOT_C/kalibr_${label}_right_20260909_r2"
  [[ -f "$out/status.txt" ]] && return
  mkdir -p "$out"
  printf 'RUNNING Kalibr %s at %s\n' "$label" "$(date -Is)"
  docker exec ros-melodic bash -lc \
    "source /ros_entrypoint.sh; source /catkin_ws/devel/setup.bash; cd '$out_c'; env OMP_NUM_THREADS=4 OPENBLAS_NUM_THREADS=4 MKL_NUM_THREADS=4 NUMEXPR_NUM_THREADS=4 MPLBACKEND=Agg taskset -c 0-3 xvfb-run -a -s '-screen 0 1024x768x24 -nolisten tcp' rosrun kalibr kalibr_calibrate_cameras --bag '$BAG' --target '$TARGET' --models '$model' --topics '$TOPIC' --no-shuffle --mi-tol -1 --dont-show-report --verbose" \
    >"$out/run.log" 2>&1
  local code=$?
  echo "exit_code=$code" >"$out/status.txt"
  printf 'FINISHED Kalibr %s exit_code=%s at %s\n' "$label" "$code" "$(date -Is)"
}

run_one ds ds-none
run_one ucm omni-none
run_one eucm eucm-none
