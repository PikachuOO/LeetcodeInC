/*Given an array of n integers where n > 1, nums, 
return an array output such that output[i] is equal to the 
product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? 
(Note: The output array does not count as extra space for the purpose of space complexity analysis.)*/

#include "common.h"
void ProductOfArrayExceptSelf(int *num, int size)
{
	int *left = malloc(size * sizeof(int));
	int *right = malloc(size * sizeof(int));
	int i;

	// scan from left -> right
	left[0] = 1;
	for (i = 1; i < size; i++)
	{
		left[i] = left[i-1] * num[i-1];
	}
	// scan from right-> left
	right[size - 1] = 1;
	for (i = size-2; i >= 0; i--)
	{
		right[i] = right[i+1] * num[i + 1];
	}

	for (i = 0; i < size; i++)
	{
		num[i] = left[i] * right[i];
	}

	free(left);
	free(right);
}

void test_238()
{
	int num[] = {1, 2, 3,4};
	int size = sizeof(num) / sizeof(num[0]);
	ProductOfArrayExceptSelf(num, size);
}
