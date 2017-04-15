#include <criterion/criterion.h>
#include <time.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include "../bisearch.h"

#define KYEL  "\x1B[33m"

static int compare_strs(const void *str1, const void *str2)
{
	int retval;
	if((retval = strcmp((const char *)str1, (const char *)str2)) < 0) return -1;
	else if(retval > 0) return 1;
	else return 0;
}

Test(bisearch, finds_text_when_present)
{
	char *test_string = malloc(36);
	memcpy((char *)test_string + (0 * 6), "five ", 5);
	memcpy((char *)test_string + (1 * 6), "four ", 5);
	memcpy((char *)test_string + (2 * 6), "one  ", 5);
	memcpy((char *)test_string + (3 * 6), "six  ", 5);
	memcpy((char *)test_string + (4 * 6), "three", 5);
	memcpy((char *)test_string + (5 * 6), "two  ", 5);

	int has_str = bisearch(test_string, "six  ", 6, 6, compare_strs);	
	cr_assert(has_str == 3, "bisearch should find six in sorted str array");

	free(test_string);
}

Test(bisearch, does_not_find_text_when_present)
{
	char *test_string = malloc(36);
	memcpy((char *)test_string + (0 * 6), "five ", 5);
	memcpy((char *)test_string + (1 * 6), "four ", 5);
	memcpy((char *)test_string + (2 * 6), "one  ", 5);
	memcpy((char *)test_string + (3 * 6), "six  ", 5);
	memcpy((char *)test_string + (4 * 6), "three", 5);
	memcpy((char *)test_string + (5 * 6), "two  ", 5);

	int has_str = bisearch(test_string, "sixty", 6, 6, compare_strs);	
	cr_assert(has_str == -1, "bisearch should not find sixty in sorted str array");

	free(test_string);
}
