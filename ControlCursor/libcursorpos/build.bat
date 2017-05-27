gcc -c -o main.o main.c
gcc -shared -fPIC -o libcursorpos_x64.dll main.o

gcc -m32 -c -o main.o main.c
gcc -m32 -shared -fPIC -o libcursorpos_x86.dll main.o