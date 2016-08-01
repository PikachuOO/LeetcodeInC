/*Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
	AB -> 28 */
#include "common.h"
int ReturnColNum(char *title)
{
	int res = 0;
	int len = strlen(title);

	res = (len - 1) * 26 + title[len - 1] - 'A' + 1;

	return res;
}

void test_171()
{
	printf("%d\n", ReturnColNum("A"));
	printf("%d\n", ReturnColNum("AB"));
	printf("%d\n", ReturnColNum("AAH"));
}