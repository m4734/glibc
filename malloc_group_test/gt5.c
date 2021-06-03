#include<stdio.h>
//#include<gnu/libc-version.h>
#include"malloc.h"
int main()
{
//	printf("%s\n",gnu_get_libc_version());
//	void* aaa = NULL;
//	aaa = valloc(1024);
//	printf("%p\n",aaa);
//	free(aaa);

//	void* a1 = (void*)malloc(1024);
//	void* v1 = (void*)valloc(1024);
	char* b;
	char* c;
	char* a;

	int i;
		b = malloc_group(1024,0);
		c = malloc_group(1024,1);
		a = malloc(1024);

//	void* c0 = (void*)calloc(5,1024);

	printf("%p %p %p\n",a,b,c);

size_t sa = *((size_t*)(a-sizeof(size_t)));
size_t sb = *((size_t*)(b-sizeof(size_t)));
size_t sc = *((size_t*)(c-sizeof(size_t)));

printf("%lu %lu %lu\n",sa,sb,sc);

		free(a);
		free(b);
		free(c);

/*

	free(b2);
	free(c2);

	b2 = malloc_group(1024,1);
	c2 = malloc_group(1024,0);

	printf("b3 %p\n",b2);
	printf("c3 %p\n",c2);

*/

	return 0;
}
