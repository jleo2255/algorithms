#include <criterion/criterion.h>
#include <time.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

#include "../rxsort.h"

#define KYEL  "\x1B[33m"

static int rxsort_unsorted_arr[] = {5, 2, 8, 40, 22, 10, 4};
static int rxsort_random_unsorted_arr[1500000];

static clock_t rxsort_start_times[2];
static clock_t rxsort_end_times[2];

void fill_rxsort_random_unsorted_arr(void)
{
	srand(time(NULL));

	for(int i = 0; i < 1500000; i++) rxsort_random_unsorted_arr[i] = (rand() % ((int)pow(2, 29)));
	rxsort_random_unsorted_arr[1499999] = (int)pow(2, 29);
}

Test(radix_sort, ascending_sort)
{
	rxsort(rxsort_unsorted_arr, 7, 2, 10);

	cr_assert(rxsort_unsorted_arr[0] == 2, "element [0] should have value 2 but was %d", rxsort_unsorted_arr[0]);
	cr_assert(rxsort_unsorted_arr[1] == 4, "element [1] should have value 4 but was %d", rxsort_unsorted_arr[1]);
	cr_assert(rxsort_unsorted_arr[2] == 5, "element [2] should have value 5 but was %d", rxsort_unsorted_arr[2]);
	cr_assert(rxsort_unsorted_arr[3] == 8, "element [3] should have value 8 but was %d", rxsort_unsorted_arr[3]);
	cr_assert(rxsort_unsorted_arr[4] == 10, "element [4] should have value 10 but was %d", rxsort_unsorted_arr[4]);
	cr_assert(rxsort_unsorted_arr[5] == 22, "element [5] should have value 22 but was %d", rxsort_unsorted_arr[5]);
	cr_assert(rxsort_unsorted_arr[6] == 40, "element [6] should have value 40 but was %d", rxsort_unsorted_arr[6]);
}

Test(radix_sort, big_ascending_sort, .init = fill_rxsort_random_unsorted_arr )
{
	rxsort_start_times[0] = clock();

	rxsort(rxsort_random_unsorted_arr, 1500000, 9, 10); 

	rxsort_end_times[0] = clock();
	
	double elapsed_time = (rxsort_end_times[0] - rxsort_start_times[0])/(double)CLOCKS_PER_SEC;

	printf(KYEL "Radixsort: Sorting 1500000 ints took approximately %f seconds.\n", elapsed_time);
}


