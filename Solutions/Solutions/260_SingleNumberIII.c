/*Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?*/

#include "common.h"
void SingleNumberIII(int *num, int size)
{
	int *p = calloc(size, sizeof(int));
	int idx, i;

	for (i = 0; i < size; i++)
	{
		idx = num[i];
		if (p[idx])
			p[idx] = 0;
		else
			p[idx] = idx;
	}
	for (i = 0; i < size; i++)
	{
		if (p[i])
			printf("%d\n", p[i]);
	}
	free(p);
}
void SingleNumberIIIEx(int *num, int size)
{
	int i, j, k;
	int val = num[0];
	unsigned int r = 1;
	int *p1 = calloc(size, sizeof(int));
	int *p2 = calloc(size, sizeof(int));

	for (i = 1; i < size; i++)
	{
		val ^= num[i];
	}
	for (i = 1; i < 32; i++)
	{
		if (val & r)
			break;
		else
			r <<= 1;
	}
	j = 0;
	k = 0;
	for (i = 0; i < size; i++)
	{
		if (num[i] & r)
			p1[j++] = num[i];
		else
			p2[k++] = num[i];
	}
	val = p1[0];
	for (i = 1; i < j; i++)
	{
		val ^= p1[i];
	}
	printf("v=%d\n", val);
	val = p2[0];
	for (i = 1; i < k; i++)
	{
		val ^= p2[i];
	}
	printf("v=%d\n", val);
	free(p1);
	free(p2);
}
void test_260()
{
	int nums[] = {1, 2, 1, 3, 2,5};
	int size = sizeof(nums) / sizeof(nums[0]);

	SingleNumberIIIEx(nums, size);
}