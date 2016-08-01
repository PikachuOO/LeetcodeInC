/*344. Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
*/

#include "common.h"
//"abcd"
char *reverseString(char *s)
{
	int len = strlen(s);
	char *pEnd, *pStart;
	char tmp;

	pEnd = &s[len - 1];
	pStart = s;

	while (pStart < pEnd)
	{
		tmp = *pStart;
		*pStart = *pEnd;
		*pEnd = tmp;
		pStart++;
		pEnd--;
	}

	printf("%s\n", s);
	return s;
}

void test_rs()
{
	char s[] = {'a','b','c','d','\0'};

	reverseString(s);
	
}