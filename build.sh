#!/bin/bash
mkdir -p $1/build
g++ $(find $1 -iname "*.cpp") -o $1/build/main