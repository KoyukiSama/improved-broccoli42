
#include "libft.h"
#include "memory_utils.h"

void	*ft_bzero(void *s, size_t n)
{
	return (ft_memset(s, '\0', n));
}
