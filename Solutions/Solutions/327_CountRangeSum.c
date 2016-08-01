/*Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.*/
#include "common.h"
int CountRangeSum(int *ar, int size, int lower, int upper)
{
	int *sum = calloc(size, sizeof(int));
	int i, j, tmp, k = 0;
	int cnt = 0;

	for (i = 0; i < size - 1; i++)
	{
		tmp = ar[i];
		for (j = i+1; j < size; j++)
		{
			sum[k++] = tmp + ar[j];
			tmp = tmp + ar[j];
		}
	}
	for (i = 0; i < size; i++)
	{
		if (ar[i] >= lower && ar[i] <= upper)
		{
			cnt++;
		}
	}
	for (i = 0; i < k; i++)
	{
		if (sum[i] >= lower && sum[i] <= upper)
		{
			cnt++;
		}
	}
	return cnt;
}

void CountRangeSumII(int *ar, int size, int lower, int upper)
{
	int *sum = calloc(size+1, sizeof(int));
	int i, k = 0;
	int cnt = 0;

	for (i = 0; i < size; i++)
	{
		sum[i + 1] = sum[i] + ar[i];
		printf("%d ", sum[i + 1]);
	}
}
void test_327()
{
	int ar[] = {-2,5,-1};
	int size = sizeof(ar) / sizeof(ar[0]);
	int lower = -2;
	int upper = 2;
	CountRangeSumII(ar, size, lower, upper);
}