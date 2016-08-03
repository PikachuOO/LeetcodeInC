#include "common.h"
#include "stack.h"


stack *stack_init()
{
	stack *p = calloc(1, sizeof(stack));
	return p;
}

void stack_push(stack *s, int v)
{
	stacknode *node = (stacknode *)calloc(1, sizeof(stacknode));
	node->v = v;

	if (s->head)
	{
		s->cur->next = node;
		node->prev = s->cur;

		s->cur = s->cur->next;
	}
	else
	{
		s->head = node;
		node->prev = NULL;
		s->cur = node;
	}
	s->node_cnt++;
}

int stack_pop(stack *s)
{
	stacknode *node, *pre;
	int v;

	if (s->node_cnt)
	{
		node = s->cur;
		pre = node->prev;
		s->cur = pre;
		if (pre)
			pre->next = NULL;
		node->prev = NULL;
		v = node->v;
		free(node);
		s->node_cnt--;
		if (s->node_cnt == 0)
			s->head = NULL;
		return v;
	}
	else
		return -1;
}

int stack_peek(stack *s)
{
	stacknode *node, *pre;
	int v;

	if (s->node_cnt)
	{
		node = s->cur;
		v = node->v;
		return v;
	}
	else
		return -1;
}


int stack_isempty(stack *s)
{
	if (s->node_cnt > 0)
		return FALSE;
	else
		return TRUE;
}