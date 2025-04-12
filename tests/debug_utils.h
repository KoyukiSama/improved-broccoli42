
#ifndef DEBUG_UTILS_H
# define DEBUG_UTILS_H
# include <stdlib.h>

#define TEST_MEMSET(name, buff, expected, byte, len) do {                 \
	memset(buff, byte, len);                                              \
	if (!mem_is_same(buff, expected, len))                                \
	{                                                                     \
		printf("[FAIL] %s\n", name);                                      \
		printf("Expected: "); print_hex(expected, len);                   \
		printf("Got     : "); print_hex(buff, len);                       \
	}                                                                     \
	else                                                                  \
	{                                                                     \
		printf("[PASS] %s\n", name);                                      \
	}                                                                     \
} while (0)

// (debug_utils.c)
int		mem_is_same(const void *s1, const void *s2, size_t len);
void	print_hex(const void *buf, size_t len);

#endif