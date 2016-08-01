/*Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)

Example 2:
Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27)
*/
#include "common.h"
typedef struct _nlnode
{
	struct _nlnode *nextL;
	struct _nlnode *next;
	int v;
}nlnode;

static nlnode *gnlhead;

static nlnode *nlnode_create(int v)
{
	nlnode *n = calloc(1, sizeof(nlnode));
	n->v = v;
	return n;
}


//Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)
int NLGetLevelSum(nlnode *head, int level)
{
	nlnode *p = head;
	int level_sum = 0;
	int nextlevel_sum = 0;

	while (p)
	{
		if (p->nextL == 0)
		{
			level_sum += p->v;
		}
		else
		{
			nextlevel_sum = NLGetLevelSum(p->nextL, level + 1);
			level_sum += nextlevel_sum;
		}
		p = p->next;
	}
	
	return level_sum * level;
}
void test_339()
{
	// [[1,2],3,[4,5]]
	nlnode *n1 = nlnode_create(0);
	nlnode *n11 = nlnode_create(1);
	nlnode *n12 = nlnode_create(1);
	nlnode *n2 = nlnode_create(2);
	nlnode *n3 = nlnode_create(0);
	nlnode *n31 = nlnode_create(1);
	nlnode *n32 = nlnode_create(1);

	gnlhead = n1;
	n1->next = n2;
	n2->next = n3;

	n1->nextL = n11;
	n11->next = n12;

	n3->nextL = n31;
	n31->next = n32;

	printf("%d\n", NLGetLevelSum(gnlhead, 1));
}


