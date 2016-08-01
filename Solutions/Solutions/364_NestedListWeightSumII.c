/*Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Different from the previous question where weight is increasing from root to leaf, now the weight is defined from bottom up. i.e., the leaf level integers have weight 1, and the root level integers have the largest weight.

Example 1:
Given the list [[1,1],2,[1,1]], return 8. (four 1's at depth 1, one 2 at depth 2)

Example 2:
Given the list [1,[4,[6]]], return 17. (one 1 at depth 3, one 4 at depth 2, and one 6 at depth 1; 1*3 + 4*2 + 6*1 = 17) */
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

int NLGetLevel(nlnode *head, int level)
{
	nlnode *p = head;
	int retLevel = level;

	while (p)
	{
		if (p->nextL == 0)
		{
			p = p->next;
		}
		else
		{
			retLevel = MAX(retLevel, NLGetLevel(p->nextL, level + 1));
			p = p->next;
		}
	}
	return retLevel;
}

int NLGetLevelSumII(nlnode *head, int toplevel)
{
	nlnode *p = head;
	int level_sum = 0;
	int nextlevel_sum = 0;

	while (p)
	{
		if (p->nextL == 0)
		{
			level_sum += p->v * toplevel;
		}
		else
		{
			nextlevel_sum = NLGetLevelSumII(p->nextL, toplevel - 1);
			level_sum += nextlevel_sum;
		}
		p = p->next;
	}

	return level_sum;
}

void test_364()
{
	int toplevel = 0;
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

	toplevel = NLGetLevel(gnlhead, 1);
	printf("%d\n", toplevel);
	printf("%d\n", NLGetLevelSumII(gnlhead, toplevel));
}