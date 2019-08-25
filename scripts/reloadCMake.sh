#!/bin/bash

if [ ! -d "/home/Official/cmake-build-debug/unix" ]; then
	mkdir /home/Official/cmake-build-debug/unix
fi

if [ ! -d "/home/Official/cmake-build-release/unix" ]; then
	mkdir /home/Official/cmake-build-release/unix
fi

cd /home/Official/cmake-build-debug/unix/
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug /home/Official

cd /home/Official/cmake-build-release/unix/
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release /home/Official

