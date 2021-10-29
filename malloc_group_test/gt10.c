#include<stdio.h>
#include<gnu/libc-version.h>
#include <stdlib.h>
#include"malloc.h"


int main()
{
	printf("%s\n",gnu_get_libc_version());
//	void* aaa = NULL;
//	printf("%p\n",aaa);
//	free(aaa);

void* aaa[200000];
int i,base=1024;

for(i=0;i<200000;i++)
{
	aaa[i] = malloc_group(base,1);
//printf("%p ",aaa[i]);
//printf("%d\n",get_size_sum(((unsigned long)aaa[i])/4096*4096));
}

//printf("0 %p\n",aaa[0]);
//printf("%lx %d\n",((unsigned long)aaa[0])/4096*4096,get_size_sum(((unsigned long)aaa[0])/4096*4096));

//printf("%lx ",((unsigned long)aaa[0])/4096*4096+4096*16384-4096);
//printf("%d\n",get_size_sum(((unsigned long)aaa[0])/4096*4096+4096*16384-4096));

for (i=0;i<200000;i++)
	aaa[i] = realloc(aaa[i],2048);

for (i=0;i<200000;i++)
{
	if (check_group(aaa[i]) != 1)
		printf("error %d\n",i);
}	
//free(aaa[i]);

	return 0;
}
