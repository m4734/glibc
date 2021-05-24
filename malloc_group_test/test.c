#include<stdio.h>
#include<stdlib.h>
#include<jemalloc/jemalloc.h>
int main()
{
	int *a,*b,*c,*d;
//	a = malloc(sizeof(int));
//	a = mallocx(sizeof(int),NULL);
//	a[0] = 10;


//	malloc_usable_size(a);
	a = (int*)mallocx(1024,MALLOCX_ARENA(0));
	b = (int*)mallocx(1024,MALLOCX_ARENA(1));
	c = (int*)mallocx(1024,MALLOCX_ARENA(2));
	d = (int*)mallocx(1024,MALLOCX_ARENA(3));

	printf("%p\n",a);
	printf("%p\n",b);
	printf("%p\n",c);
	printf("%p\n",d);

	free(a);
	free(b);
	free(c);
	free(d);


}
