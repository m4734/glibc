#include<stdio.h>
//#include<stdlib.h>
//#include<gnu/libc-version.h>
#include"malloc.h"
int main()
{
//	printf("%s\n",gnu_get_libc_version());
//	void* aaa = NULL;
//	aaa = valloc(1024);
//	printf("%p\n",aaa);
//	free(aaa);

	void* a1 = (void*)malloc(1024);
	void* v1 = (void*)valloc(1024);
	/*
	void* b1 = (void*)malloc_group(1024,0);
	void* c1 = (void*)malloc_group(1024,1);
	void* b2 = (void*)malloc_group(1024,0);
	void* c2 = (void*)malloc_group(1024,1);
*/
	void* c0 = (void*)calloc(5,1024);

	printf("a1 %p\n",a1);
	/*
	printf("b1 %p\n",b1);
	printf("c1 %p\n",c1);
	printf("b2 %p\n",b2);
	printf("c2 %p\n",c2);
*/
	printf("v1 %p\n",v1);

	printf("c0 %p\n",c0);

//	free(b2);
//	free(c2);
/*
	b2 = malloc_group(1024,1);
	c2 = malloc_group(1024,0);

	printf("d %p\n",b2);
	printf("e %p\n",c2);
*/

	void* z1 = (void*)malloc_group(1024,0);
	printf("z1 %p\n",z1);

	return 0;
}
