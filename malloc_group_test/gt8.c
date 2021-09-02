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

void* aaa[100];
int i,j,cnt;
/*
for(i=0;i<100;i++)
{
	aaa[i] = malloc_group(25,2);
	printf("%p\n",aaa[i]);
}
for (i=0;i<100;i++)
	free(aaa[i]);
*/
cnt = 0;
for (i=0;i<10;i++)
{
	for (j=1;j<=5;j++)
	{
		aaa[cnt] = malloc_group(1024,j);
		printf("%p ",aaa[cnt]);
		cnt++;
	}
printf("\n");
}
/*
for (i=0;i<cnt;i++)
{

printf("%p %d\n",aaa[i],get_size_sum(aaa[i]));
}
*/
printf("------------\n");
for (i=0;i<cnt;i++)
	printf("%d\n",get_size_sum((void*)((unsigned long)aaa[i]-(unsigned long)aaa[i]%4096)));
for (i=0;i<cnt;i++)
{
printf("%p\n",aaa[i]);
	free(aaa[i]);
}
printf("end\n");
	return 0;
}
