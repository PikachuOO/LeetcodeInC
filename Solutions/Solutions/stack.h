#ifndef __STACK_H__
#define __STACK_H__

typedef struct _stacknode
{
	struct _stacknode *next;
	struct _stacknode *prev;
	int v;

} stacknode;
typedef struct _stack
{
	int node_cnt;
	stacknode *head;
	stacknode *cur;
} stack;

stack *stack_init();
void stack_push(stack *s, int v);
int stack_pop(stack *s);
int stack_peek(stack *s);
int stack_isempty(stack *s);
#endif

