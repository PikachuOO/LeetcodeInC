
void swap(int *a, int *b)
{
	int tmp =*a;
	*a = *b;
	*b = tmp;
}
void heapify(int ar[], int size, int i)
{
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int largest = i;

	if (left < size && ar[left] > ar[largest])
	{
		largest = left;
	}

	if (right < size && ar[right] > ar[largest])
	{
		largest = right;
	}

	if (i != largest)
	{
		swap(&ar[i], &ar[largest]);
		heapify(ar, size, largest);
	}
}

void heapsort(int ar[], int size)
{
	int i;
	for (i = size / 2 -1; i >= 0; i--)
	{
		heapify(ar, size, i);
	}
	for (i = size - 1; i >= 0; i--)
	{
		swap(&ar[0], &ar[i]);
		heapify(ar, i, 0);
	}
}
void heapsort_n(int ar[], int size, int n)
{
	int i;
	int nn = 0;

	if (n > size)
		n = size;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(ar, size, i);
	}
	for (i = size - 1; i >= 0; i--)
	{
		swap(&ar[0], &ar[i]);
		if (++nn == n)
			break;
		heapify(ar, i, 0);
	}
}
void heapsort_test()
{
	int ar[] = {2, 5, 1, 4, 9};
	heapsort(ar, sizeof(ar) / sizeof(int));
}