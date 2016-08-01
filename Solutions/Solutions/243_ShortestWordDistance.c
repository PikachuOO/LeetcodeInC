/*Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example, Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3. Given word1 = "makes", word2 = "coding", return 1.

Note: You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

The naive idea is very easy. But could you solve it in one-pass? 
*/
#include "common.h"
int abs(int a)
{
	if (a < 0)
		return (0 - a);
	else
		return a;
}

int ShortestWordDistance(char **ar, int size, char *w1, char *w2)
{
	int i;
	int find_w1 = -1;
	int find_w2 = -1;
	int distance = size;

	for (i = 0; i < size; i++)
	{
		if (0 == strcmp(ar[i], w1))
		{
			find_w1 = i;
		}
		else if (0 == strcmp(ar[i], w2))
		{
			find_w2 = i;
		}
		if (find_w1 >=0 && find_w2 >= 0)
			distance = MIN(distance, abs(find_w1 - find_w2));
	}
	return distance;
}

void test_243()
{
	char *ar[] = {"practice", "makes","perfect", "coding", "makes"};
	int size = sizeof(ar) / sizeof(char*);
	ShortestWordDistance(ar, size, "makes", "coding");
}