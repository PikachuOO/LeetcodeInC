/*Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
	28 -> AB */

#include "common.h"
void ReturnColTitle(int k, char *title)
{
	int length = (k-1) / 26 + 1;
	int index = (k - 1) % 26;
	int i;

	for (i = 0; i < length; i++)
	{
		if (i == length - 1)
		{
			title[i] = 'A' + index;
		}
		else
		{
			title[i] = 'A';
		}
	}
}

void test_168()
{
	char title[10] = { 0 };

	ReturnColTitle(3, title);
	printf("%s\n", title);

	ReturnColTitle(28, title);
	printf("%s\n", title);

	ReturnColTitle(60, title);
	printf("%s\n", title);
}
