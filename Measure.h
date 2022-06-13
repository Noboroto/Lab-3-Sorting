#ifndef MEASURE
#define MEASURE

#include <cstdint>
#include <vector>

using namespace std;

typedef void (*SortAlgoPointer)(int array[], const int &n);
typedef void (*SortAlgoPointerWithCounting)(int array[], const int &n, uint64_t &comparison_counter);

struct MeasureInfo
{
    uint64_t time;
    uint64_t comparison_counter;
    MeasureInfo();
};

MeasureInfo MeasureSorting(SortAlgoPointer sort, SortAlgoPointerWithCounting sort_counting, std::vector<int> &arr, const int8_t &output_parameter);
#endif