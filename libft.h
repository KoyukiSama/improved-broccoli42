
#include <stdlib.h>
#include <stdint.h>

#define WORD_SIZE sizeof(size_t)
#define WORD_MASK (WORD_SIZE - 1)

// (memory.c)
void	*memset(void *s, int c, size_t n);

// (string.c)
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);