#!/usr/bin/bash

mkdir -p build
cd build
cmake ..
make
./src/out