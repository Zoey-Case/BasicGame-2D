#!/bin/bash

cd ../../build
./premake5.osx gmake2

cd ../
make config=release_arm64
./bin/Release/BasicGame-2D