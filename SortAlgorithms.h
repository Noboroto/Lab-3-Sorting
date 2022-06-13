#ifndef SORT_ALGORTIHMS
#define SORT_ALGORTIHMS

#include "Measure.h"
#include <string>

using namespace std;

// 0	selection-sort
// 1	insertion-sort
// 2	bubble-sort
// 3	heap-sort
// 4	merge-sort
// 5	quick-sort
// 6	radix-sort
// 7	shaker-sort
// 8	shell-sort
// 9	counting-sort
// 10	flash-sort

void SelectionSort(vector<int> &array);
void InsertionSort(vector<int> &array);
void BubbleSort(vector<int> &array);
void HeapSort(vector<int> &array);
void MergeSort(vector<int> &array);
void QuickSort(vector<int> &array);
void RadixSort(vector<int> &array);
void ShakerSort(vector<int> &array);
void ShellSort(vector<int> &array);
void CountingSort(vector<int> &array);
void FlashSort(vector<int> &array);

void SelectionSortCounting(vector<int> &array, uint64_t &comparison_counter);
void InsertionSortCounting(vector<int> &array, uint64_t &comparison_counter);
void BubbleSortCounting(vector<int> &array, uint64_t &comparison_counter);
void HeapSortCounting(vector<int> &array, uint64_t &comparison_counter);
void MergeSortCounting(vector<int> &array, uint64_t &comparison_counter);
void QuickSortCounting(vector<int> &array, uint64_t &comparison_counter);
void RadixSortCounting(vector<int> &array, uint64_t &comparison_counter);
void ShakerSortCounting(vector<int> &array, uint64_t &comparison_counter);
void ShellSortCounting(vector<int> &array, uint64_t &comparison_counter);
void CountingSortCounting(vector<int> &array, uint64_t &comparison_counter);
void FlashSortCounting(vector<int> &array, uint64_t &comparison_counter);

const vector<string> ALGO_NAME =
    {
        "Selection Sort",
        "Insertion Sort",
        "Bubble Sort",
        "Heap Sort",
        "Merge Sort",
        "Quick Sort",
        "Radix Sort",
        "Shaker Sort",
        "Shell Sort",
        "Counting Sort",
        "Flash Sort",
};

const vector<SortAlgoPointer> SORT_ARRAY =
    {
        SelectionSort,
        InsertionSort,
        BubbleSort,
        HeapSort,
        MergeSort,
        QuickSort,
        RadixSort,
        ShakerSort,
        ShellSort,
        CountingSort,
        FlashSort,
};

const vector<SortAlgoPointerWithCounting> SORT_ARRAY_COUNTING =
    {
        SelectionSortCounting,
        InsertionSortCounting,
        BubbleSortCounting,
        HeapSortCounting,
        MergeSortCounting,
        QuickSortCounting,
        RadixSortCounting,
        ShakerSortCounting,
        ShellSortCounting,
        CountingSortCounting,
        FlashSortCounting,
};
#endif