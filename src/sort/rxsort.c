#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int rxsort(int *data, int size, int p_count, int radix)
{
	int *counts, *temp;

	int index, pval, i, j, n;

	if ((counts = (int*)malloc(radix * sizeof(int))) == NULL) return -1;
	if ((temp = (int*)malloc(size * sizeof(int))) == NULL) return -1;

	for (n = 0; n < p_count; n++)
	{
		for (i = 0; i < radix; i++) counts[i] = 0;

		pval = pow((double)radix, (double)n);

		for (j = 0; j < size; j++)
		{
			index = (int)(data[j] / pval) % radix;
			counts[index] = counts[index] + 1;
		}
	
		for (i = 0; i < radix; i++) counts[i] = counts[i] + counts[i - 1]; 

		for (j = size - 1; j >= 0; j--)
		{
			index = (int)(data[j] / pval) % radix;
			temp[counts[index] - 1] = data[j];
			counts[index] = counts[index] - 1;
		}

		memcpy(data, temp, size * sizeof(int));
	}

	free(counts);
	free(temp);

	return 0;
	
}
