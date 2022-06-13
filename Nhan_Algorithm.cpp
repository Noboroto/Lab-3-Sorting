#include"SortAlgorithms.h"

void InsertionSortCounting(std::vector<int>& arr, uint64_t& comparison_counter)
{
	for (int i = 1; ++comparison_counter && i < arr.size(); i++)
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

void InsertionSort(std::vector<int>& arr)
{
	int x, j;
	for (int i = 1; i < arr.size(); i++)
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
}
