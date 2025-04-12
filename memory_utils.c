
#include "memory_utils.h"

static int	word_size()
{
	return (sizeof(size_t));
}

static int	word_mask()
{
	return (sizeof(size_t) - 1);
}

static size_t	uchar_to_word(unsigned char c)
{
	size_t	word;

	word = c;
	word |= word << 8;
	word |= word << 16;
	if (word_size() == 8)
		word |= word << 32;
	return (word);
}