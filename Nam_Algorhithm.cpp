#include "SortAlgorithms.h"
// Counting Sort
double CountingSort(int array[], const int &n)
{
    clock_t start = clock();
    int max = array[0], min = array[0];
    vector <int> ans = vector<int>(n);
    for (int i = 1;i < n; ++i)
    {
        if (max < array[i])
            max = array[i];
        if (min > array[i])
            min = array[i];
    }
    vector<int> count(max - min + 1, 0);
    for (int i = 0; i < n; i++)
    {
        count[array[i] - min]++;
        ans[i] = array[i];
    }
    for (int i = 1; i < count.size(); i++) 
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) 
    {
        array[count[ans[i] - min] - 1] = ans[i];
        count[ans[i] - min]--;
    }
    return (clock() - start);
}
//
void CountingSortCounting(int array[], const int &n, uint64_t &comparison_counter)
{
    int max = array[0], min = array[0];
    vector<int> ans = vector<int>(n);
    for (int i = 1; ++comparison_counter && i < n; ++i)
    {
        if (++comparison_counter && max < array[i])
            max = array[i];
        if (++comparison_counter && min > array[i])
            min = array[i];
    }
    vector<int> count(max - min + 1, 0);
    for (int i = 0; ++comparison_counter && i < n; i++)
    {
        count[array[i] - min]++;
        ans[i] = array[i];
    }
    for (int i = 1; ++comparison_counter && i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; ++comparison_counter && i >= 0; i--)
    {
        array[count[ans[i] - min] - 1] = ans[i];
        count[ans[i] - min]--;
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
    {
        return (clock() - start);
    }
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
