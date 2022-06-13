#include "SortAlgorithms.h"

void RadixSort(vector<int> &array)
{
    int i, exp = array[0];
    int counting[2] = {0, 0};
    int bit = 0;

    vector<int> temp = vector<int>(array);

    for (i = 1; i < array.size(); i++)
    {
        if (array[i] > exp)
        {
            exp = array[i];
        }
    }
    for (; exp > 0; exp >>= 1, ++bit)
    {
        counting[0] = 0;
        counting[1] = 0;

        for (i = 0; i < array.size(); i++)
        {
            counting[(array[i] >> bit) & 1]++;
            temp[i] = array[i];
        }

        counting[1] += counting[0];

        for (i = temp.size() - 1; i >= 0; i--)
        {
            array[counting[(temp[i] >> bit) & 1] - 1] = temp[i];
            counting[(temp[i] >> bit) & 1]--;
        }
    }
}

void RadixSortCounting(vector<int> &array, uint64_t &comparison_counter)
{

    int i, exp;
    int counting[2] = {0, 0};
    int bit = 0;
    vector<int> temp = vector<int>(array);

    for (i = 1; ++comparison_counter && i < array.size(); i++)
    {
        if (++comparison_counter && array[i] > exp)
        {
            exp = array[i];
        }
    }

    for (; ++comparison_counter && exp > 0; exp >>= 1, ++bit)
    {
        counting[0] = 0;
        counting[1] = 0;

        for (i = 0; ++comparison_counter && i < array.size(); i++)
        {
            counting[(array[i] >> bit) & 1]++;
            temp[i] = array[i];
        }

        counting[1] += counting[0];

        for (i = temp.size() - 1; ++comparison_counter && i >= 0; i--)
        {
            array[counting[(temp[i] >> bit) & 1] - 1] = temp[i];
            counting[(temp[i] >> bit) & 1]--;
        }
    }
}

void ShellSort(vector<int> &array)
{
    int i, temp, j;
    for (int gap = array.size() / 2; gap > 0; gap /= 2)
    {
        for ( i = gap; i < array.size(); i += 1)
        {
            temp = array[i];
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

void ShellSortCounting(vector<int> &array, uint64_t &comparison_counter)
{
    int i, temp, j;
    for (int gap = array.size() / 2; ++comparison_counter && gap > 0; gap /= 2)
    {
        for (i = gap; ++comparison_counter && i < array.size(); i += 1)
        {
            temp = array[i];
            for (j = i; ++comparison_counter && j >= gap && ++comparison_counter && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

void FlashSort(vector<int> &array) {}
void FlashSortCounting(vector<int> &array, uint64_t &comparison_counter) {}

void ShakerSort(std::vector<int> &arr)
{
    int index = -1;
    int left = 0;
    int right = arr.size() - 1;
    int temp_index, i, temp;

    while (left < right)
    {
        temp_index = index;
        for (i = right; i > left; i--)
        {
            if (arr[i] < arr[i - 1])
            {
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                index = i - 1;
            }
        }
        left = index + 1;
        if (temp_index == index)
            break;
        temp_index = index;
        for (i = left; i < right; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                index = i + 1;
            }
        }
        right = index - 1;
        if (temp_index == index)
            break;
    }
}
void ShakerSortCounting(std::vector<int> &arr, uint64_t &comparison_counter)
{
    int index = -1;
    int left = 0;
    int right = arr.size() - 1;
    int temp_index, i, temp;

    while (++comparison_counter && (left < right))
    {
        temp_index = index;
        for (i = right; ++comparison_counter && i > left; i--)
        {
            if (++comparison_counter && (arr[i] < arr[i - 1]))
            {
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                index = i - 1;
            }
        }
        left = index + 1;
        if (++comparison_counter && (temp_index == index))
            break;
        temp_index = index;
        for (i = left; ++comparison_counter && i < right; i++)
        {
            if (++comparison_counter && (arr[i] > arr[i + 1]))
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                index = i + 1;
            }
        }
        right = index - 1;
        if (++comparison_counter && (temp_index == index))
            break;
    }
}
