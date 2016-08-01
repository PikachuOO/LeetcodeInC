/*This is a follow up of Shortest Word Distance. 
The only difference is now you are given the list 
of words and your method will be called repeatedly many times with different parameters. 
How would you optimize it?

Design a class which receives a list of words in the constructor, 
and implements a method that takes two words word1 and word2 
and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.*/

#include "hash.h"
#include "common.h"

static hash_table h1;
int ShortestWordDistanceII(char **ar, int size, char *w1, char *w2)
{
	int count_w1, count_w2;
	int *range_w1, *range_w2;

	range_w1 = hash_getrange(&h1, w1, &count_w1);
	range_w2 = hash_getrange(&h1, w2, &count_w2);

	if (count_w1 == 1 && count_w2 == 1)
	{
		return abs(*range_w1 - *range_w2);
	}
	else
	{
		//5, 10, 20
		//1, 17
		int i = 0, j = 0;
		int dis = INT_MAX;
		while (i < count_w1 && j < count_w2)
		{
			dis = MIN(dis, abs(range_w1[i] - range_w2[j]));
			if (range_w1[i] < range_w2[j])
				i++;
			else
				j++;
		}
		return dis;
	}
	
}

void ShortestWordDistanceII_init(char **ar, int size)
{
	int i;

	hash_init(&h1, 65535);
	for (i = 0; i < size; i++)
	{
		hash_set(&h1, ar[i], i + 1);
	}
}
void test_244()
{
	char *ar[] = { "practice", "makes", "perfect", "coding", "makes" };
	int size = sizeof(ar) / sizeof(char*);
	ShortestWordDistanceII_init(ar, size);
	ShortestWordDistanceII(ar, size, "makes", "coding");
}