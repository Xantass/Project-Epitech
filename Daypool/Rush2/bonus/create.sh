#!/bin/bash
cd lib/my && ./build.sh && cd ../..
gcc -o rush2 *.c -I./include -L./lib/my -lmy
