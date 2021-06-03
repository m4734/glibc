#include<stdio.h>
#include<gnu/libc-version.h>
#include <stdlib.h>
#include"malloc.h"

#define N 10000

void* aaa[N];

void* bbb[N];

int main()
{
	printf("%s\n",gnu_get_libc_version());
//	void* aaa = NULL;
//	aaa = valloc(1024);
//	printf("%p\n",aaa);
//	free(aaa);
malloc_group(1024,5);


int i,j,k;
for (k=0;k<5;k++)
{
for (i=0;i<N;i++)
{
	aaa[i] = malloc_group(1024,1);
	bbb[i] = malloc_group(1024,0);
}

for (i=0;i<10;i++)
{
	printf("%d %lld %p / %d %lld %p\n",i,(unsigned long long)aaa[i]/4096,aaa[i],i,(unsigned long long)bbb[i]/4096,bbb[i]);

}

for (i=0;i<N;i++)
{
for (j=0;j<N;j++)
{
if ((unsigned long long)aaa[i]/4096 == (unsigned long long)bbb[j]/4096)
	printf("%d %p - %d %p\n",i,aaa[i],j,bbb[j]);
}
}

for (i=0;i<N;i++)
{
	free(aaa[i]);
	free(bbb[i]);
}
}
scanf("%d");
	return 0;
}
