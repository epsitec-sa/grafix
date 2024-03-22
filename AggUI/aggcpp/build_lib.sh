#!/usr/bin/env bash
cd "$(dirname "$0")"
echo "Building AntigrainCPP with cmake"
cmake -B ./build && cmake --build ./build
