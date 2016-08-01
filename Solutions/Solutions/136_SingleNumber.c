/*Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

// [2, 5, 4, 2, 4, 1, 5]
#include "common.h"
int SingleNum(int *num, int size)
{
	int i;
	int val = num[0];

	for (i = 1; i < size; i++)
	{
		val ^= num[i];
	}
	return val;
}

void test_136()
{
	int num[] = { 2, 5, 4, 2, 4, 1, 5 };
	int size = sizeof(num) / sizeof(int);
	printf("%d\n", SingleNum(num, size));
}