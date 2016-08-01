/*Given an array of integers that is already sorted in ascending order, 
find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. 
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2*/
#include "common.h"
void TwoSumII(int *ar, int size, int target)
{
	int left, right;
	int sum;
	left = 0;
	right = size - 1;

	while (left < right)
	{
		sum = ar[left] + ar[right];
		if (target == sum)
		{
			printf("index1 = %d, index2 = %d\n", left + 1, right + 1);
			break;
		}
		else if (target > sum)
		{
			left++;
		}
		else
		{
			right--;
		}
	}
}

void test_167()
{
	int ar[] = { 2, 7, 11, 15 };
	int size = sizeof(ar) / sizeof(int);
	TwoSumII(ar, size, 18);
}