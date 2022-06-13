#include "Command.h"
#include "DataGenerator.h"

void Command_2(int8_t sort_index, int32_t input_size, int8_t input_order, int8_t output_option)
{
	//init
	vector<int> arr = vector<int>(input_size);
	GenerateData(&arr[0], arr.size(), input_order);

	ExportArray(arr, "input.txt");

	//Print initial info to console
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << ALGO_NAME[sort_index] << "\n";
	cout << "Input size: " << arr.size() << "\n";
	cout << "Input order: " << INPUT_ORDER_NAME[input_order] << "\n";
	cout << BREAK_LINE;

	// Process
	MeasureInfo algo_info = MeasureSorting(SORT_ARRAY[sort_index],SORT_ARRAY_COUNTING[sort_index], arr, output_option);

	//Print report to console
	PrintReport(algo_info, output_option);
}

void Command_3(int8_t sort_index, int32_t input_size, int8_t output_option)
{
	//init
	vector<int> arr_1 = vector<int>(input_size);
	GenerateData(&arr_1[0], arr_1.size(), 0);
	vector<int> arr_2 = vector<int>(input_size);
	GenerateData(&arr_2[0], arr_2.size(), 3);
	vector<int> arr_3 = vector<int>(input_size);
	GenerateData(&arr_3[0], arr_3.size(), 1);
	vector<int> arr_4 = vector<int>(input_size);
	GenerateData(&arr_4[0], arr_4.size(), 2);

	// Export generated array
	ExportArray(arr_1, "input_1.txt");
	ExportArray(arr_2, "input_2.txt");
	ExportArray(arr_3, "input_3.txt");
	ExportArray(arr_4, "input_4.txt");

	// Print initial info to console - Array 1
	cout << "ALGORITHM MODE\n";
	cout << "Algorithm: " << ALGO_NAME[sort_index] << "\n";
	cout << "Input size: " << arr_1.size() << "\n\n";
	cout << "Input order: " << INPUT_ORDER_NAME[0] << "\n";
	cout << BREAK_LINE;

	// Process - Array 1
	MeasureInfo algo_info_1 = MeasureSorting(SORT_ARRAY[sort_index],SORT_ARRAY_COUNTING[sort_index], arr_1, output_option);

	// Print report to console - Array 1
	PrintReport(algo_info_1, output_option);

	// Print initial info to console - Array 2
	cout << "Input order: " << INPUT_ORDER_NAME[3] << "\n";
	cout << BREAK_LINE;

	// Process - Array 2
	MeasureInfo algo_info_2 = MeasureSorting(SORT_ARRAY[sort_index],SORT_ARRAY_COUNTING[sort_index], arr_2, output_option);

	// Print report to console - Array 2
	PrintReport(algo_info_2, output_option);

	// Print initial info to console - Array 3
	cout << "Input order: " << INPUT_ORDER_NAME[1] << "\n";
	cout << BREAK_LINE;

	// Process - Array 3
	MeasureInfo algo_info_3 = MeasureSorting(SORT_ARRAY[sort_index],SORT_ARRAY_COUNTING[sort_index], arr_3, output_option);

	// Print report to console - Array 3
	PrintReport(algo_info_3, output_option);

	// Print initial info to console - Array 4
	cout << "Input order: " << INPUT_ORDER_NAME[2] << "\n";
	cout << BREAK_LINE;

	// Process - Array 4
	MeasureInfo algo_info_4 = MeasureSorting(SORT_ARRAY[sort_index],SORT_ARRAY_COUNTING[sort_index], arr_4, output_option);

	// Print report to console - Array 4
	PrintReport(algo_info_4, output_option);
}

void Command_4(int8_t first_sort_index, int8_t second_sort_index, string file_path)
{
	// init
	ifstream fi(file_path);
	if (!fi.is_open())
	{
		PrintError("Cannot open input file!");
		return;
	}
	int32_t n;
	fi >> n;
	vector<int> first_arr = vector<int>(n);

	// Read array
	for (int i = 0; i < n; ++i)
	{
		fi >> first_arr[i];
	}
	fi.close();
	vector<int> second_arr = vector<int>(first_arr);

	// Print initial info to console
	cout << "COMPARE MODE\n";
	cout << "Algorithm: " << ALGO_NAME[first_sort_index] << " | " << ALGO_NAME[second_sort_index] << "\n";
	cout << "Input file: " << file_path << "\n";
	cout << "Input size: " << first_arr.size() << "\n";
	cout << BREAK_LINE;
	
	// Process
	MeasureInfo first_info = MeasureSorting(SORT_ARRAY[first_sort_index], SORT_ARRAY_COUNTING[first_sort_index], first_arr, 0b11);
	MeasureInfo second_info = MeasureSorting(SORT_ARRAY[second_sort_index], SORT_ARRAY_COUNTING[second_sort_index], second_arr, 0b11);

	//Print report to console
	PrintReport(first_info, second_info, 0b11);

	// Export sorted array
	ExportArray(first_arr, "output.txt");
}