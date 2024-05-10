#!/bin/bash

total_to_sync=0

sync_directories() {
  local src_dir=$1
  local dest_dir=$2

  rsync -az --delete "$src_dir/" "$dest_dir/"
}

display_progress() {
  local width=40
  local total=$1
  local completed=$2
  local completed_bar=$(( $completed * $width / $total - 1 ))
  local left_bar=$(( $width - $completed_bar ))
  # local percent=$(( $completed_bar * 100 / $width ))
  local percent=$(( $completed * 100 / $total ))

  printf "Progress:["
  for ((i=1; i<=completed_bar; i++)); do
    printf "="
  done
  printf ">"
  for ((i=1; i<left_bar; i++)); do
    printf " "
  done
  printf "] $percent%%"
  echo -en "\r"
}

while IFS= read -r line; do
  # Trim leading and trailing whitespace from the line
  line=$(echo "$line" | xargs)

  # Check if the line is empty or a comment and skip it
  if [[ -z "$line" || "$line" == \#* ]]; then
    continue
  fi

  (( total_to_sync++ ))

done < sync_tool.conf

echo "Total to sync: $total_to_sync"
completed=0

display_progress $total_to_sync $completed

while IFS= read -r line; do
  # Trim leading and trailing whitespace from the line
  line=$(echo "$line" | xargs)

  # Check if the line is empty or a comment and skip it
  if [[ -z "$line" || "$line" == \#* ]]; then
    continue
  fi

  # Get the src and dest from the line
  src=$(echo "$line" | awk -F " -> " '{print $1}')
  dest=$(echo "$line" | awk -F " -> " '{print $2}')

  # test if the src exists
  if [[ ! -d $src ]]; then
	break
  fi

  # test if the dest exist, if not creating it
  if [[ ! -d $dest ]]; then
	sudo mkdir -p "$dest"
	sudo chown -R $USER:$USER "$dest"
  fi

  # Sync src and dest directories with progress
  sync_directories "$src" "$dest"

  (( completed++ ))
  display_progress $total_to_sync $completed

 #  echo "$src  ->  $dest"

done < sync_tool.conf

echo -en "\nSync completed\n"
