#include<stdio.h>
//#include<gnu/libc-version.h>
#include"malloc.h"

void *malloc_group(size_t size,volatile size_t group);

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
//a = malloc(1024);
		a = malloc_group(1024,0);
b = malloc(1024);
//		b = malloc_group(1024,1);
		c = malloc_group(1024,1);

//	void* c0 = (void*)calloc(5,1024);

	printf("%p %p %p\n",a,b,c);

	for (i=0;i<1024;i++)
		b[i] = 'b';
	for (i=0;i<1024;i++)
		c[i] = 'c';
	for (i=0;i<1024;i++)
		a[i] = 'a';

	for (i=0;i<10;i++)
		printf("a %c b %c c %c\n",a[i],b[i],c[i]);

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
