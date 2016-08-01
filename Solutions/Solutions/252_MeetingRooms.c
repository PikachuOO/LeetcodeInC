/*Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example, Given [[0, 30], [50, 90], [5, 10]], return false.*/

// case 1, one range include another range
// case 2, two ranges are mixed 
// case 3, two ranges are separated

#include "common.h"

typedef struct _btnode
{
	struct _btnode *parent;
	struct _btnode *left;
	struct _btnode *right;
	int start;
	int end;
} btnode;

static btnode *root;

btnode *BT_createnode(int start, int end)
{
	btnode *n = (btnode *)calloc(1, sizeof(btnode));
	n->start = start;
	n->end = end;
	return n;
}

btnode *BT_insert(btnode *n)
{
	btnode *p = root;
	btnode *pp = p;

	if (!root)
	{
		root = n;
		return root;
	}

	while (p)
	{
		if ((n->start >= p->start && n->end <= p->end) || (n->start > p->start && n->start < p->end))
		{
			return NULL;
		}
		pp = p;

		if (n->start < p->start)
		{
			p = p->left;
		}
		else
		{
			p = p->right;
		}
	}
	if (n->start < pp->start)
	{
		pp->left = n;
		n->parent = pp;
	}
	else
	{
		pp->right = n;
		n->parent = pp;
	}
	return root;
}


BOOL AttendAllMeeting(int time[][2], int count)
{
	int i;
	btnode *n;

	for (i = 0; i < count; i++)
	{
		n = BT_createnode(time[i][0], time[i][1]);
		if (NULL == BT_insert(n))
			return FALSE;
	}
	return TRUE;
}

extern int compare(const void *a, const void *b);
BOOL AttendAllMeetingII(int time[][2], int count)
{
	int i;
	int maxend = 0;

	qsort(time, count, 2*sizeof(int), compare);

	maxend = time[0][1];
	for (i = 1; i < count; i++)
	{
		if (time[i][0] < maxend)
			return FALSE;
		maxend = MAX(maxend, time[i][1]);
	}
	return TRUE;
}
void test_252()
{
	int time[3][2] = {
		{0, 30},
		{50, 90},
		{100, 110}
	};
	printf("%d\n", AttendAllMeetingII(time, 3));
}