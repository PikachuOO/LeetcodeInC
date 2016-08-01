/*Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.*/
#include "common.h"
typedef struct _llnode
{
	struct _llnode *next;
	int val;
}llnode;

void DelNodeInLL(llnode *n)
{
	llnode *pnext = n->next;
	n->val = pnext->val;
	n->next = pnext->next;
}

void test_237()
{
	llnode n1, n2, n3, n4;
	n1.val = 1;
	n1.next = &n2;
	n2.val = 2;
	n2.next = &n3;
	n3.val = 3;
	n3.next = &n4;
	n4.val = 4;
	n4.next = 0;
	DelNodeInLL(&n3);
}