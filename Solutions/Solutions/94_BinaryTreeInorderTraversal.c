/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
*/

#include "common.h"
#include "tree.h"
#include "stack.h"

void InorderTraversal(node *root)
{
	node *n = root;
	stack *s = stack_init();

	while (TRUE != stack_isempty(s) || n != NULL)
	{
		if (n)
		{
			stack_push(s, (int)n);
			n = n->left;
		}
		else
		{
			n = (node *)stack_pop(s);
			printf("%d ", n->v);
			n = n->right;
		}
	}

}
void InorderTraversalII(node *root)
{
	node *n = root;
	stack *s = stack_init();

	stack_push(s, (int)n);
	while (FALSE == stack_isempty(s))
	{
		n = (node *)stack_peek(s);
		if (n->left)
		{
			stack_push(s, (int)(n->left));
			n->left = NULL;
		}
		else
		{
			stack_pop(s);
			printf("%d ", n->v);
			if (n->right)
			{
				stack_push(s, (int)(n->right));
			}
		}
	}
}
void test_94()
{
	node *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8;

	n1 = create_node(1);
	n2 = create_node(2);
	n3 = create_node(3);
	n4 = create_node(4);
	n5 = create_node(5);
	n6 = create_node(6);
	n7 = create_node(7);
	n8 = create_node(8);

	n1->right = n2;
	n2->left = n3;
	InorderTraversalII(n1);

}