#include "common.h"

typedef struct _node
{
	struct _node *left;
	struct _node *right;
	int v;
} node;

node *gbtroot;

int CntLeaf(node *root)
{
	int count = 0;
	if (root->left == 0 && root->right == 0)
	{
		count = 1;
	}
	else
	{
		if (root->left)
		{
			count += CntLeaf(root->left);
		}
		if (root->right)
		{
			count += CntLeaf(root->left);
		}
	}
	return count;
}