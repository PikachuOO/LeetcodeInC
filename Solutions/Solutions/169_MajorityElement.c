/*Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.*/
#include "hash.h"
#include "common.h"
int MajorityElement(int ar[], int size)
{
	hash_table h;
	int i, n;
	int max = 0;
	int maxi = 0;

	hash_init(&h, size);

	for (i = 0; i < size; i++)
	{
		n = hash_n_get(&h, ar[i]);
		hash_nset(&h, ar[i], n + 1);
		max = MAX(max, n + 1);
		if (max == n + 1)
			maxi = i;
	}
	return ar[maxi];
}

extern int compare(const void *a, const void *b);
int MajorityElementII(int ar[], int size)
{
	if (size == 1)
		return ar[0];

	qsort(ar, size, sizeof(int), compare);
	return ar[size / 2];
}

int MajorityElementIII(int ar[], int size)
{
	int i;
	int result;
	int count = 0;

	for (i = 0; i < size; i++)
	{
		if (count == 0)
		{
			result = ar[i];
			count++;
			continue;
		}
		if (result == ar[i])
			count++;
		else
			count--;
	}
	return result;
}
void test_169()
{
	int ar[] = {1, 2, 3, 2, 1, 2, 2};
	int size = sizeof(ar) / sizeof(ar[0]);

	printf("%d\n", MajorityElement(ar, size));
//	printf("%d\n", MajorityElementII(ar, size));
	printf("%d\n", MajorityElementIII(ar, size));
}