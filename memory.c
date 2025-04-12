
#include "libft.h"
#include "memory_utils.h"

static unsigned char	*align_ptr(unsigned char *p, int c, size_t *n)
{
	unsigned char	byte;

	byte = (unsigned char) c;
	while (!is_mem_aligned(p) && *n > 0)
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
	while (*n >= word_size())
	{
		*wptr++ = word;
		*n -= word_size();
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

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *) s;
	p = align_ptr(p, c, &n);
	p = set_words(p, c, &n);
	cleanup_block(p, c, &n);
	return (s);
}

void	*ft_bzero(void *s, size_t n)
{
	*ft_memset(s, '\0', n);
}
