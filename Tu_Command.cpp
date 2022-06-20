#include "Command.h"
#include "DataGenerator.h"

void Command_1(int8_t sort_index, string file_path, int8_t output_option)
{
    // Init
    ifstream fi(file_path);
    if (!fi.is_open())
    {
        PrintError("Cannot open input file!");
        return;
    }
    int32_t n;
    fi >> n;
    vector<int> arr = vector<int>(n);

    // Read array
    for (int i = 0; i < n; ++i)
    {
        fi >> arr[i];
    }
    fi.close();

    // Print initial info to console
    cout << "ALGORITHM MODE\n";
    cout << "Algorithm: " << ALGO_NAME[sort_index] << "\n";
    cout << "Input file: " << file_path << "\n";
    cout << "Input size: " << arr.size() << "\n";
    cout << BREAK_LINE;

    // Process
    MeasureInfo algo_info = MeasureSorting(SORT_ARRAY[sort_index], SORT_ARRAY_COUNTING[sort_index], arr, output_option);

    PrintReport(algo_info, output_option);

    ExportArray(arr, "output.txt");
}

void Command_5(int8_t first_sort_index, int8_t second_sort_index, int32_t input_size, int8_t input_order)
{
    // init
    vector<int> first_arr = vector<int>(input_size);
    GenerateData(&first_arr[0], first_arr.size(), input_order);
    vector<int> second_arr = vector<int>(first_arr);

    ExportArray(first_arr, "input.txt");

    // Print initial info to console
    cout << "COMPARE MODE\n";
    cout << "Algorithm: " << ALGO_NAME[first_sort_index] << " | " << ALGO_NAME[second_sort_index] << "\n";
    cout << "Input size: " << input_size << "\n";
    cout << "Input order: " << INPUT_ORDER_NAME[input_order] << "\n";
    cout << BREAK_LINE;

    // Process
    MeasureInfo first_info = MeasureSorting(SORT_ARRAY[first_sort_index], SORT_ARRAY_COUNTING[first_sort_index], first_arr, 0b11);
    MeasureInfo second_info = MeasureSorting(SORT_ARRAY[second_sort_index], SORT_ARRAY_COUNTING[second_sort_index], second_arr, 0b11);

    // Print Report to console
    PrintReport(first_info, second_info, 0b11);
}