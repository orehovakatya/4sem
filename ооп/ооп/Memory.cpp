#include "Memory.h"

void clear_memory(void* ptr)
{
	if (ptr != NULL)
		free(ptr);
}
void* alloc_memory(int n, int size_type)
{
	return calloc(n, size_type);
}