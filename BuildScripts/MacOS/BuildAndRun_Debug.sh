#!/bin/bash

cd ../../build
./premake5.osx gmake2

cd ../
make config=debug_arm64
./bin/Debug/BasicGame-2D