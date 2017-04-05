#include <criterion/criterion.h>
#include <time.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

#include "../ctsort.h"

#define KYEL  "\x1B[33m"

static int max_array(int a[], int num_elements)
{
   int i, max=-32000;
   for (i=0; i<num_elements; i++)
   {
	 if (a[i]>max)
	 {
	    max=a[i];
	 }
   }
   return(max);
}

static int ctsort_unsorted_arr[] = {5, 2, 8, 40, 22, 10, 4};
static int ctsort_random_unsorted_arr[1500000];

static clock_t ctsort_start_times[2];
static clock_t ctsort_end_times[2];

void fill_ctsort_random_unsorted_arr(void)
{
	srand(time(NULL));

	for(int i = 0; i < 1500000; i++) ctsort_random_unsorted_arr[i] = (rand() % ((int)pow(2, 27)));
}

Test(counting_sort, ascending_sort)
{
	ctsort(ctsort_unsorted_arr, 7, 41);

	cr_assert(ctsort_unsorted_arr[0] == 2, "element [0] should have value 2 but was %d", ctsort_unsorted_arr[0]);
	cr_assert(ctsort_unsorted_arr[1] == 4, "element [1] should have value 4 but was %d", ctsort_unsorted_arr[1]);
	cr_assert(ctsort_unsorted_arr[2] == 5, "element [2] should have value 5 but was %d", ctsort_unsorted_arr[2]);
	cr_assert(ctsort_unsorted_arr[3] == 8, "element [3] should have value 8 but was %d", ctsort_unsorted_arr[3]);
	cr_assert(ctsort_unsorted_arr[4] == 10, "element [4] should have value 10 but was %d", ctsort_unsorted_arr[4]);
	cr_assert(ctsort_unsorted_arr[5] == 22, "element [5] should have value 22 but was %d", ctsort_unsorted_arr[5]);
	cr_assert(ctsort_unsorted_arr[6] == 40, "element [6] should have value 40 but was %d", ctsort_unsorted_arr[6]);
}

Test(counting_sort, big_ascending_sort, .init = fill_ctsort_random_unsorted_arr )
{
	int max_plus_one = max_array(ctsort_random_unsorted_arr, 1500000) + 1;

	ctsort_start_times[0] = clock();

	ctsort(ctsort_random_unsorted_arr, 1500000, max_plus_one); 

	ctsort_end_times[0] = clock();
	
	double elapsed_time = (ctsort_end_times[0] - ctsort_start_times[0])/(double)CLOCKS_PER_SEC;

	printf(KYEL "Countingsort: Sorting 1500000 ints took approximately %f seconds.\n", elapsed_time);
}


