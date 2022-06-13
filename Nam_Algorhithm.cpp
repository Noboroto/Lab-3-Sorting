#include "SortAlgorithms.h"
// Counting Sort
double CountingSort(int array[], const int &n)
{
    clock_t start = clock();
    vector<int> count(n, 0);
    for (int i = 0; i < n; i++)
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
    return (clock() - start);
}
//
void CountingSortCounting(int array[], const int &n, uint64_t &comparison_counter)
{
    vector<int> count(n, 0);
    for (int i = 0; ++comparison_counter && i < n; i++)
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
void MergeArray(vector<int> &a, vector<int> &b, int array[], const int &n)
{
    int ia = 0, ib = 0, ic = 0;
    while (ia < a.size() && ib < b.size())
        array[ic++] = (a[ia] < b[ib]) ? a[ia++] : b[ib++];
    while (ia < a.size())
        array[ic++] = a[ia++];
    while (ib < b.size())
        array[ic++] = b[ib++];
}

void Split(vector<int> &a, vector<int> &b, int array[], const int &n)
{
    for (int i = 0; i < a.size(); i++)
    {
        a[i] = array[i];
        b[i] = array[i + a.size()];
    }
    if (a.size() < b.size())
        b[b.size() - 1] = array[n - 1];
}

double MergeSort(int array[], const int &n)
{
    clock_t start = clock();
    if (n == 1)
        return (clock() - start);
    vector<int> a(n / 2, 0);
    vector<int> b(n / 2, 0);
    if (n % 2 != 0)
        b.push_back(0);
    Split(a, b, array, n);
    MergeSort(&a[0], a.size());
    MergeSort(&b[0], b.size());
    MergeArray(a, b, array, n);
    return (clock() - start);
}
//
void MergeArrayCounting(vector<int> &a, vector<int> &b, int array[], const int &n, uint64_t &comparison_counter)
{
    int ia = 0, ib = 0, ic = 0;
    while (++comparison_counter && ia < a.size() && ++comparison_counter && ib < b.size())
        array[ic++] = (++comparison_counter && a[ia] < b[ib]) ? a[ia++] : b[ib++];
    while (++comparison_counter && ia < a.size())
        array[ic++] = a[ia++];
    while (++comparison_counter && ib < b.size())
        array[ic++] = b[ib++];
}
void SplitCounting(vector<int> &a, vector<int> &b, int array[], const int &n, uint64_t &comparison_counter)
{
    for (int i = 0; ++comparison_counter && i < a.size(); i++)
    {
        a[i] = array[i];
        b[i] = array[i + a.size()];
    }
    if (++comparison_counter && a.size() < b.size())
        b[b.size() - 1] = array[n - 1];
}
void MergeSortCounting(int array[], const int &n, uint64_t &comparison_counter)
{
    if (++comparison_counter && n == 1)
        return;
    vector<int> a(n / 2, 0);
    vector<int> b(n / 2, 0);
    if (++comparison_counter && n % 2 != 0)
        b.push_back(0);
    SplitCounting(a, b, array, n, comparison_counter);
    MergeSortCounting(&a[0], a.size(), comparison_counter);
    MergeSortCounting(&b[0], b.size(), comparison_counter);
    MergeArrayCounting(a, b, array, n, comparison_counter);
}
