/*Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?*/

int MissingNumber(int nums[], int n, int size)
{
	int sum, actual_sum = 0;
	int i;

	sum = (1 + n) * (n) / 2;
	for (i = 0; i < size; i++)
	{
		actual_sum += nums[i];
	}
	return sum - actual_sum;
}
int MissingNumberII(int nums[], int n, int size)
{
	int low, high, median;

	low = 0;
	high = n;

	while (low < high)
	{
		median = low + (high - low) / 2;
		if (nums[median] > median)
			high = median;
		else if (nums[median] < median)
			low = median;
		else
			low = median + 1;
	}
	
	
	return low;
}
void test_268()
{
	int nums[] = {1, 2, 3, 4, 5};
	int size = sizeof(nums) / sizeof(nums[0]);
	printf("%d\n", MissingNumber(nums, 5, size));
	printf("%d\n", MissingNumberII(nums, 5, size));
}