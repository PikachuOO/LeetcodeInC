/*Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
 9   6 3   1
 */
#include "tree.h"
#include "common.h"
void InvertBinaryTree(node *root)
{
	node *tmp;

	if (root->left && root->right)
	{
		InvertBinaryTree(root->left);
		InvertBinaryTree(root->right);
		tmp = root->left;
		root->left = root->right;
		root->right = tmp;
	}
	else if (root->left && root->right == 0)
	{
		InvertBinaryTree(root->left);
		root->right = root->left;
		root->left = 0;
	}
	else if (root->right && root->left == 0)
	{
		InvertBinaryTree(root->right);
		root->left = root->right;
		root->right = 0;
	}
}

void test_226()
{
	node *n1, *n2, *n3, *n4, *n6, *n7, *n9;
	n1 = create_node(1);
	n2 = create_node(2);
	n3 = create_node(3);
	n4 = create_node(4);
	n6 = create_node(6);
	n7 = create_node(7);
	n9 = create_node(9);

	n4->left = n2;
	n4->right = n7;
	n2->left = n1;
	n2->right = n3;
	n7->left = n6;
	n7->right = n9;

	InvertBinaryTree(n4);
}