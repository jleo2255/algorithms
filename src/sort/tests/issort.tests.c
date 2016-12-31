#include <criterion/criterion.h>
#include "../sort.h"

int compare_ints(const void *key1, const void *key2)
{
	int k1 = *(int*)(key1);
	int k2 = *(int*)(key2);
	
	if(k1 > k2) return 1;
	if(k1 < k2) return -1;

	return 0;
}

static int unsorted_arr[] = {5, 2, 8, 40, 22, 10, 4};

Test(insertion_sort, ascending_sort)
{
	issort(&unsorted_arr, 7, sizeof(int), &compare_ints);

	cr_assert(unsorted_arr[0] == 2, "element [0] should have value 2 but was %d", unsorted_arr[0]);
	cr_assert(unsorted_arr[1] == 4, "element [1] should have value 4 but was %d", unsorted_arr[1]);
	cr_assert(unsorted_arr[2] == 5, "element [2] should have value 5 but was %d", unsorted_arr[2]);
	cr_assert(unsorted_arr[3] == 8, "element [3] should have value 8 but was %d", unsorted_arr[3]);
	cr_assert(unsorted_arr[4] == 10, "element [4] should have value 10 but was %d", unsorted_arr[4]);
	cr_assert(unsorted_arr[5] == 22, "element [5] should have value 22 but was %d", unsorted_arr[5]);
	cr_assert(unsorted_arr[6] == 40, "element [6] should have value 40 but was %d", unsorted_arr[6]);
}

