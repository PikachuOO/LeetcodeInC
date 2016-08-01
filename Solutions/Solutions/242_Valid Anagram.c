/*Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?*/
#include "common.h"
int charcompare(const void *a, const void *b)
{
	return (*(char*)a - *(char*)b);
}

int ValidAnagram(char *s, char *t)
{
	int len_s = strlen(s);
	int len_t = strlen(s);

	if (len_s != len_t)
		return 0;

	qsort(s, len_s - 1, sizeof(char), charcompare);
	qsort(t, len_s - 1, sizeof(char), charcompare);

	return strcmp(s, t);
}
int ValidAnagramII(char *s, char *t)
{
	int alph[26] = { 0 };
	int i;
	int ret = 1;

	for (i = 0; i < strlen(s); i++)
	{
		alph[s[i] - 'a']++;
	}

	for (i = 0; i < strlen(t); i++)
	{
		if (0 == alph[t[i] - 'a'])
		{
			ret = 0;
			break;
		}
		alph[t[i] - 'a'] --;
	}
	return ret;
}
void test_242()
{
	char s[] = { 'a', 'n', 'a', 'g', 'r', 'a', 'm', '\0' };
	char t[] = { 'n', 'a', 'g', 'a', 'r', 'a', 'm', '\0' };

	char s1[] = { 'r', 'a', 't', '\0' };
	char t1[] = { 'c', 'a', 'r', '\0' };

	printf("%d\n", ValidAnagramII(s, t));
	printf("%d\n", ValidAnagramII(s1, t1));
}