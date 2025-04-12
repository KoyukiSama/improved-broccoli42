
#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdint.h>
# define ANS_RED     "\x1b[31m"
# define ANS_GREEN   "\x1b[32m"
# define ANS_RESET   "\x1b[0m"

// (memory.c)
void	*memset(void *s, int c, size_t n);

// (string.c)
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif