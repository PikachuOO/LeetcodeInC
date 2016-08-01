/*Problem Description:

You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, 
you and your friend take turns to flip two consecutive "++" into "--". 
The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity.*/

#include "common.h"

int FlipGameII(char *s)
{
	int i;
	int ret;
	int len = strlen(s);

	if (s == NULL || len < 2)
		return FALSE;

	for (i = 0; i < len-1; i++)
	{
		if (s[i] == '+' && s[i + 1] == '+')
		{
			s[i] = '-';
			s[i + 1] = '-';
			ret = FlipGameII(s);
			s[i] = '+';
			s[i + 1] = '+';
			if (ret == FALSE)
				return TRUE;
		}		
	}
	return FALSE;
}

void test_294()
{
	char s[] = { '+', '+', '+', '+' , '\0'};
	printf("%d\n", FlipGameII(s));
}