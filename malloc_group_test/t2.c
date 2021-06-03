#include<stdio.h>
#include<gnu/libc-version.h>
#include <stdlib.h>
int main()
{
	printf("%s\n",gnu_get_libc_version());
//	void* aaa = NULL;
//	aaa = valloc(1024);
//	printf("%p\n",aaa);
//	free(aaa);

//	printf("v1 %p\n",v1);

//	printf("c0 %p\n",c0);

	/*
	free(b2);
	free(c2);

	b2 = malloc_group(1024,1);
	c2 = malloc_group(1024,0);

	printf("b3 %p\n",b2);
	printf("c3 %p\n",c2);
*/

//	scanf("%d");

	return 0;
}
