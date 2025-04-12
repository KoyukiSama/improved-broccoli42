
#include "libft.h"

static size_t	uchar_to_word(unsigned char c)
{
	size_t	word;

	word = c;
	word |= word << 8;
	word |= word << 16;
	if (WORD_SIZE == 8)
		word |= word << 32;
	return (word);
}

static unsigned char	*align_ptr(unsigned char *p, int c, size_t *n)
{
	unsigned char	byte;

	byte = (unsigned char) c;
	while (((uintptr_t) p & WORD_MASK) && *n > 0)
	{
		*p++ = byte;
		(*n)--;
	}
	return (p);
}

static unsigned char	*set_words(unsigned char *p, int c, size_t *n)
{
	size_t	word;
	size_t	*wptr;

	word = uchar_to_word((unsigned char) c);
	wptr = (size_t *) p;
	while (*n >= WORD_SIZE)
	{
		*wptr++ = word;
		*n -= WORD_SIZE;
	}
	return ((unsigned char *) wptr);
}

static unsigned char	*cleanup_block(unsigned char *p, int c, size_t *n)
{
	unsigned char	byte;

	byte = (unsigned char) c;
	while ((*n)--)
	{
		*p++ = byte;
	}
	return (p);
}

void	*memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *) s;
	p = align_ptr(p, c, &n);
	p = set_words(p, c, &n);
	cleanup_block(p, c, &n);
	return (s);
}
