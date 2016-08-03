/*Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
       1
      /   \
     2    3
    / \
   4   5
return [1,2,4,5,3].

Note: Recursive solution is trivial, could you do it iteratively?*/

#include "common.h"
#include "stack.h"
#include "tree.h"

void PreorderTraversal(node *root)
{
	node *n = root;
	stack *s = stack_init();
	
	stack_push(s, (int)n);

	while (FALSE == stack_isempty(s))
	{
		n = stack_peek(s);
		printf("%d ", n->v);
		if (n->left)
		{
			stack_push(s, (int)(n->left));
			n->left = NULL;
		}
		else
		{
			while (FALSE == stack_isempty(s))
			{
				n = stack_pop(s);
				if (n->right)
					break;

			}
			if (n->right)
				stack_push(s, (int)(n->right));
		}
	}
}
void PreorderTraversalII(node *root)
{
	node *n = root;
	stack *s = stack_init();

	stack_push(s, (int)n);

	while (FALSE == stack_isempty(s))
	{
		n = stack_pop(s);
		printf("%d ", n->v);
		if (n->right)
		{
			stack_push(s, (int)(n->right));
		}
		if (n->left)
		{
			stack_push(s, (int)(n->left));
		}
	}
}
void test_114()
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

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	PreorderTraversalII(n1);

}
