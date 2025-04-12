
#include "debug_utils.h"

int	mem_is_same(const void *s1, const void *s2, size_t len)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = s1;
	p2 = s2;
	i = 0;
	while (i < len)
	{
		if (p1[i] != p2[i])
		{
			printf("Mismatch at byte %zu: got 0x%02X, expected 0x%02X\n", i, p1[i], p2[i]);
			return (0);
		}
		i++;
	}
	return (1);	
}

void	print_hex(const void *buf, size_t len)
{
	const unsigned char *p = buf;
	for (size_t i = 0; i < len; i++)
		printf("%02X ", p[i]);
	printf("\n");
}
