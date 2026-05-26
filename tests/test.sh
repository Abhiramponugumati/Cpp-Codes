#!/usr/bin/env bash

reward_dir="/logs/verifier"
reward_file="$reward_dir/reward.txt"

if ! mkdir -p "$reward_dir" 2>/dev/null; then
    sudo mkdir -p "$reward_dir"
    sudo chown "$(id -u):$(id -g)" "$reward_dir"
fi

if python3 -m pytest -q; then
    echo 1 > "$reward_file"
else
    echo 0 > "$reward_file"
fi
