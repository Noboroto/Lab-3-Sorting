#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

#endif