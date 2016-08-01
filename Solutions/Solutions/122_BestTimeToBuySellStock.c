/*Say you have an array for which the ith element is the price of a given stock on day i. 
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find
the maximum profit.*/
#include "common.h"

int MaxProfit(int price[], int size)
{
	int i;
	int minPrice = price[0];
	int maxProfit = 0;
	for (i = 1; i < size; i++)
	{
		minPrice = MIN(minPrice, price[i]);
		maxProfit = MAX(maxProfit, price[i] - minPrice);
	}
}

