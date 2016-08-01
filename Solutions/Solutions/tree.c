#include <malloc.h>
#include "tree.h"


node *create_node(int v)
{
	node *n = (node *)calloc(1, sizeof(node));
	n->v = v;
	return n;
}
