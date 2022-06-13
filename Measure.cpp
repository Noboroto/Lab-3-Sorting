#include "Measure.h"
#include <ctime>

MeasureInfo::MeasureInfo()
{
    time = 0;
    comparison_counter = 0;
}

MeasureInfo MeasureSorting(SortAlgoPointer sort, SortAlgoPointerWithCounting sort_counting, std::vector<int>& arr, const int8_t&output_parameter)
{
    //initialize
    MeasureInfo info = MeasureInfo();
    clock_t start, end;

    // mesuare time
    switch (output_parameter)
    {
    case 0b01:
        start = clock();
        sort(&arr[0], arr.size());
        end = clock();
        info.time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        break;
    case 0b10:
        sort_counting(&arr[0], arr.size(), info.comparison_counter);
        break;
    case 0b11:
        vector<int> tmp = vector<int>(arr);
        start = clock();
        sort(&arr[0], arr.size());
        end = clock();
        info.time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        sort_counting(&tmp[0], tmp.size(), info.comparison_counter);
        break;
    }

    //save result
    return info;
}