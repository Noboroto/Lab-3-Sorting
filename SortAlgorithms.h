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

double SelectionSort(int array[], const int &n);
double InsertionSort(int array[], const int &n);
double BubbleSort(int array[], const int &n);
double HeapSort(int array[], const int &n);
double MergeSort(int array[], const int &n);
double QuickSort(int array[], const int &n);
double RadixSort(int array[], const int &n);
double ShakerSort(int array[], const int &n);
double ShellSort(int array[], const int &n);
double CountingSort(int array[], const int &n);
double FlashSort(int array[], const int &n);

void SelectionSortCounting(int array[], const int &n, uint64_t &comparison_counter);
void InsertionSortCounting(int array[], const int &n, uint64_t &comparison_counter);
void BubbleSortCounting(int array[], const int &n, uint64_t &comparison_counter);
void HeapSortCounting(int array[], const int &n, uint64_t &comparison_counter);
void MergeSortCounting(int array[], const int &n, uint64_t &comparison_counter);
void QuickSortCounting(int array[], const int &n, uint64_t &comparison_counter);
void RadixSortCounting(int array[], const int &n, uint64_t &comparison_counter);
void ShakerSortCounting(int array[], const int &n, uint64_t &comparison_counter);
void ShellSortCounting(int array[], const int &n, uint64_t &comparison_counter);
void CountingSortCounting(int array[], const int &n, uint64_t &comparison_counter);
void FlashSortCounting(int array[], const int &n, uint64_t &comparison_counter);

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