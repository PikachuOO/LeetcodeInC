#include "common.h"

typedef struct _stacknode
{
	struct _stacknode *next;
	struct _stacknode *prev;
	void *v;
	
} stacknode;
typedef struct _stack
{
	int node_cnt;
	int node_size;
	stacknode *head;
	stacknode *cur;
} stack;

stack *stack_init(int v_size)
{
	stack *p = calloc(1, sizeof(stack));
	p->node_size = v_size;
}

void stack_push(stack *s, void *v)
{

}
