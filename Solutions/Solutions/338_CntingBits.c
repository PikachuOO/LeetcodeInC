/*338. Given a non negative integer number num. 
For every numbers i in the range 0 ≤ i ≤ num calculate the 
number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). 
But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? 
Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/

// 1 -> 1
// 2 -> 1
// 3 -> 2
// 4 -> 1
// 5 -> 2 (4+1) -> (1+1)
#include "common.h"
void CountingBits(int n)
{
	int i;
	int r = 2;
	int next_r = r<<1;
	int *map = malloc((n+1) * sizeof(int));
	map[1] = 1;

	if (n > 2)
	{
		printf("%d %d ", 0, 1);
	}
	else
	{
		return;
	}

	for (i = 2; i <= n; i++)
	{
		if (i == r)
		{
			printf("%d ", 1);
			map[i] = 1;
		}
		else if (i == next_r)
		{
			r = next_r;
			next_r <<= 1;
			printf("%d ", 1);
			map[i] = 1;
		}
		else
		{
			map[i] = 1 + map[i - r];
			printf("%d ", map[i]);
		}
	}

	free(map);
}

void test_338()
{
	CountingBits(15);
}