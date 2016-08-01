/*Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.*/

#include "common.h"

extern int compare(const void *a, const void *b);

void IntersectionOfTwoArray(int *num1, int size1, int *num2, int size2)
{
	int i = 0;
	int j = 0;
	int find = 0;

	qsort(num1, size1, sizeof(int), compare);
	qsort(num2, size2, sizeof(int), compare);

	while (i < size1 && j < size2)
	{
		if (num1[i] == num2[j])
		{
			if (find == 0 || find != num1[i])
				printf("%d\n", num1[i]);
			find = num1[i];
			i++;
			j++;
		}
		else if (num1[i] < num2[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}

}

void test_349()
{
	int num1[] = { 1, 2, 5, 8 };
	int num2[] = { 8, 2, 1 };
	IntersectionOfTwoArray(num1, sizeof(num1) / sizeof(int), num2, sizeof(num2) / sizeof(int));
}