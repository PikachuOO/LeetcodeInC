/*Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.*/

#include "tree.h"
#include "common.h"

int MaxDepth(node *root)
{
	int max = 0;
	int ldepth = 1;
	int rdepth = 1;

	if (root->left == 0 && root->right == 0)
		return 1;
	
	if (root->left)
		ldepth += MaxDepth(root->left);
	if (root->right)
		rdepth += MaxDepth(root->right);
	
	max = (ldepth > rdepth) ? ldepth : rdepth;

	return max;
}


/*
          6
	  2        7
	  |              8
   |     |       
   1     4
         |
     3
	 |
	      5
*/
void test_104()
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

	n6->left = n2;
	n6->right = n7;
	n7->right = n8;
	n2->left = n1;
	n2->right = n4;
	n4->left = n3;
	n3->right = n5;

	printf("max depth= %d\n", MaxDepth(n6));
}