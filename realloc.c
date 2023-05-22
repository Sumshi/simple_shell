#include "main.h"
/**
 * my_realloc - realloc implementation
 * @ptr: pointer to memory location
 * @size: represents old-size
 * @newsize: represents the new-size.
 * Return: on success, newly allocated memory
 */
void *my_realloc(void *ptr, unsigned int size, unsigned int newsize)
{
	void *memory;
	char *ptr_cpy;
	char *fill;
	unsigned int idx;

	if (newsize == size)
	{
		return (ptr);
	}
	if (ptr == NULL)
	{
		memory = malloc(newsize);
		if (memory == NULL)
		{
			return (NULL);
		}
		return (memory);
	}
	if (newsize == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	ptr_cpy = ptr;
	memory = malloc(newsize);
	if (memory == NULL)
	{
		free(ptr);
		return (NULL);
	}

	fill = memory;
	idx = 0;
	while (idx < size && idx < newsize)
	{
		fill[idx] = *ptr_cpy++;
		idx++;
	}
	free(ptr);
	return (memory);
}
