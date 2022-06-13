#ifndef COMMAND_H
#define COMMAND_H
#include "SortAlgorithms.h"
#include <string>
#include <cstdint>
#include <fstream>
#include <iostream>

using namespace std;

const string BREAK_LINE = "-----------------------\n";

const vector<string> INPUT_ORDER_NAME =
	{
		"Randomized data",
		"Sorted data",
		"Reverse sorted data",
		"Nearly sorted data"};

// Hàm kiểm tra string có phải số hay không
int8_t IsNumber(string s);
// Hàm lấy vị trí của hàm sort từ tên
int8_t GetSortIndex(string s);
// Hàm lấy Input Order từ string
int8_t GetInputOrderIndex(string s);
// Hàm lấy Output Parameter từ string
int8_t GetOutpuParameterIndex(string s);
// Hàm chuyển string thành số
int32_t GetIntFromString(string s);
// Hàm in thông tin lỗi
void PrintError(string s);
// In báo cáo
void PrintReport(MeasureInfo info, const int8_t &output_option);
void PrintReport(MeasureInfo first, MeasureInfo second, const int8_t &output_option);
// Hàm xuất mảng ra file
void ExportArray(const vector<int>& arr, string file_name);

// Command in các loại hàm sort
void Command_0();
void Command_1(int8_t sort_index, string file_path, int8_t output_option);
void Command_2(int8_t sort_index, int input_size, int8_t input_order, int8_t output_option);
void Command_3(int8_t sort_index, int input_size, int8_t output_option);
void Command_4(int8_t first_sort_index, int8_t second_sort_index, string file_path);
void Command_5(int8_t first_sort_index, int8_t second_sort_index, int input_size, int8_t input_order);
#endif