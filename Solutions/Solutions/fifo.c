#include <malloc.h>
typedef struct _fifo
{
	int head;
	int tail;
	int size;
	int *data;
} fifo;

fifo gFifo;
#define FIFO_CNT 100

void fifo_init()
{
	fifo *p = &gFifo;
	p->data = (int *)malloc(sizeof(int) * FIFO_CNT);
	p->head = 0;
	p->tail = 0;
	p->size = FIFO_CNT;
}

void fifo_push(int val)
{
	int index;
	fifo *p = &gFifo;

	// not full
	if ((p->tail - p->head) < p->size)
	{
		index = p->tail%p->size;
		p->tail++;
		p->data[index] = val;
	}
}

int fifo_cnt()
{
	fifo *p = &gFifo;
	return p->tail - p->head;
}
int fifo_pop()
{
	int index;
	fifo *p = &gFifo;

	if (fifo_cnt(p) > 0)
	{
		index = p->head % p->size;
		p->head++;
		return p->data[index];
	}
	return -1;
}