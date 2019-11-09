#!/bin/bash

cd build
make
cd ..
./build/pid &

../term2_sim_linux/term2_sim.x86_64