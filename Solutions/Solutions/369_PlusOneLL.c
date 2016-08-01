/*Given a non-negative number represented as a singly linked list of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4
*/
#include "common.h"
typedef struct _llnode
{
	struct _llnode *next;
	int val;
} llnode;

void PlusOneLL(llnode *head)
{
	int val = 0;
	llnode *p = head;
	llnode *newhead = p->next;
	llnode *newcur = newhead;
	llnode *pnext;
	p->next = 0;
	while (newcur)
	{
		pnext = newcur->next;
		newcur->next = p;
		newhead = newcur;
		newcur = pnext;
		p = newhead;
	}

	p = newhead;
	while (p)
	{
		if (p->val == 9)
		{
			p->val = 0;
			p = p->next;
		}
		else
		{
			p->val++;
			break;
		}
	}

	p = newhead;
	newhead = p->next;
	newcur = newhead;
	p->next = 0;
	while (newcur)
	{
		pnext = newcur->next;
		newcur->next = p;
		newhead = newcur;
		newcur = pnext;
		p = newhead;
	}
}

void test_369()
{
	llnode n1, n2, n3;
	n1.val = 1;
	n1.next = &n2;
	n2.val = 2;
	n2.next = &n3;
	n3.val = 3;
	n3.next = 0;
	PlusOneLL(&n1);
}