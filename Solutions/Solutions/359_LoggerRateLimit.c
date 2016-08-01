/*Design a logger system that receive stream of messages along with its timestamps,
each message should be printed if and only if it is not printed in the last 10 seconds.

Given a message and a timestamp (in seconds granularity),
return true if the message should be printed in the given timestamp, otherwise returns false.

It is possible that several messages arrive roughly at the same time.

Example:

Logger logger = new Logger();

// logging string "foo" at timestamp 1
logger.shouldPrintMessage(1, "foo"); returns true; 

// logging string "bar" at timestamp 2
logger.shouldPrintMessage(2,"bar"); returns true;

// logging string "foo" at timestamp 3
logger.shouldPrintMessage(3,"foo"); returns false;

// logging string "bar" at timestamp 8
logger.shouldPrintMessage(8,"bar"); returns false;

// logging string "foo" at timestamp 10
logger.shouldPrintMessage(10,"foo"); returns false;

// logging string "foo" at timestamp 11
logger.shouldPrintMessage(11,"foo"); returns true;
*/

#include "hash.h"
#include "common.h"
static hash_table h1;
int Logger(int timestamp, char * msg)
{
	int key;
	int ret = 0;
	

	key = hash_get(&h1, msg, timestamp);
	if (key == -1)
	{
		hash_set(&h1, msg, timestamp);
		ret = 1;
	}
	else
	{
		if (timestamp - key >= 10)
		{
			hash_set(&h1, msg, timestamp);
			ret = 1;
		}
	}

	return ret;
}

void test_359()
{
	hash_init(&h1, 65535);
	printf("%d\n", Logger(1, "foo"));
	printf("%d\n", Logger(2, "bar"));
	printf("%d\n", Logger(3, "foo"));
	printf("%d\n", Logger(8, "bar"));
	printf("%d\n", Logger(10, "foo"));
	printf("%d\n", Logger(11, "foo"));
}