#!/usr/bin/env bash

mkdir -p /logs/verifier

if python3 -m pytest -q; then
    echo 1 > /logs/verifier/reward.txt
else
    echo 0 > /logs/verifier/reward.txt
fi
