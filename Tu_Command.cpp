#include "Command.h"
#include "DataGenerator.h"

void Command_0()
{
    const vector<int> DATA_SIZE =
        {
            10000,
            30000,
            50000,
            100000,
            300000,
            500000,
        };
    vector<vector<int>> GeneratedDataArray = vector<vector<int>>(DATA_SIZE.size());
    ofstream fo;
    ifstream fi;
    string file_path;
    int n;

    for (int input_order = 0; input_order < INPUT_ORDER_NAME.size(); ++input_order)
    {
        cout << BREAK_LINE << INPUT_ORDER_NAME[input_order] << "\n" << BREAK_LINE;

        // Write header
        fo.open("Report - " + INPUT_ORDER_NAME[input_order] + ".csv");
        fo << "Data size,";
        fo.flush();
        for (int data_index = 0; data_index < DATA_SIZE.size(); ++data_index)
        {
            file_path = "Data/Data - " + to_string(input_order) + "-" + INPUT_ORDER_NAME[input_order] + "-" + to_string(DATA_SIZE[data_index]) + ".txt";
            
            fo << DATA_SIZE[data_index] << ",,";
            fo.flush();

            GeneratedDataArray[data_index] = vector<int>(DATA_SIZE[data_index]);

            fi.open(file_path);
            fi >> n;
            for (int i = 0; i < n; ++i)
            {
                fi >> GeneratedDataArray[data_index][i];
            }
            fi.close();
        }
        
        fo << "\nResulting statics,";
        fo.flush();
        for (int j = 0; j < DATA_SIZE.size(); ++j)
        {
            fo << "Running time,Comparision,";
            fo.flush();
        }
        fo << endl;

        vector<int> arr;

        // Process
        for (int index = 0; index < ALGO_NAME.size(); ++index)
        {
            cout << BREAK_LINE;
            cout << ALGO_NAME[index] << endl;
            cout << BREAK_LINE;

            fo << ALGO_NAME[index] << ",";
            fo.flush();

            for (int data_index = 0; data_index < DATA_SIZE.size(); ++data_index)
            {
                arr = vector<int>(GeneratedDataArray[data_index]);

                cout << "Input size: " << arr.size() << endl;

                MeasureInfo algo_info = MeasureSorting(SORT_ARRAY[index], SORT_ARRAY_COUNTING[index], arr, 0b11);

                fo << algo_info.time << "," << algo_info.comparison_counter << ",";
                fo.flush();

                PrintReport(algo_info, 0b11);

                cout << BREAK_LINE;
            }
            fo << endl;
        }
        fo.close();
    }

    cout << "END!" << endl;
    fo.open("end.txt");
    fo.close();
}

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