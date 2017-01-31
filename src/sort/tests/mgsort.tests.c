#include <criterion/criterion.h>
#include <time.h>
#include <stdio.h>

#include "../mgsort.h"

#define KYEL  "\x1B[33m"

int mgsort_compare_ints(const void *key1, const void *key2)
{
	int k1 = *(int*)(key1);
	int k2 = *(int*)(key2);
	
	if(k1 > k2) return 1;
	if(k1 < k2) return -1;

	return 0;
}

int mgsort_compare_ints_desc(const void *key1, const void *key2)
{
	int k1 = *(int*)(key1);
	int k2 = *(int*)(key2);
	
	if(k1 > k2) return -1;
	if(k1 < k2) return 1;

	return 0;
}

static int mgsort_unsorted_arr[] = {5, 2, 8, 40, 22, 10, 4};
static int mgsort_random_unsorted_arr[1000000];

static clock_t mgsort_start_times[2];
static clock_t mgsort_end_times[2];

void fill_mgsort_random_unsorted_arr(void)
{
	srand(time(NULL));

	for(int i = 0; i < 1000000; i++) mgsort_random_unsorted_arr[i] = rand();
}

Test(merge_sort, ascending_sort)
{
	mgsort(&mgsort_unsorted_arr, 7, sizeof(int), 0, 6, &mgsort_compare_ints);

	cr_assert(mgsort_unsorted_arr[0] == 2, "element [0] should have value 2 but was %d", mgsort_unsorted_arr[0]);
	cr_assert(mgsort_unsorted_arr[1] == 4, "element [1] should have value 4 but was %d", mgsort_unsorted_arr[1]);
	cr_assert(mgsort_unsorted_arr[2] == 5, "element [2] should have value 5 but was %d", mgsort_unsorted_arr[2]);
	cr_assert(mgsort_unsorted_arr[3] == 8, "element [3] should have value 8 but was %d", mgsort_unsorted_arr[3]);
	cr_assert(mgsort_unsorted_arr[4] == 10, "element [4] should have value 10 but was %d", mgsort_unsorted_arr[4]);
	cr_assert(mgsort_unsorted_arr[5] == 22, "element [5] should have value 22 but was %d", mgsort_unsorted_arr[5]);
	cr_assert(mgsort_unsorted_arr[6] == 40, "element [6] should have value 40 but was %d", mgsort_unsorted_arr[6]);
}

Test(merge_sort, descending_sort)
{
	mgsort(&mgsort_unsorted_arr, 7, sizeof(int), 0, 6, &mgsort_compare_ints_desc);

	cr_assert(mgsort_unsorted_arr[6] == 2, "element [6] should have value 2 but was %d", mgsort_unsorted_arr[6]);
	cr_assert(mgsort_unsorted_arr[5] == 4, "element [5] should have value 4 but was %d", mgsort_unsorted_arr[5]);
	cr_assert(mgsort_unsorted_arr[4] == 5, "element [4] should have value 5 but was %d", mgsort_unsorted_arr[4]);
	cr_assert(mgsort_unsorted_arr[3] == 8, "element [3] should have value 8 but was %d", mgsort_unsorted_arr[3]);
	cr_assert(mgsort_unsorted_arr[2] == 10, "element [2] should have value 10 but was %d", mgsort_unsorted_arr[2]);
	cr_assert(mgsort_unsorted_arr[1] == 22, "element [1] should have value 22 but was %d", mgsort_unsorted_arr[1]);
	cr_assert(mgsort_unsorted_arr[0] == 40, "element [0] should have value 40 but was %d", mgsort_unsorted_arr[0]);
}

Test(merge_sort, big_ascending_sort, .init = fill_mgsort_random_unsorted_arr )
{
	mgsort_start_times[0] = clock();

	mgsort(&mgsort_random_unsorted_arr, 1000000, sizeof(int), 0, (1000000 - 1), &mgsort_compare_ints);

	mgsort_end_times[0] = clock();
	
	double elapsed_time = (mgsort_end_times[0] - mgsort_start_times[0])/(double)CLOCKS_PER_SEC;

	printf(KYEL "Mergesort: Sorting 1000000 ints took approximately %f seconds.\n", elapsed_time);
}
