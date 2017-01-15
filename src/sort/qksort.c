#include <stdlib.h>
#include <string.h>

#include "issort.h"
#include "qksort.h"

static int compare_int(const void *int1, const void *int2)
{
	if(*(const int *)int1 > *(const int *)int2) return 1;
	if(*(const int *)int1 < *(const int *)int2) return -1;
	return 0;
}

static int partition(void *data, int esize, int i, int k, int (*compare)(const void *key1, const void *key2))
{
	char *a = data;
	void *pval, *temp;

	int r[3];

	if((pval = malloc(esize)) == NULL)
		return -1; 

	if((temp = malloc(esize)) == NULL)
	{
		free(pval);
		return -1;
	}

	r[0] = (rand() % (k - i + 1)) + i;
	r[1] = (rand() % (k - i + 1)) + i;
	r[2] = (rand() % (k - i + 1)) + i;

	issort(r, 3, sizeof(int), compare_int);
	memcpy(pval, &a[r[1] * esize], esize);
	
	i--;
	k++;

	while(1)
	{
		do
		{
			k--; // move left until an element is found in the wrong partition
		} while (compare(&a[k * esize], pval) > 0);
		
		do
		{
			i++; // move right until an element is found in the wrong partition
		} while (compare(&a[i * esize], pval) < 0);
		
		if (i >= k) break; // if the elements cross, stop
		else
		{
			// if the elements do not cross, swap them
			memcpy(temp, &a[i * esize], esize);
			memcpy(&a[i * esize], &a[k * esize], esize);
			memcpy(&a[k * esize], temp, esize);
		}
	}

	free(pval);
	free(temp);

	return k;
}

int qksort(void *data, int size, int esize, int i, int k, int (*compare)(const void *key1, const void *key2))
{
	int j;

	while(i < k)
	{
		if((j = partition(data, esize, i, k, compare)) < 0)
			return -1;

		// recursively sort the left partition
		if(qksort(data, size, esize, i, j, compare) < 0)
			return -1;

		// increment.  then recursively sort the right partition
		i = j + 1;
	}

	return 0;
}
