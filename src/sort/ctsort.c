#include <stdlib.h>
#include <string.h>

int ctsort(int *data, int size, int max_plus_one)
{
	int		*counts, *temp;
	int		i, j;

	// allocate data for counts and temp arrays
	if ((counts = (int*)malloc(max_plus_one * sizeof(int))) == NULL) return -1;
	if ((temp = (int*)malloc(size * sizeof(int))) == NULL)
	{
		free(counts);
		return -1;
	}

	// initialize the counts array 
	for (i = 0; i < max_plus_one; i++) counts[i] = 0;

	// fill the index array with counts
	for (j = 0; j < size; j++) counts[data[j]] = counts[data[j]] + 1;

	// adjust the counts to be an array of offsets
	for (i = 1; i < max_plus_one; i++) counts[i] = counts[i - 1] + counts[i];

	for (j = size - 1; j >= 0; j--)
	{
		temp[counts[data[j]] - 1] = data[j];
		counts[data[j]] = counts[data[j]] - 1;
	}

	memcpy(data, temp, size * sizeof(int));

	free(counts);
	free(temp);
		
	return 0;
}
