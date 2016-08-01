typedef struct _node
{
	struct _node *left;
	struct _node *right;
	int v;
} node;

node *create_node(int v);
