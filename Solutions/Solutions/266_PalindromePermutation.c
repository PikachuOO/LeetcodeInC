/*For example,
"code" -> False, "aba" -> True, "carerac" -> True. "deed" -> true

Hint:

Consider the palindromes of odd vs even length. What difference do you notice?
Count the frequency of each character.
If each character occurs even number of times, 
then it must be a palindrome. How about character which occurs odd number of times?
*/
#include "common.h"
int Palindrome(char *str)
{
	char *left, *right;
	int ret = 1;
	int len = strlen(str);

	left = str;
	right = str + len - 1;

	if (len % 2)
	{
		while (left != right)
		{
			if (*left != *right)
			{
				ret = 0;
				break;
			}
			left++;
			right--;
		}
	}
	else
	{
		while (left < right)
		{
			if (*left != *right)
			{
				ret = 0;
				break;
			}
			left++;
			right--;
		}
	}
	return ret;
}

void test_266()
{
	printf("%d\n", Palindrome("aba"));
	printf("%d\n", Palindrome("deed"));
	printf("%d\n", Palindrome("code"));
}