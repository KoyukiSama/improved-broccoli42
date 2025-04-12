
#ifndef MEMORY_UTILS_H
# define MEMORY_UTILS_H
# include <stdlib.h>

// (memory_utils.c)
size_t		word_size();
size_t		word_mask();
size_t		uchar_to_word(unsigned char c);
int			is_mem_aligned(unsigned char *p);

#endif
