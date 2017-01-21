#include <criterion/criterion.h>
#include <time.h>
#include <stdio.h>

#include "../issort.h"

#define KYEL  "\x1B[33m"

int issort_compare_ints(const void *key1, const void *key2)
{
	int k1 = *(int*)(key1);
	int k2 = *(int*)(key2);
	
	if(k1 > k2) return 1;
	if(k1 < k2) return -1;

	return 0;
}

int issort_compare_ints_desc(const void *key1, const void *key2)
{
	int k1 = *(int*)(key1);
	int k2 = *(int*)(key2);
	
	if(k1 > k2) return -1;
	if(k1 < k2) return 1;

	return 0;
}

static int issort_unsorted_arr[] = {5, 2, 8, 40, 22, 10, 4};
static int issort_random_issort_unsorted_arr[20000];

static clock_t issort_start_times[2];
static clock_t issort_end_times[2];

void fill_issort_random_issort_unsorted_arr(void)
{
	srand(time(NULL));

	for(int i = 0; i < 20000; i++) issort_random_issort_unsorted_arr[i] = rand();
}

Test(insertion_sort, ascending_sort)
{
	issort(&issort_unsorted_arr, 7, sizeof(int), &issort_compare_ints);

	cr_assert(issort_unsorted_arr[0] == 2, "element [0] should have value 2 but was %d", issort_unsorted_arr[0]);
	cr_assert(issort_unsorted_arr[1] == 4, "element [1] should have value 4 but was %d", issort_unsorted_arr[1]);
	cr_assert(issort_unsorted_arr[2] == 5, "element [2] should have value 5 but was %d", issort_unsorted_arr[2]);
	cr_assert(issort_unsorted_arr[3] == 8, "element [3] should have value 8 but was %d", issort_unsorted_arr[3]);
	cr_assert(issort_unsorted_arr[4] == 10, "element [4] should have value 10 but was %d", issort_unsorted_arr[4]);
	cr_assert(issort_unsorted_arr[5] == 22, "element [5] should have value 22 but was %d", issort_unsorted_arr[5]);
	cr_assert(issort_unsorted_arr[6] == 40, "element [6] should have value 40 but was %d", issort_unsorted_arr[6]);
}

Test(insertion_sort, descending_sort)
{
	issort(&issort_unsorted_arr, 7, sizeof(int), &issort_compare_ints_desc);

	cr_assert(issort_unsorted_arr[6] == 2, "element [6] should have value 2 but was %d", issort_unsorted_arr[6]);
	cr_assert(issort_unsorted_arr[5] == 4, "element [5] should have value 4 but was %d", issort_unsorted_arr[5]);
	cr_assert(issort_unsorted_arr[4] == 5, "element [4] should have value 5 but was %d", issort_unsorted_arr[4]);
	cr_assert(issort_unsorted_arr[3] == 8, "element [3] should have value 8 but was %d", issort_unsorted_arr[3]);
	cr_assert(issort_unsorted_arr[2] == 10, "element [2] should have value 10 but was %d", issort_unsorted_arr[2]);
	cr_assert(issort_unsorted_arr[1] == 22, "element [1] should have value 22 but was %d", issort_unsorted_arr[1]);
	cr_assert(issort_unsorted_arr[0] == 40, "element [0] should have value 40 but was %d", issort_unsorted_arr[0]);
}

Test(insertion_sort, big_ascending_sort, .init = fill_issort_random_issort_unsorted_arr )
{
	issort_start_times[0] = clock();

	issort(&issort_random_issort_unsorted_arr, 20000, sizeof(int), &issort_compare_ints);

	issort_end_times[0] = clock();
	
	double elapsed_time = (issort_end_times[0] - issort_start_times[0])/(double)CLOCKS_PER_SEC;

	printf(KYEL "Insertion sort: Sorting 20000 ints took approximately %f seconds.\n", elapsed_time);
}
