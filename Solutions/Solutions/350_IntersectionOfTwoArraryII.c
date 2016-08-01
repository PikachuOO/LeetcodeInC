/*Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?*/

#include "common.h"
#include "hash.h"

void IntersectionOfTwoArrayII(int nums1[], int size_nums1, int nums2[], int size_nums2)
{
	hash_table h;
	int i, cnt;

	hash_init(&h, size_nums1);

	for (i = 0; i < size_nums1; i++)
	{
		cnt = hash_n_get(&h, nums1[i]);
		hash_nset(&h, nums1[i], cnt+1);
	}

	for (i = 0; i < size_nums2; i++)
	{
		cnt = hash_n_get(&h, nums2[i]);
		if (cnt > 0)
		{
			printf("%d ", nums2[i]);
			hash_nset(&h, nums2[i], cnt - 1);
		}
	}
}

extern int compare(const void *a, const void *b);
void IntersectionOfTwoArrayII_II(int nums1[], int size_nums1, int nums2[], int size_nums2)
{
	int i = 0;
	int j = 0;

	qsort(nums1, size_nums1, sizeof(int), compare);
	qsort(nums2, size_nums2, sizeof(int), compare);

	while (i < size_nums1 && j < size_nums2)
	{
		if (nums1[i] == nums2[j])
		{
			printf("%d\n", nums1[i]);
			i++;
			j++;
		}
		else if (nums1[i] < nums2[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}
}

void test_350()
{
	int num1[] = { 1, 2, 2, 5, 8 };
	int num2[] = { 8, 2, 2, 1 };

	IntersectionOfTwoArrayII(num1, sizeof(num1) / sizeof(int), num2, sizeof(num2) / sizeof(int));
	IntersectionOfTwoArrayII_II(num1, sizeof(num1) / sizeof(int), num2, sizeof(num2) / sizeof(int));
}