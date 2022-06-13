#include "SortAlgorithms.h"
// Counting Sort
void CountingSort(std::vector<int> &array)
{
    vector<int> count(array.size(), 0);
    for (int i = 0; i < array.size(); i++)
    {
        count[array[i]]++;
    }
    int tmp = 0;
    for (int i = 0; i < count.size(); i++)
    {
        while (count[i] > 0)
        {
            array[tmp++] = i;
            count[i]--;
        }
    }
}
//
void CountingSortCounting(std::vector<int> &array, uint64_t &comparison_counter)
{
    vector<int> count(array.size(), 0);
    for (int i = 0; ++comparison_counter && i < array.size(); i++)
    {
        count[array[i]]++;
    }
    int tmp = 0;
    for (int i = 0; ++comparison_counter && i < count.size(); i++)
    {
        while (++comparison_counter && count[i] > 0)
        {
            array[tmp++] = i;
            count[i]--;
        }
    }
}
//--------------------------------------------------------------
// Merge Sort
void MergeArray(std::vector<int> &a, std::vector<int> &b, std::vector<int> &array)
{
    int ia = 0, ib = 0, ic = 0;
    while (ia < a.size() && ib < b.size())
        array[ic++] = (a[ia] < b[ib]) ? a[ia++] : b[ib++];
    while (ia < a.size())
        array[ic++] = a[ia++];
    while (ib < b.size())
        array[ic++] = b[ib++];
}

void Split(std::vector<int> &a, std::vector<int> &b, std::vector<int> &array)
{
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = array[i];
        b[i] = array[i + a.size()];
    }
    if (a.size() < b.size())
        b[b.size() - 1] = array[array.size() - 1];
}

void MergeSort(std::vector<int> &array)
{
    if (array.size() == 1)
        return;
    vector<int> a(array.size() / 2, 0);
    vector<int> b(array.size() / 2, 0);
    if (array.size() % 2 != 0)
        b.push_back(0);
    Split(a, b, array);
    MergeSort(a);
    MergeSort(b);
    MergeArray(a, b, array);
}
//
void MergeArrayCounting(std::vector<int> &a, std::vector<int> &b, std::vector<int> &array, uint64_t &comparison_counter)
{
    int ia = 0, ib = 0, ic = 0;
    while (++comparison_counter && ia < a.size() && ++comparison_counter && ib < b.size())
        array[ic++] = (++comparison_counter && a[ia] < b[ib]) ? a[ia++] : b[ib++];
    while (++comparison_counter && ia < a.size())
        array[ic++] = a[ia++];
    while (++comparison_counter && ib < b.size())
        array[ic++] = b[ib++];
}
void SplitCounting(std::vector<int> &a, std::vector<int> &b, std::vector<int> &array, uint64_t &comparison_counter)
{
    for (int i = 0; ++comparison_counter && i < a.size(); i++)
    {
        a[i] = array[i];
        b[i] = array[i + a.size()];
    }
    if (++comparison_counter && a.size() < b.size())
        b[b.size() - 1] = array[array.size() - 1];
}
void MergeSortCounting(std::vector<int> &array, uint64_t &comparison_counter)
{
    if (++comparison_counter && array.size() == 1)
        return;
    vector<int> a(array.size() / 2, 0);
    vector<int> b(array.size() / 2, 0);
    if (++comparison_counter && array.size() % 2 != 0)
        b.push_back(0);
    SplitCounting(a, b, array, comparison_counter);
    MergeSortCounting(a, comparison_counter);
    MergeSortCounting(b, comparison_counter);
    MergeArrayCounting(a, b, array, comparison_counter);
}
