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

void InorderTraversal(node *root)
{
	node *n = root;


	do 
	{
		if (n->left)
		{
			stack_push(n);
			n = n->left;
		}
		else
		{
			printf("%d ", n->v);
			if (n->right)
			{
				n = n->right;
			}
			else
			{
				n = stack_pop();
			}
		}
	} while (TRUE == stack_isempty());
}