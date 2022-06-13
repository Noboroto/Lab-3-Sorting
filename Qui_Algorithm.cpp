#include "SortAlgorithms.h"


void BubbleSort(vector<int> &array)
{
    int i, j, temp;
    for (i = 0; i < array.size() - 1; ++i)
    {
        for (j = i + 1; j < array.size(); ++j)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void BubbleSortCounting(vector<int> &array, uint64_t &comparison_counter)
{
    int i, j, temp;
    for (i = 0; ++comparison_counter && i < array.size() - 1; ++i)
    {
        for (j = i + 1; ++comparison_counter && j < array.size(); ++j)
        {
            if (++comparison_counter && array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}


void SelectionSort(vector <int> &array)
{
    int i, j, min_index, temp;
    for (i = 0; i < array.size() - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < array.size(); j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
                temp = array[i];
                array[i] = array[min_index];
                array[min_index] = temp;
            }
        }
    }
}

void SelectionSortCounting(vector<int> &array, uint64_t &comparison_counter)
{
    int i, j, min_index, temp;
    for (i = 0; ++comparison_counter && i < array.size() - 1; i++)
    {
        min_index = i;
        for (j = i + 1; ++comparison_counter && j < array.size(); j++)
        {
            if (++comparison_counter &&  array[j] < array[min_index])
            {
                min_index = j;
                temp = array[i];
                array[i] = array[min_index];
                array[min_index] = temp;
            }
        }
    }
}


void QuickSortExpand(vector<int> &array, int left, int right)
{
    int mid_value = array[(left + right) / 2];
    int i = left;
    int j = right;
    int temp;
    while(i < j)
    {
        while(array[i] < mid_value)
        {
            i++;
        }
        while(array[j] > mid_value)
        {
            j--;
        }
        if(i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if(i < right)
    {
        QuickSortExpand(array, i, right);
    }
    if(left < j)
    {
        QuickSortExpand(array, left, j);
    }
}

void QuickSort(vector<int> &array)
{
    QuickSortExpand(array, 0, array.size() - 1);
}

void QuickSortExpandCounting(vector<int> &array, int left, int right, uint64_t &comparison_counter)
{
    int mid_value = array[(left + right) / 2];
    int i = left;
    int j = right;
    int temp;
    while (i < j)
    {
        while (array[i] < mid_value)
        {
            i++;
        }
        while (array[j] > mid_value)
        {
            j--;
        }
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (i < right)
    {
        QuickSortExpandCounting(array, i, right, comparison_counter);
    }
    if (left < j)
    {
        QuickSortExpandCounting(array, left, j, comparison_counter);
    }
}

void QuickSortCounting(vector<int> &array, uint64_t &comparison_counter)
{
    QuickSortExpandCounting(array, 0, array.size() - 1, comparison_counter);
}


void HeapPartition(vector <int> &array, int n, int i)
{
    int max = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && array[left] > array[max])
    {
        max = left;
    }
    if (right < n && array[right] > array[max])
    {
        max = right;
    }
    if (max != i) 
    {
        temp = array[i];
        array[i] = array[max];
        array[max] = temp;
        HeapPartition(array, n, max);
    }
}

void HeapSort(vector<int> &array)
{
    for (int i = (array.size() / 2) - 1; i >= 0; i--)
    {
        HeapPartition(array, array.size(), i);
    }
    int temp;
    for (int i = (array.size() - 1); i >= 0; i--) 
    {
        temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        HeapPartition(array, i, 0);
    }
}

void HeapPartitionCounting(vector<int> &array, int n, int i, uint64_t &comparison_counter)
{
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if ((++comparison_counter && left < n) && (++comparison_counter && array[left] > array[max]))
    {
        max = left;
    }
    if ((++comparison_counter && right < n) && (++comparison_counter && array[right] > array[max]))
    {
        max = right;
    }
    if (++comparison_counter && max != i)
    {
        temp = array[i];
        array[i] = array[max];
        array[max] = temp;
        HeapPartitionCounting(array, n, max, comparison_counter);
    }
}

void HeapSortCounting(vector<int> &array, uint64_t &comparison_counter)
{
    for (int i = (array.size() / 2) - 1; ++comparison_counter && i >= 0; i--)
    {
        HeapPartitionCounting(array, array.size(), i, comparison_counter);
    }
    int temp;
    for (int i = (array.size() - 1); ++comparison_counter && i >= 0; i--)
    {
        temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        HeapPartitionCounting(array, i, 0, comparison_counter);
    }
}