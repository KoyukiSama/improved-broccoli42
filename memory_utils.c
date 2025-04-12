
#include "memory_utils.h"
#include <stdint.h>

size_t	word_size(void)
{
	return (sizeof(size_t));
}

size_t	word_mask(void)
{
	return (sizeof(size_t) - 1);
}

int	is_mem_aligned(unsigned char *p)
{
	return (((uintptr_t) p & word_mask()) == 0);
}

size_t	uchar_to_word(unsigned char c)
{
	size_t	word;

	word = c;
	word |= word << 8;
	word |= word << 16;
	if (word_size() == 8)
		word |= word << 32;
	return (word);
}
