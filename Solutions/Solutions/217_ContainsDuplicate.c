/*Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.*/
#include "common.h"
extern int compare(const void *a, const void *b);

BOOL ContainDuplicate(int ar[], int size)
{
	int count = 0;
	int i;
	int pre;

	qsort(ar, size, sizeof(int), compare);
	pre = ar[0];
	for (i = 1; i < size; i++)
	{
		if (pre == ar[i])
			return FALSE;
	}
	return TRUE;
}
