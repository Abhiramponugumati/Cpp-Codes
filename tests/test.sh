#!/bin/bash
mkdir -p /logs/verifier

if [ -d /tests ]; then
    TEST_PATH=/tests/test_outputs.py
else
    TEST_PATH="$(cd "$(dirname "$0")" && pwd)/test_outputs.py"
fi

uvx pytest "$TEST_PATH" -v
STATUS=$?

if [ $STATUS -eq 0 ]; then
    echo 1 > /logs/verifier/reward.txt
else
    echo 0 > /logs/verifier/reward.txt
fi
