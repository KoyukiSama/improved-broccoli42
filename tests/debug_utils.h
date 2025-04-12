
#ifndef DEBUG_UTILS_H
# define DEBUG_UTILS_H
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

#define TEST_MEMSET(name, buff, expected, byte, len) do {                 \
	ft_memset(buff, byte, len);                                           \
	memset(expected, byte, len);                                          \
	if (!mem_is_same(buff, expected, len))                                \
	{                                                                     \
		printf(ANS_RED"[FAIL] %s\n"ANS_RESET, name);                      \
		printf("Expected: "); print_hex(expected, len);                   \
		printf("Got     : "); print_hex(buff, len);                       \
	}                                                                     \
	else                                                                  \
	{                                                                     \
		printf(ANS_GREEN"[PASS] %s\n"ANS_RESET, name);                                      \
	}                                                                     \
} while (0)

#define TEST_MEMSET2(name, buff, expected, byte, len) do {                \
	ft_memset(buff, byte, len);                                           \
	if (!mem_is_same(buff, expected, len))                                \
	{                                                                     \
		printf(ANS_RED"[FAIL] %s\n"ANS_RESET, name);                      \
		printf("Expected: "); print_hex(expected, len);                   \
		printf("Got     : "); print_hex(buff, len);                       \
	}                                                                     \
	else                                                                  \
	{                                                                     \
		printf(ANS_GREEN"[PASS] %s\n"ANS_RESET, name);                    \
	}                                                                     \
} while (0)

// (debug_utils.c)
int		mem_is_same(const void *s1, const void *s2, size_t len);
void	print_hex(const void *buf, size_t len);

#endif