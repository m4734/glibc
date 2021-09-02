gcc -L../build/install/lib -I../build/install/include -Wl,--rpath=../build/install/lib -Wl,--dynamic-linker=../build/install/lib/ld-linux-x86-64.so.2 gt8.c
