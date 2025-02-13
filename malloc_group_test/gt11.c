#include<stdio.h>
#include<gnu/libc-version.h>
#include <stdlib.h>
#include"malloc.h"

#define N 1024*1024*256

#define U 256

#define IT N/U

//void* aaa[N];

//void* bbb[N];

int* aaa[IT];
int main()
{
	printf("%s\n",gnu_get_libc_version());
//	void* aaa = NULL;
//	aaa = valloc(1024);
//	printf("%p\n",aaa);
//	free(aaa);
int i,j;
for(i=0;i<IT;i++)
//	aaa[i] = (int*)malloc_group(U*sizeof(int),1);
	aaa[i] = (int*)malloc(U*sizeof(int));

for (i=0;i<IT;i++)
{
for (j=0;j<U;j++)
	aaa[i][j] = 0;
}

if (fork() != 0)
{
printf("c\n");
sleep(100);
}
else
{
printf("p\n");

for (i=0;i<IT/2;i++)
{
	(int*)realloc(aaa[i],(U+10)*sizeof(int));
//for (j=0;j<U;j++)
//	aaa[i][j] = 1;
}
printf("pe\n");
sleep(100);
}

//scanf("%d");
	return 0;
}
