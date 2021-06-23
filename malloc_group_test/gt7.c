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

int *d[1000000];

	int i,j,cnt,cnt2;
cnt = 0;
cnt2 = 0;
//a = malloc(1024);
for (i=0;i<1000;i++)
{
for (j=0;j<1000;j++)
{
d[cnt] = malloc_group(sizeof(int),1);
*d[cnt] = cnt;
		printf("%p %d\n",d[cnt],*d[cnt]);
cnt++;
}
for (j=0;j<500;j++)
{
if (*d[cnt2] != cnt2)
	return 0;
		free(d[cnt2]);
cnt2++;
}
}
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
