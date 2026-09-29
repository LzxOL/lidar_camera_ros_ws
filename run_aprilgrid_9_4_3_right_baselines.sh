#!/usr/bin/env bash
# Run the comparable right-camera intrinsic calibration baselines for
# aprilgrid-9-4-3-METERS.  Results are deliberately versioned by date so an
# older invalid run is retained for diagnosis.
set -u

DATA_ROOT=/home/root1/lzx_ws/datasets/aprilgrid-9-4-3-METERS
DATA_IN_CONTAINER=/data/aprilgrid-9-4-3-METERS
RIGHT_BAG_HOST="$DATA_ROOT/aprilgrid-9-4-3-METERS_right_mono8_ros1.bag"
RIGHT_BAG_CONTAINER="$DATA_IN_CONTAINER/aprilgrid-9-4-3-METERS_right_mono8_ros1.bag"
TOPIC=/vimbax_camera_right/image_raw
TARGET_CONTAINER=/data/aprilgrid_6_6.yaml
TARGET_HOST=/home/root1/lzx_ws/datasets/aprilgrid_6_6.yaml
BASALT=/home/root1/lzx_ws/project/calibration_tools/basalt/build/release/basalt_calibrate
BASALT_TARGET=/home/root1/lzx_ws/project/lidar_camera_ros_ws/basalt_aprilgrid_6x6_actionpro.json
RUN_LOG="$DATA_ROOT/right_baselines_20260909_runner.log"

mkdir -p "$DATA_ROOT"
exec >>"$RUN_LOG" 2>&1
printf '\n===== baseline runner started: %s =====\n' "$(date -Is)"

run_kalibr() {
  local label="$1" model="$2"
  local out="$DATA_ROOT/kalibr_${label}_right_20260909"
  if [[ -f "$out/status.txt" ]]; then
    echo "Kalibr $label already has status: $(tr '\n' ' ' < "$out/status.txt")"
    return
  fi
  mkdir -p "$out"
  echo "RUNNING Kalibr $label"
  printf '%q ' docker exec ros-melodic bash -lc \
    "source /ros_entrypoint.sh; cd '$DATA_IN_CONTAINER/kalibr_${label}_right_20260909'; env OMP_NUM_THREADS=4 OPENBLAS_NUM_THREADS=4 MKL_NUM_THREADS=4 NUMEXPR_NUM_THREADS=4 MPLBACKEND=Agg taskset -c 0-3 xvfb-run -a -s '-screen 0 1024x768x24 -nolisten tcp' rosrun kalibr kalibr_calibrate_cameras --bag '$RIGHT_BAG_CONTAINER' --target '$TARGET_CONTAINER' --models '$model' --topics '$TOPIC' --no-shuffle --mi-tol -1 --dont-show-report --verbose" \
    > "$out/command.txt"
  docker exec ros-melodic bash -lc \
    "source /ros_entrypoint.sh; cd '$DATA_IN_CONTAINER/kalibr_${label}_right_20260909'; env OMP_NUM_THREADS=4 OPENBLAS_NUM_THREADS=4 MKL_NUM_THREADS=4 NUMEXPR_NUM_THREADS=4 MPLBACKEND=Agg taskset -c 0-3 xvfb-run -a -s '-screen 0 1024x768x24 -nolisten tcp' rosrun kalibr kalibr_calibrate_cameras --bag '$RIGHT_BAG_CONTAINER' --target '$TARGET_CONTAINER' --models '$model' --topics '$TOPIC' --no-shuffle --mi-tol -1 --dont-show-report --verbose" \
    >"$out/run.log" 2>&1
  local code=$?
  echo "exit_code=$code" > "$out/status.txt"
  echo "FINISHED Kalibr $label exit_code=$code"
}

run_tartan() {
  local label="$1" model="$2"
  local out="$DATA_ROOT/tartancalib_${label}_right_20260909"
  if [[ -f "$out/status.txt" ]]; then
    echo "TartanCalib $label already has status: $(tr '\n' ' ' < "$out/status.txt")"
    return
  fi
  mkdir -p "$out"
  echo "RUNNING TartanCalib $label"
  printf '%q ' docker exec ros-melodic bash -lc \
    "source /ros_entrypoint.sh; source /tartan_ws/devel/setup.bash; cd '$DATA_IN_CONTAINER/tartancalib_${label}_right_20260909'; env PYTHONUNBUFFERED=1 OMP_NUM_THREADS=4 OPENBLAS_NUM_THREADS=4 MKL_NUM_THREADS=4 NUMEXPR_NUM_THREADS=4 MPLBACKEND=Agg taskset -c 0-3 xvfb-run -a -s '-screen 0 1024x768x24 -nolisten tcp' python -u /tartan_ws/src/tartancalib/aslam_offline_calibration/kalibr/python/tartan_calibrate --bag '$RIGHT_BAG_CONTAINER' --target '$TARGET_CONTAINER' --models '$model' --topics '$TOPIC' --no-shuffle --mi-tol -1 --dont-show-report --verbose --save_dir '$DATA_IN_CONTAINER/tartancalib_${label}_right_20260909'" \
    > "$out/command.txt"
  docker exec ros-melodic bash -lc \
    "source /ros_entrypoint.sh; source /tartan_ws/devel/setup.bash; cd '$DATA_IN_CONTAINER/tartancalib_${label}_right_20260909'; env PYTHONUNBUFFERED=1 OMP_NUM_THREADS=4 OPENBLAS_NUM_THREADS=4 MKL_NUM_THREADS=4 NUMEXPR_NUM_THREADS=4 MPLBACKEND=Agg taskset -c 0-3 xvfb-run -a -s '-screen 0 1024x768x24 -nolisten tcp' python -u /tartan_ws/src/tartancalib/aslam_offline_calibration/kalibr/python/tartan_calibrate --bag '$RIGHT_BAG_CONTAINER' --target '$TARGET_CONTAINER' --models '$model' --topics '$TOPIC' --no-shuffle --mi-tol -1 --dont-show-report --verbose --save_dir '$DATA_IN_CONTAINER/tartancalib_${label}_right_20260909'" \
    >"$out/run.log" 2>&1
  local code=$?
  echo "exit_code=$code" > "$out/status.txt"
  echo "FINISHED TartanCalib $label exit_code=$code"
}

run_basalt() {
  local label="$1" model="$2"
  local out="$DATA_ROOT/basalt_${label}_right_20260909"
  if [[ -f "$out/status.txt" ]]; then
    echo "Basalt $label already has status: $(tr '\n' ' ' < "$out/status.txt")"
    return
  fi
  mkdir -p "$out"
  echo "RUNNING Basalt $label"
  printf '%q ' env OMP_NUM_THREADS=4 OPENBLAS_NUM_THREADS=4 MKL_NUM_THREADS=4 NUMEXPR_NUM_THREADS=4 taskset -c 0-3 "$BASALT" \
    --dataset-path "$RIGHT_BAG_HOST" --dataset-type bag --result-path "$out" --aprilgrid "$BASALT_TARGET" --cam-types "$model" --no-gui \
    > "$out/command.txt"
  env OMP_NUM_THREADS=4 OPENBLAS_NUM_THREADS=4 MKL_NUM_THREADS=4 NUMEXPR_NUM_THREADS=4 taskset -c 0-3 "$BASALT" \
    --dataset-path "$RIGHT_BAG_HOST" --dataset-type bag --result-path "$out" --aprilgrid "$BASALT_TARGET" --cam-types "$model" --no-gui \
    >"$out/run.log" 2>&1
  local code=$?
  echo "exit_code=$code" > "$out/status.txt"
  echo "FINISHED Basalt $label exit_code=$code"
}

# Kalibr KB right has already completed successfully in kalibr_kb_right.
run_kalibr ds ds-none
run_kalibr ucm omni-none
run_kalibr eucm eucm-none

run_tartan kb pinhole-equi
run_tartan ds ds-none
run_tartan ucm omni-none
run_tartan eucm eucm-none

run_basalt kb4 kb4
run_basalt ds ds
run_basalt eucm eucm

# The installed Basalt binary advertises no UCM camera type.  Keep an explicit
# record rather than relabelling its pinhole model as UCM.
unsupported="$DATA_ROOT/basalt_ucm_right_20260909"
mkdir -p "$unsupported"
printf '%s\n' 'not_run: current basalt_calibrate supports eucm, ds, kb4, pinhole; it does not support ucm' > "$unsupported/status.txt"

printf '===== baseline runner finished: %s =====\n' "$(date -Is)"
