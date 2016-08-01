/*Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
Hint:

A direct way is to use the backtracking approach.
Backtracking should contains three states which are (the current number, number of steps to get that number and a bitmask which represent which number is marked as visited so far in the current number). Start with state (0,0,0) and count all valid number till we reach number of steps equals to 10n.
This problem can also be solved using a dynamic programming approach and some knowledge of combinatorics.
Let f(k) = count of numbers with unique digits with length equals k.
f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 because a number cannot start with 0].

*/
#include "common.h"
int CountForSingleDigit(int x)
{
	if (x == 1)
		return 10;
	else
	{
		int val = 9;
		
		while (x>1)
		{
			val *= (9 - x + 2);
			x--;
		}
		return val;
	}
}

int CountUniqueDigitNum(int x)
{
	int count = 0;
	int counts[12] = { 0 };
	int i;

	if (x == 1)
		return 10;

	if (x > 11)
		return 0;

	for (i = 1; i <= x; i++)
	{
		count += CountForSingleDigit(i);
		counts[i - 1] = count;
	}
	return count;
}

void test_357()
{
	printf("%d\n", CountUniqueDigitNum(1));
	printf("%d\n", CountUniqueDigitNum(2));
	printf("%d\n", CountUniqueDigitNum(3));
}
