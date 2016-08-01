/*Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.*/

#include "common.h"
int SumofTwoInt(int a, int b)
{
	int r = 1;
	int sum = 0;
	int c = 0;

	while (r <= a || r <= b)
	{
		if (c)
		{
			c = 0;
			if ((a & r) && (b & r))
			{
				c = 1;
				sum |= r;
			}
			else if (((a & r) == 0) && ((b & r) == 0))
			{
				sum |= r;
			}
			else
			{
				c = 1;
			}
		}
		else
		{
			if ((a & r) && (b & r))
			{
				c = 1;
			}
			else if ((a & r) || (b & r))
			{
				sum |= r;
			}
		}
		r = r << 1;
	}
	if (c)
	{
		sum |= r;
	}
	return sum;
}

void test_371()
{
	printf("%d\n", SumofTwoInt(1, 1));
	printf("%d\n", SumofTwoInt(1, 2));
	printf("%d\n", SumofTwoInt(1, 3));
	printf("%d\n", SumofTwoInt(7, 8));
}