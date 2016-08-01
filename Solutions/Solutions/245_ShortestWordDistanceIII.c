/*This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.

Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes", "makes"].

Given word1 = “makes”, word2 = “coding”, return 1.
Given word1 = "makes", word2 = "makes", return 3.

Note:
You may assume word1 and word2 are both in the list.
*/
#include "common.h"

int ShortestWordDistanceIII(char **ar, int size, char *w1, char *w2)
{
	int i;
	 

	if (!strcmp(w1, w2))
	{
		int distance = size;
		int cur_distance = 0;
		int find_w1 = -1;
		
		for (i = 0; i < size; i++)
		{
			if (0 == strcmp(ar[i], w1))
			{
				if (find_w1 < 0)
				{
					find_w1 = i;
				}
				else
				{
					cur_distance = i - find_w1;
					distance = MIN(distance, cur_distance);
					find_w1 = i;
				}
			}
		}
		return distance;
	}
	else
	{
		int find_w1 = -1;
		int find_w2 = -1;
		int distance = size;
		int cur_distance = 0;

		for (i = 0; i < size; i++)
		{
			if (0 == strcmp(ar[i], w1))
			{
				if (find_w2 < 0)
					find_w1 = i;
				else
				{
					cur_distance = abs(i - find_w2);
					if (cur_distance < distance)
					{
						distance = cur_distance;
						find_w1 = i;
					}
				}
			}
			else if (0 == strcmp(ar[i], w2))
			{
				if (find_w1 < 0)
					find_w2 = i;
				else
				{
					cur_distance = abs(i - find_w1);
					if (cur_distance < distance)
					{
						distance = cur_distance;
						find_w2 = i;
					}
				}
			}
		}

		return abs(find_w1 - find_w2);
	}
}

void test_245()
{
	char *ar[] = { "practice", "makes", "perfect", "coding", "makes", "makes" };
	int size = sizeof(ar) / sizeof(char*);
	printf("%d\n", ShortestWordDistanceIII(ar, size, "makes", "makes"));
}