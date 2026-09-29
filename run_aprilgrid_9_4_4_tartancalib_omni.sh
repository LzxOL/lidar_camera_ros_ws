#!/usr/bin/env bash
set -u

out=/data/aprilgrid-9-4-4-METERS/tartancalib_omni_right
bag=/data/aprilgrid-9-4-4-METERS/aprilgrid-9-4-4-METERS_right_mono8_ros1.bag
target=/data/aprilgrid_6_6.yaml
topic=/vimbax_camera_right/image_raw

docker exec ros-melodic bash -lc "
  out='$out'
  mkdir -p \"\$out\"
  source /ros_entrypoint.sh
  source /tartan_ws/devel/setup.bash
  printf '%s\n' 'TartanCalib omni-none right, aprilgrid-9-4-4-METERS' > \"\$out/command.sh\"
  env PYTHONUNBUFFERED=1 OMP_NUM_THREADS=4 OPENBLAS_NUM_THREADS=4 \
      MKL_NUM_THREADS=4 NUMEXPR_NUM_THREADS=4 MPLBACKEND=Agg \
      taskset -c 0-3 xvfb-run -a -s '-screen 0 1024x768x24 -nolisten tcp' \
      python -u /tartan_ws/src/tartancalib/aslam_offline_calibration/kalibr/python/tartan_calibrate \
        --bag '$bag' \
        --target '$target' \
        --models omni-none \
        --topics '$topic' \
        --no-shuffle --mi-tol -1 --dont-show-report --verbose \
        --save_dir \"\$out\" > \"\$out/run.log\" 2>&1
  code=\$?
  echo \"exit_code=\$code\" | tee \"\$out/status.txt\"
  exit 0
"
