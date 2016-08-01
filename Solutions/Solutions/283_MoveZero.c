/*Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.*/
#include "common.h"
void MoveZero(int nums[5], int size)
{
	int idxZero = 0;
	int idxNonZero = 0;
	int tmp;
	
	while (idxZero < size && idxNonZero < size)
	{
		if (nums[idxZero] != 0)
		{
			idxZero++;
			continue;
		}
		if (nums[idxNonZero] == 0)
		{
			idxNonZero++;
			continue;
		}

		if (idxZero > idxNonZero)
		{
			idxNonZero = idxZero + 1;
			continue;
		}
		tmp = nums[idxNonZero];
		nums[idxNonZero] = 0;
		nums[idxZero] = tmp;
	}
}

void test_283()
{
	int nums[] = { 0, 1, 0, 3, 12 };
	int size = sizeof(nums) / sizeof(nums[0]);
	MoveZero(nums, size);
}