
#ifndef MEMORY_UTILS_H
# define MEMORY_UTILS_H
# include <stdlib.h>

// (memory_utils.c)
size_t		word_size(void);
size_t		word_mask(void);
size_t		uchar_to_word(unsigned char c);
int			is_mem_aligned(unsigned char *p);
void		*ft_memmove(void *dest, const void *src, size_t n)

#endif
