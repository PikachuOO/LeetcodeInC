/*Design a hit counter which counts the number of hits received in the past 5 minutes.

Each function accepts a timestamp parameter (in seconds granularity) 
and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). 
You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

Example:
HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301); 
Follow up:
What if the number of hits per second could be very large? Does your design scale?
*/
#include "common.h"
typedef struct _hitnode
{
	int timestamp;
	struct _hitnode *next;
} hitnode_t;

typedef struct _hittable
{
	hitnode_t *head;
	hitnode_t *cur;
	int count;
} hittable_t;

hittable_t hittable;

hitnode_t *hitnode_creat()
{
	return (hitnode_t *)calloc(1, sizeof(hitnode_t));
}
void HitCounter_hit(int timestamp)
{
	// if timestamp - 1st timestamp in Q < 300
	// insert LL for this timestamp 
	// count in Q ++
	// else 
	// delete node from head
	// count --;
	if (hittable.count)
	{
		int head_time = hittable.head->timestamp;
		if (timestamp - head_time < 300)
		{
			hitnode_t *n = hitnode_creat();
			n->timestamp = timestamp;
			hittable.cur->next = n;
			hittable.cur = hittable.cur->next;
			hittable.count++;
		}
		else
		{
			hitnode_t *n;
			n = hittable.head;
			hittable.head = n->next;
			free(n);
			n = hitnode_creat();
			n->timestamp = timestamp;
			hittable.cur->next = n;
			hittable.cur = hittable.cur->next;
		}
	}
	else
	{
		hitnode_t *n = hitnode_creat();
		n->timestamp = timestamp;
		hittable.head = n;
		hittable.cur = hittable.head;
		hittable.count++;
	}
}

int HitCounter_gethit(int timestamp)
{
	// if timestamp - 1st timestamp in Q < 300
	// insert LL for this timestamp 
	// count in Q ++
	// else 
	// delete node from head
	// count --;
	//return count

	if (hittable.count)
	{
		int head_time = hittable.head->timestamp;
		if (timestamp - head_time < 300)
		{
			return hittable.count;
		}
		else
		{
			hitnode_t *n;

			n = hittable.head;

			while (timestamp - n->timestamp >= 300)
			{
				hittable.head = n->next;
				free(n);
				n = hittable.head;
				hittable.count--;
			}

			return hittable.count;
		}
	}
	else
	{
		return 0;
	}
}

int time[300] = {0};
int hit[300] = {0};
void HitCounter_hitII(int timestamp)
{
	int idx = timestamp % 300;
	if (time[idx] == timestamp)
	{
		hit[idx]++;
	}
	else
	{
		time[idx] = timestamp;
		hit[idx] = 1;
	}
}

int HitCounter_gethitII(int timestamp)
{
	int i;
	int total = 0;
	for (i = 0; i < 300; i++)
	{
		if (time[i] >0 && timestamp - time[i] < 300)
		{
			total += hit[i];
		}
	}
	return total;
}

void test_362()
{
	HitCounter_hit(1);
	HitCounter_hit(2);
	HitCounter_hit(3);
	printf("%d\n", HitCounter_gethit(4));
	HitCounter_hit(300);
	printf("%d\n", HitCounter_gethit(300));
	printf("%d\n", HitCounter_gethit(301));

	HitCounter_hitII(1);
	HitCounter_hitII(2);
	HitCounter_hitII(3);
	printf("%d\n", HitCounter_gethitII(4));
	HitCounter_hitII(300);
	HitCounter_hitII(300);
	HitCounter_hitII(300);
	printf("%d\n", HitCounter_gethitII(300));
	printf("%d\n", HitCounter_gethitII(301));
}

