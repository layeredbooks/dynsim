#!/bin/bash

set -euo pipefail

rm -rf ./build

cxx_compiler=$(command -v clang++)

cmake -S . -B build \
  -DCMAKE_CXX_COMPILER="$cxx_compiler" \

cmake --build build
