#include <criterion/criterion.h>
#include <time.h>
#include <stdio.h>

#include "../qksort.h"

#define KYEL  "\x1B[33m"

int qksort_compare_ints(const void *key1, const void *key2)
{
	int k1 = *(int*)(key1);
	int k2 = *(int*)(key2);
	
	if(k1 > k2) return 1;
	if(k1 < k2) return -1;

	return 0;
}

int qksort_compare_ints_desc(const void *key1, const void *key2)
{
	int k1 = *(int*)(key1);
	int k2 = *(int*)(key2);
	
	if(k1 > k2) return -1;
	if(k1 < k2) return 1;

	return 0;
}

static int unsorted_arr[] = {5, 2, 8, 40, 22, 10, 4};
static int qksort_random_unsorted_arr[2000000];

static clock_t qksort_start_times[2];
static clock_t qksort_end_times[2];

void fill_qksort_random_unsorted_arr(void)
{
	srand(time(NULL));

	for(int i = 0; i < 2000000; i++) qksort_random_unsorted_arr[i] = rand();
}

Test(quick_sort, ascending_sort)
{
	qksort(&unsorted_arr, 7, sizeof(int), 0, 6, &qksort_compare_ints);

	cr_assert(unsorted_arr[0] == 2, "element [0] should have value 2 but was %d", unsorted_arr[0]);
	cr_assert(unsorted_arr[1] == 4, "element [1] should have value 4 but was %d", unsorted_arr[1]);
	cr_assert(unsorted_arr[2] == 5, "element [2] should have value 5 but was %d", unsorted_arr[2]);
	cr_assert(unsorted_arr[3] == 8, "element [3] should have value 8 but was %d", unsorted_arr[3]);
	cr_assert(unsorted_arr[4] == 10, "element [4] should have value 10 but was %d", unsorted_arr[4]);
	cr_assert(unsorted_arr[5] == 22, "element [5] should have value 22 but was %d", unsorted_arr[5]);
	cr_assert(unsorted_arr[6] == 40, "element [6] should have value 40 but was %d", unsorted_arr[6]);
}

Test(quick_sort, descending_sort)
{
	qksort(&unsorted_arr, 7, sizeof(int), 0, 6, &qksort_compare_ints_desc);

	cr_assert(unsorted_arr[6] == 2, "element [6] should have value 2 but was %d", unsorted_arr[6]);
	cr_assert(unsorted_arr[5] == 4, "element [5] should have value 4 but was %d", unsorted_arr[5]);
	cr_assert(unsorted_arr[4] == 5, "element [4] should have value 5 but was %d", unsorted_arr[4]);
	cr_assert(unsorted_arr[3] == 8, "element [3] should have value 8 but was %d", unsorted_arr[3]);
	cr_assert(unsorted_arr[2] == 10, "element [2] should have value 10 but was %d", unsorted_arr[2]);
	cr_assert(unsorted_arr[1] == 22, "element [1] should have value 22 but was %d", unsorted_arr[1]);
	cr_assert(unsorted_arr[0] == 40, "element [0] should have value 40 but was %d", unsorted_arr[0]);
}

Test(quick_sort, big_ascending_sort, .init = fill_qksort_random_unsorted_arr )
{
	qksort_start_times[0] = clock();

	qksort(&qksort_random_unsorted_arr, 2000000, sizeof(int), 0, (2000000 - 1), &qksort_compare_ints);

	qksort_end_times[0] = clock();
	
	double elapsed_time = (qksort_end_times[0] - qksort_start_times[0])/(double)CLOCKS_PER_SEC;

	printf(KYEL "Quicksort: Sorting 2000000 ints took approximately %f seconds.\n", elapsed_time);
}
