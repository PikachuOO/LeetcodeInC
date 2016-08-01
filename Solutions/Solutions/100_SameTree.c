/*Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.*/
#include "tree.h"
#include "common.h"

int SameTree(node *t1, node *t2)
{
	int ret = 1;

	if (t1->left == 0 && t1->right == 0)
	{
		if (t2->left == 0 && t2->right == 0 && t1->v == t2->v)
		{
			ret = 1;
		}
		else
		{
			ret = 0;
		}
	}
	else
	{
		if (t1->v == t2->v)
		{
			if (t1->left)
			{
				if (t2->left == 0)
				{
					ret = 0;
				}
				else
				{
					ret = SameTree(t1->left, t2->left);
					if (ret == 0)
						return ret;
				}
			}
			if (t1->right)
			{
				if (t2->right == 0)
				{
					ret = 0;
				}
				else
				{
					ret = SameTree(t1->right, t2->right);
					if (ret == 0)
						return ret;
				}
			}
		}
		else
		{
			ret = 0;
		}
	}
	return ret;
}

void test_100()
{
	node *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8;
	node *m1, *m2, *m3, *m4, *m5, *m6, *m7, *m8;

	n1 = create_node(1);
	n2 = create_node(2);
	n3 = create_node(3);
	n4 = create_node(4);
	n5 = create_node(5);
	n6 = create_node(6);
	n7 = create_node(7);
	n8 = create_node(8);

	n6->left = n2;
	n6->right = n7;
	n7->right = n8;
	n2->left = n1;
	n2->right = n4;
	n4->left = n3;
	n3->right = n5;

	m1 = create_node(1);
	m2 = create_node(2);
	m3 = create_node(3);
	m4 = create_node(4);
	m5 = create_node(5);
	m6 = create_node(6);
	m7 = create_node(7);
	m8 = create_node(8);

	m6->left = m2;
	m6->right = m7;
	m7->right = m8;
	m2->left = m1;
	m2->right = m4;
	m4->left = m3;
	m3->right = m5;

	printf("%d", SameTree(n6, m6));
}