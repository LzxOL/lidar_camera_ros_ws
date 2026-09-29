#!/usr/bin/env bash
set -euo pipefail

DATA="${1:-/home/root1/lzx_ws/datasets}"
MODE="${2:---apply}"
if [ "$MODE" != "--apply" ] && [ "$MODE" != "--dry-run" ]; then
  echo "usage: $0 [datasets_dir] [--apply|--dry-run]" >&2
  exit 2
fi
STAMP="$(date +%Y%m%d_%H%M%S)"
MANIFEST="$DATA/organization_manifest_${STAMP}.tsv"
ROLLBACK="$DATA/rollback_organization_${STAMP}.sh"

if [ "$MODE" = "--apply" ]; then
  mkdir -p "$DATA/00_configs" "$DATA/00_tools" "$DATA/01_source_datasets" \
    "$DATA/02_bags" "$DATA/03_calibration_results" "$DATA/04_experiments" \
    "$DATA/05_archives" "$DATA/06_logs" "$DATA/99_legacy"
else
  MANIFEST="/tmp/organization_manifest_${STAMP}.tsv"
fi
printf 'old_path\tnew_path\ttype\n' > "$MANIFEST"

if [ "$MODE" = "--dry-run" ]; then
  echo "DRY RUN: no files or links will be changed" >&2
fi

move_link() {
  local old="$1" new="$2" kind="$3"
  [ -e "$old" ] || [ -L "$old" ] || return 0
  if [ -e "$new" ] || [ -L "$new" ]; then
    echo "SKIP existing target: $old -> $new" >&2
    return 0
  fi
  if [ "$MODE" = "--dry-run" ]; then
    printf 'would_move\t%s\t%s\t%s\n' "$old" "$new" "$kind" >> "$MANIFEST"
    echo "WOULD MOVE: $old -> $new" >&2
    return 0
  fi
  mkdir -p "$(dirname "$new")"
  if ! mv -- "$old" "$new"; then
    echo "ERROR moving: $old -> $new" >&2
    return 0
  fi
  if ! ln -s "$new" "$old"; then
    echo "ERROR linking (moved item retained at target): $old -> $new" >&2
    return 0
  fi
  printf '%s\t%s\t%s\n' "$old" "$new" >> "$MANIFEST"
}

dataset_name() {
  case "$1" in
    aprilgrid-8-22-1*) echo aprilgrid-8-22-1 ;;
    aprilgrid-8-22-3*) echo aprilgrid-8-22-3 ;;
    aprilgrid-8-22-4*) echo aprilgrid-8-22-4 ;;
    aprilgrid-8-27-1*) echo aprilgrid-8-27-1 ;;
    aprilgrid-8-29-1*) echo aprilgrid-8-29-1 ;;
    aprilgrid-8-29-2*) echo aprilgrid-8-29-2 ;;
    aprilgrid-8-29-3*) echo aprilgrid-8-29-3 ;;
    aprilgrid-8-31-1*) echo aprilgrid-8-31-1 ;;
    aprilgrid-8-31-2*) echo aprilgrid-8-31-2 ;;
    aprilgrid-8-31-3*) echo aprilgrid-8-31-3 ;;
    aprilgrid-9-4-3*) echo aprilgrid-9-4-3-METERS ;;
    aprilgrid-9-4-4*) echo aprilgrid-9-4-4-METERS ;;
    aprilgrid-fov183-8-29-1*) echo fov183-8-29-1 ;;
    aprilgrid-fov183-8-29-2*) echo fov183-8-29-2 ;;
    aprilgrid-fov183-8-29-3*) echo fov183-8-29-3 ;;
    aprilgrid-iqoo*) echo aprilgrid-iqoo ;;
    aprilgrid_8_14*) echo aprilgrid_8_14 ;;
    aprilgrid_8_18*) echo aprilgrid_8_18 ;;
    aprilgrid_8_19-12*) echo aprilgrid_8_19-12 ;;
    aprilgrid_8_20_3*) echo aprilgrid_8_20_3 ;;
    aprilgrid_8_20_2*) echo aprilgrid_8_20_2 ;;
    aprilgrid_8_20*) echo aprilgrid_8_20 ;;
    OSMO*|8-31-*) echo OSMO ;;
    fov_155*) echo Action_Pro5_fov155 ;;
    *) echo unsorted ;;
  esac
}

is_source_dir() {
  case "$1" in
    Action\ Pro5|OSMO|aprilgrid-iqoo|aprilgrid_8_19-12|aprilgrid_8_20|aprilgrid_8_20_2|aprilgrid_8_20_3|aprilgrid-9-4-3-METERS|aprilgrid-9-4-4-METERS|aprilgrid-fov183-8-29-1|aprilgrid-fov183-8-29-2|aprilgrid-fov183-8-29-3|aprilgrid-fov183-8-29-1_mono8|aprilgrid-fov183-8-29-2_mono8|aprilgrid-fov183-8-29-3_mono8) return 0 ;;
    *) return 1 ;;
  esac
}

while IFS= read -r -d '' old; do
  base="$(basename "$old")"
  if is_source_dir "$base"; then
    move_link "$old" "$DATA/01_source_datasets/$base" source_dataset
  elif [ "$base" = kalibr_frame_budget_staging ]; then
    move_link "$old" "$DATA/04_experiments/$base" experiment
  elif [ "$base" = basalt ]; then
    move_link "$old" "$DATA/00_tools/$base" tool
  elif [ "$base" = old ]; then
    move_link "$old" "$DATA/99_legacy/$base" legacy
  elif [[ "$base" == *kalibr* || "$base" == *tartancalib* || "$base" == *basalt* || "$base" == *calib* ]]; then
    move_link "$old" "$DATA/03_calibration_results/$(dataset_name "$base")/$base" result
  else
    move_link "$old" "$DATA/99_legacy/$base" legacy
  fi
done < <(find "$DATA" -mindepth 1 -maxdepth 1 -type d ! -name '00_configs' ! -name '00_tools' ! -name '01_source_datasets' ! -name '02_bags' ! -name '03_calibration_results' ! -name '04_experiments' ! -name '05_archives' ! -name '06_logs' ! -name '99_legacy' -print0)

while IFS= read -r -d '' old; do
  base="$(basename "$old")"
  case "$base" in
    *.bag) move_link "$old" "$DATA/02_bags/$(dataset_name "$base")/$base" bag ;;
    *.tar.gz|*.zip) move_link "$old" "$DATA/05_archives/$(dataset_name "$base")/$base" archive ;;
    *.log) move_link "$old" "$DATA/06_logs/$(dataset_name "$base")/$base" log ;;
    aprilgrid_6_6.yaml|test.py) move_link "$old" "$DATA/00_configs/$base" config ;;
    *.yaml|*.pdf|*.txt|*.csv|*.md) move_link "$old" "$DATA/03_calibration_results/$(dataset_name "$base")/legacy_exports/$base" export ;;
    *) move_link "$old" "$DATA/99_legacy/$base" legacy ;;
  esac
done < <(find "$DATA" -mindepth 1 -maxdepth 1 -type f -print0)

if [ "$MODE" = "--dry-run" ]; then
  echo "manifest=$MANIFEST"
  exit 0
fi

cat > "$ROLLBACK" <<'EOF'
#!/usr/bin/env bash
set -euo pipefail
SELF="$(readlink -f "$0")"
MANIFEST="${SELF/rollback_organization_/organization_manifest_}"
MANIFEST="${MANIFEST%.sh}.tsv"
tail -n +2 "$MANIFEST" | while IFS=$'\t' read -r old new kind; do
  [ -L "$old" ] && [ -e "$new" ] || continue
  rm -- "$old"
  mv -- "$new" "$old"
done
EOF
chmod +x "$ROLLBACK"

cat > "$DATA/README.md" <<EOF
# datasets organization

- 00_configs: target YAML and helper configuration.
- 00_tools: local calibration tools.
- 01_source_datasets: original image/data directories.
- 02_bags: ROS bags grouped by dataset.
- 03_calibration_results: Kalibr/TartanCalib/Basalt outputs grouped by dataset.
- 04_experiments: frame-budget and staging experiments.
- 05_archives: result tar.gz/zip packages.
- 06_logs: loose logs.
- 99_legacy: ambiguous or old material.

Original top-level paths are retained as symlinks.
Mapping: $(basename "$MANIFEST")
Rollback: $(basename "$ROLLBACK")
No files are deleted; large log.pkl files are unchanged.
EOF

printf 'manifest=%s\nrollback=%s\n' "$MANIFEST" "$ROLLBACK"
