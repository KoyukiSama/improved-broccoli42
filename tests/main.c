
#include "../libft.h"
#include "debug_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// memset test cases
	char buf1[10];
	char buf_corr1[10] = {'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'};
	TEST_MEMSET("TEST1: 10 byte-fill 'A'", buf1, buf_corr1, 'A', 10);
}
