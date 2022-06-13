#ifndef MEASURE
#define MEASURE

#include <cstdint>
#include <vector>

using namespace std;

typedef void (*SortAlgoPointer)(std::vector<int>& array);
typedef void (*SortAlgoPointerWithCounting)(std::vector<int> &array, uint64_t &comparison_counter);

struct MeasureInfo
{
    uint64_t time;
    uint64_t comparison_counter;
    MeasureInfo();
};

MeasureInfo MeasureSorting(SortAlgoPointer sort, SortAlgoPointerWithCounting sort_counting, std::vector<int> &arr, const int8_t &output_parameter);
#endif