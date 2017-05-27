#!/bin/bash
set -ex

gcc -c -fPIC -o main.o main.c
gcc -shared -fPIC -lX11 -o liblibcursorpos_x64.so main.o
