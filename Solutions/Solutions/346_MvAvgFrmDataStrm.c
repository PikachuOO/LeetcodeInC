/*346. Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3

*/

#include "fifo.h"
#include "common.h"
int getAvgFromDataStream(int val, int size)
{
	static int curSum = 0;
	static int curSize = 0;

	if (curSize < size)
	{
		curSize++;
		curSum += val;
		fifo_push(val);
	}
	else if (curSize == size)
	{
		curSum -= fifo_pop();
		curSum += val;
		fifo_push(val);
	}
	return curSum / curSize;
}

void test_346()
{
	getAvgFromDataStream(1, 3);
	getAvgFromDataStream(10, 3);
	getAvgFromDataStream(3, 3);
	getAvgFromDataStream(5, 3);
}