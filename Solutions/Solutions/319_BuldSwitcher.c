/*There are n bulbs that are initially off. 
You first turn on all the bulbs. 
Then, you turn off every second bulb. 
On the third round, you toggle every third bulb 
(turning on if it's off or turning off if it's on). 
For the ith round, 
you toggle every i bulb. 
For the nth round, you only toggle the last bulb. 
Find how many bulbs are on after n rounds.

Example:

Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.*/
#include "common.h"
int BulbSwitch(int n)
{
	int *cnt = (int *)calloc(n, sizeof(int));
	int half = n / 2;
	int i, j;
	int total = 1;

	for (i = n; i > half; i--)
	{
		for (j = 2; j <= half; j++)
		{
			if (i % j == 0)
			{
				cnt[i - 1]++;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (cnt[i] > 0 && cnt[i] % 2 == 1)
			total++;
	}
	free(cnt);
	return total;
}

int BulbSwitchII(int n)
{
	int i = 1;
	while (i * i <= n)
	{
		i++;
	}
	return i-1;
}

void test_319()
{
	printf("%d\n", BulbSwitch(3));
	printf("%d\n", BulbSwitch(5));
}