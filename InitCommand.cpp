#include "Command.h"

int8_t IsNumber(string s)
{
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            return false;
        }
    }
    return true;
}

int8_t GetSortIndex(string s)
{
    if (s == "selection-sort")
    {
        return 0;
    }
    if (s == "insertion-sort")
    {
        return 1;
    }
    if (s == "bubble-sort")
    {
        return 2;
    }
    if (s == "heap-sort")
    {
        return 3;
    }
    if (s == "merge-sort")
    {
        return 4;
    }
    if (s == "quick-sort")
    {
        return 5;
    }
    if (s == "radix-sort")
    {
        return 6;
    }
    if (s == "shaker-sort")
    {
        return 7;
    }
    if (s == "shell-sort")
    {
        return 8;
    }
    if (s == "counting-sort")
    {
        return 9;
    }
    if (s == "flash-sort")
    {
        return 10;
    }
    return -1;
}

int8_t GetInputOrderIndex(string s)
{
    if (s == "-rand")
    {
        return 0;
    }
    if (s == "-nsorted")
    {
        return 3;
    }
    if (s == "-sorted")
    {
        return 1;
    }
    if (s == "-rev")
    {
        return 2;
    }
    return -1;
}

int8_t GetOutpuParameterIndex(string s)
{
    if (s == "-time")
    {
        return 0b01;
    }
    if (s == "-comp")
    {
        return 0b10;
    }
    if (s == "-both")
    {
        return 0b11;
    }
    return -1;
}

int32_t GetIntFromString(string s)
{
    if (!IsNumber(s)) return -1;
    int32_t Result = 0;
    for (int32_t i = 0; i < s.size(); ++i)
    {
        Result = Result * 10 + (s[i] - '0');
    }
    return Result;
}

void PrintError(string s)
{
    cout << "Error: " << s << "\n";
}

void PrintReport(MeasureInfo info, const int8_t &output_option)
{
    string unit = ((info.time > 1) ? " miliseconds " : " milisecond ");

    switch (output_option)
    {
    case 0b01:
        cout << "Running time: " << info.time << unit << "\n";
        break;
    case 0b10:
        cout << "Comparisions: " << info.comparison_counter << "\n";
        break;
    case 0b11:
        cout << "Running time: " << info.time << unit << "\n";
        cout << "Comparisions: " << info.comparison_counter << "\n";
        break;
    }
}

void PrintReport(MeasureInfo first, MeasureInfo second, const int8_t &output_option)
{
    string first_unit = ((first.time > 1) ? " miliseconds " : " milisecond ");
    string second_unit = ((second.time > 1) ? " miliseconds " : " milisecond ");
    cout << "Running time: " << first.time << first_unit << "| " << second.time << second_unit << "\n";
    cout << "Comparisions: " << first.comparison_counter << " | " << second.comparison_counter << "\n";
}

void ExportArray(const vector<int> &arr, string file_name)
{
    ofstream fo(file_name);
    if (!fo.is_open())
    {
        PrintError("Cannot open file to export!");
    }
    fo << arr.size() << "\n";
    for (int32_t i = 0; i < arr.size(); ++i)
    {
        fo << arr[i] << " ";
    }
    fo.close();
}