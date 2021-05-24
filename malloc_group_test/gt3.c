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
	void* b[100];
	void* c[100];
	void* a[100];

	int i;
	for (i=0;i<10;i++)
		b[i] = malloc_group(1024,0);
	for (i=0;i<10;i++)
		c[i] = malloc_group(1024,1);
	for (i=0;i<10;i++)
		a[i] = malloc(1024);

//	void* c0 = (void*)calloc(5,1024);

	for (i=0;i<10;i++)
		printf("b %d %p\n",i,b[i]);
	for (i=0;i<10;i++)
		printf("c %d %p\n",i,c[i]);
	for (i=0;i<10;i++)
		printf("a %d %p\n",i,a[i]);

	for (i=0;i<10;i++)
	{
		free(a[i]);
		free(b[i]);
		free(c[i]);
	}
	for (i=0;i<10;i++)
	{
		b[i] = malloc_group(1024,1);
		c[i] = malloc_group(1024,0);
		a[i] = malloc(1024);
	}
	for (i=0;i<10;i++)
		printf("b %d %p\n",i,b[i]);
	for (i=0;i<10;i++)
		printf("c %d %p\n",i,c[i]);
	for (i=0;i<10;i++)
		printf("a %d %p\n",i,a[i]);



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
