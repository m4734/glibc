#include<stdio.h>
#include<gnu/libc-version.h>
#include <stdlib.h>
#include"malloc.h"


int main()
{
	printf("%s\n",gnu_get_libc_version());
//	void* aaa = NULL;
//	aaa = valloc(1024);
//	printf("%p\n",aaa);
//	free(aaa);

//void* aaa[100];
int i,j,cnt,base;
base = 2000;
/*
for(i=0;i<100;i++)
{
	aaa[i] = malloc_group(25,2);
	printf("%p\n",aaa[i]);
}
for (i=0;i<100;i++)
	free(aaa[i]);
*/

int* aaa = malloc_group(base,1);
	printf("gss %d %d\n",get_size_sum((void*)((unsigned long)aaa-(unsigned long)aaa%4096)),get_size_sum((void*)((unsigned long)aaa+4096-(unsigned long)aaa%4096)));

for (i=0;i<10;i++)
{
		aaa = realloc(aaa,base-i*100);
printf("%p\n",aaa);
	printf("gss %d %d\n",get_size_sum((void*)((unsigned long)aaa-(unsigned long)aaa%4096)),get_size_sum((void*)((unsigned long)aaa+4096-(unsigned long)aaa%4096)));

}
/*
for (i=0;i<cnt;i++)
{

printf("%p %d\n",aaa[i],get_size_sum(aaa[i]));
}
*/
int* bbb = aaa;
	free(bbb);
	printf("gss %d %d\n",get_size_sum((void*)((unsigned long)aaa-(unsigned long)aaa%4096)),get_size_sum((void*)((unsigned long)aaa+4096-(unsigned long)aaa%4096)));

printf("end\n");
	return 0;
}
