/*Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.*/

#include "heapsort.h"
#include "hash.h"
#include "common.h"
void TopKFrequentElement(int ar[], int size, int k)
{
	int i;
	int n, key;
	int *count = calloc(size, sizeof(int));
	hash_table h1, h2;
	

	hash_init(&h1, size);

	for (i = 0; i < size; i++)
	{
		if (hash_n_contain(&h1, ar[i]) == 0)
		{
			hash_nset(&h1, ar[i], 1);
		}
		else
		{
			hash_nset(&h1, ar[i], hash_n_get(&h1, ar[i]) + 1);
		}
	}

	i = 0;
	hash_init(&h2, size);
	while (-1 != hash_n_traverse(&h1, i, &n, &key))
	{
		count[i] = key;
		hash_nset(&h2, key, n);
		i++;
	}
	size = i;

	heapsort_n(count, i, k);

	for (i = 0; i < k; i++)
		printf("%d ", hash_n_get(&h2, count[size-1-i]));
	
	free(count);
}

void test_347()
{
	int ar[] = { 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
	int size = sizeof(ar) / sizeof(int);
	TopKFrequentElement(ar, size, 2);
}