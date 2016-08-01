/*Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4]
*/

#include "common.h"

int compare(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}
void WiggleSort(int *array, int size)
{
	int i, j;
	int tmp;

	if (size < 3)
		return;

	qsort(array, size, sizeof(int), compare);

	i = 2;
	while (i < size)
	{
		j = i - 1;
		tmp = array[j];
		array[j] = array[i];
		array[i] = tmp;
		i += 2;
	}
}

void test_280()
{
	int ar[] = { 3, 5, 2, 1, 6, 4, 7 };
	int size = sizeof(ar) / sizeof(int);
	int i;
	WiggleSort(ar, size);
	for (i = 0; i < size; i++)
		printf("%d ", ar[i]);
}