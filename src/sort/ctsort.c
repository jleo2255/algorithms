#include <stdlib.h>
#include <string.h>

#include "issort.h" 

int ctsort(int *data, int size, int max_plus_one)
{
	int		*counts, *temp;
	int		i, j;

	// allocate data for counts and temp arrays
	if ((counts = (int*)malloc(k * sizeof(int))) == NULL) return -1;
	if ((temp = (int*)malloc(size * sizeof(int))) == NULL)
	{
		free(counts);
		return -1;
	}

	// initialize the counts array
	for (i = 0; i < max_plus_one; i++) counts[i] = 0;

	
}
