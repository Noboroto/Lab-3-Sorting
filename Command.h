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

int8_t IsNumber(string s);
int8_t GetSortIndex(string s);
int8_t GetInputOrderIndex(string s);
int8_t GetOutpuParameterIndex(string s);
int32_t GetIntFromString(string s);
void PrintError(string s);
void PrintReport(MeasureInfo info, const int8_t &output_option);
void PrintReport(MeasureInfo first, MeasureInfo second, const int8_t &output_option);
void ExportArray(const vector<int>& arr, string file_name);

void Command_1(int8_t sort_index, string file_path, int8_t output_option);
void Command_2(int8_t sort_index, int input_size, int8_t input_order, int8_t output_option);
void Command_3(int8_t sort_index, int input_size, int8_t output_option);
void Command_4(int8_t first_sort_index, int8_t second_sort_index, string file_path);
void Command_5(int8_t first_sort_index, int8_t second_sort_index, int input_size, int8_t input_order);
#endif