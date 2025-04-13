
#include "../libft.h"
#include "debug_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include "../memory_utils.h"

int main(void)
{
	////**** (memset)
	printf("(FT_MEMSET:)\n");
	// basic fills
	char	buf[1000];
	char	buf_corr[1000];

	memset(buf_corr, 'A', 10);
	TEST_MEMSET("TEST1: 10 byte-fill 'A'", buf, buf_corr, 'A', 10);

	memset(buf_corr, 0x00, 10);
	TEST_MEMSET("TEST2: 10 byte-fill 0x00", buf, buf_corr, 0x00, 10);

	memset(buf_corr, 0xFF, 10);
	TEST_MEMSET("TEST3: 10 byte-fill 0xFF", buf, buf_corr, 0xFF, 10);	
	
	memset(buf_corr, 300, 10);
	TEST_MEMSET("TEST4: 10 byte-fill 300", buf, buf_corr, 300, 10);

	// size edges
	memset(buf, 'B', 10);
	memset(buf_corr, 'B', 10);
	TEST_MEMSET2("TEST5: 0 byte-fill 'A'", buf, buf_corr, 'A', 0);
	
	memset(buf, 'B', 10);
	memset(buf_corr, 'B', 10);
	TEST_MEMSET("TEST6: 1 byte-fill 'A'", buf, buf_corr, 'A', 1);
	
	// stretch test
	memset(buf, 'B', 1000);
	memset(buf_corr, 'B', 1000);
	TEST_MEMSET("TEST7: 1000 byte-fill 'A'", buf, buf_corr, 'A', 1000);

	// sentinel test
	memset(buf, 'B', 20);
	memset(buf_corr, 'B', 20);
	buf[0] = 'X';
	buf[19] = 'Y';
	buf_corr[0] = 'X';
	buf_corr[19] = 'Y';
	TEST_MEMSET("TEST8: sentinel check byte-fill 'A'", buf + 1, buf_corr + 1, 'A', 18);
	if (buf[0] == buf_corr[0])
		printf(ANS_GREEN"-[PASS]1\n"ANS_RESET);
	else
		printf(ANS_RED"-[FAIL]1\n");
	if (buf[19] == buf_corr[19])
		printf(ANS_GREEN"-[PASS]2\n"ANS_RESET);
	else
		printf(ANS_RED"-[FAIL]2\n");
}
