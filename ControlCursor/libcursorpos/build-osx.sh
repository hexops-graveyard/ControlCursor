#!/bin/bash
set -ex

gcc -c -o main.o ./main.c
gcc -shared -fPIC -o libcursorpos_x64.bundle main.o -lobjc -framework ApplicationServices
