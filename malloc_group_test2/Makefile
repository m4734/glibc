malloc_group.o: malloc_group.c malloc_group.h
	gcc -c -o malloc_group.o -L$(glibc_install)/lib -I$(glibc_install)/include -Wl,--rpath=$(glibc_install)/lib -Wl,--dynamic-linker=$(glibc_install)/lib/ld-linux-x86-64.so.2 malloc_group.c
