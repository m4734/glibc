#include "malloc_group.h"
void* malloc_group_f(size_t size, size_t group)
{
	return malloc_group(size,group);
}
