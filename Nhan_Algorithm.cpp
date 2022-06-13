#include "SortAlgorithms.h"

double InsertionSort(int arr[], const int &n)
{
	clock_t start = clock();
	int x, j;
	for (int i = 1; i < n; i++)
	{
		x = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] >= x)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = x;
	}
	return (clock() - start);
}

void InsertionSortCounting(int arr[], const int &n, uint64_t &comparison_counter)
{
	for (int i = 1; ++comparison_counter && i < n; i++)
	{
		int x = arr[i];
		int j = i - 1;
		while (++comparison_counter && j >= 0 && ++comparison_counter && arr[j] >= x)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = x;
	}
}