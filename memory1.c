
#include "libft.h"
#include "memory_utils.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p_char;
	size_t			*p_word;
	size_t			word;
	unsigned char	byte;

	byte = (unsigned char) c;
	p_char = (unsigned char *) s;
	while (!is_mem_aligned(p_char) && n-- > 0)
		*p_char++ = byte;
	word = uchar_to_word(byte);
	p_word = (size_t *) p_char;
	while (n >= word_size())
	{
		*p_word++ = word;
		n -= word_size();
	}
	p_char = (unsigned char *) p_word;
	while (n--)
		*p_char++ = byte;
	return (s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_char;
	const size_t		*src_word;
	unsigned char		*dst_char;
	size_t				*dst_word;

	src_char = (unsigned char *) src;
	dst_char = (unsigned char *) dest;
	while (!is_mem_aligned(dst_char) && n-- > 0)
		*dst_char++ = *src_char++;
	if (is_mem_aligned(dst_char) && is_mem_aligned(src_char))
	{
		src_word = (size_t *) src_char;
		dst_word = (size_t *) dst_char;
		while (n >= word_size())
		{
			*dst_word++ = *src_word++;
			n -= word_size();
		}
		src_char = (unsigned char *) src_word;
		dst_char = (unsigned char *) dst_word;
	}
	while (n--)
		*dst_char++ = *src_char++;
	return (dest);
}

static void	*ft_memcpy_backwards(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_char;
	const size_t		*src_word;
	unsigned char		*dst_char;
	size_t				*dst_word;

	src_char = ((unsigned char *) src) + n - 1;
	dst_char = ((unsigned char *) dest) + n - 1;
	while (!is_mem_aligned(dst_char) && n-- > 0)
		*dst_char-- = *src_char--;
	if (is_mem_aligned(dst_char) && is_mem_aligned(src_char))
	{
		src_word = (size_t *) src_char;
		dst_word = (size_t *) dst_char;
		while (n >= word_size())
		{
			*dst_word-- = *src_word--;
			n -= word_size();
		}
		src_char = (unsigned char *) src_word;
		dst_char = (unsigned char *) dst_word;
	}
	while (n--)
		*dst_char-- = *src_char--;
	return (dest);
}

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const unsigned char	*src_char;
	unsigned char		*dst_char;
	unsigned char		byte;

	src_char = (unsigned char *) src;
	dst_char = (unsigned char *) dest;
	byte = (unsigned char) c;
	while (n--)
	{
		*dst_char = *src_char;
		if (*src_char == byte)
			return ((void *) dst_char + 1);
		dst_char++;
		src_char++;
	}
	return (NULL);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_char;
	const size_t		*src_word;
	unsigned char		*dst_char;
	size_t				*dst_word;

	if (dest > src)
	{
		return (ft_memcpy_backwards(dest, src, n))
	}
	else
		return (ft_memcpy(dest, src, n));
}
