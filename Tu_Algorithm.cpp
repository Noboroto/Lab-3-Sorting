#include "SortAlgorithms.h"

double RadixSort(int array[], const int &n)
{
    clock_t start = clock();
    int i, exp, max_value = array[0];
    int counting[10];
    int bit = 0;

    vector<int> temp = vector<int>(n);

    for (i = 1; i < n; ++i)
    {
        if (array[i] > max_value)
        {
            max_value = array[i];
        }
    }

    for (exp = 1; max_value / exp > 0; exp *= 10)
    {
        for (i = 0; i < 10; ++i)
        {
            counting[i] = 0;
        }

        for (i = 0; i < n; ++i)
        {
            counting[(array[i] / exp) % 10]++;
            temp[i] = array[i];
        }

        for (i = 1; i < 10; i++)
        {
            counting[i] += counting[i - 1];
        }

        for (i = temp.size() - 1; i >= 0; i--)
        {
            array[counting[(temp[i] / exp) % 10] - 1] = temp[i];
            counting[(temp[i] / exp) % 10]--;
        }
    }

    return (clock() - start);
}

void RadixSortCounting(int array[], const int &n, uint64_t &comparison_counter)
{
    int i, exp, max_value = array[0];
    int counting[10];
    int bit = 0;

    vector<int> temp = vector<int>(n);

    for (i = 1;++comparison_counter && i < n; ++i)
    {
        if (++comparison_counter && array[i] > max_value)
        {
            max_value = array[i];
        }
    }

    for (exp = 1; ++comparison_counter && max_value / exp > 0; exp *= 10)
    {
        for (i = 0; ++comparison_counter && i < 10; ++i)
        {
            counting[i] = 0;
        }

        for (i = 0; ++comparison_counter && i < n; ++i)
        {
            counting[(array[i] / exp) % 10]++;
            temp[i] = array[i];
        }

        for (i = 1; ++comparison_counter && i < 10; i++)
        {
            counting[i] += counting[i - 1];
        }

        for (i = temp.size() - 1; ++comparison_counter && i >= 0; i--)
        {
            array[counting[(temp[i] / exp) % 10] - 1] = temp[i];
            counting[(temp[i] / exp) % 10]--;
        }
    }
}

double ShellSort(int array[], const int &n)
{
    clock_t start = clock();
    int i, temp, j;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i += 1)
        {
            temp = array[i];
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
            {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
    return (clock() - start);
}

void ShellSortCounting(int array[], const int &n, uint64_t &comparison_counter)
{
    int i, temp, j;
    for (int gap = n / 2; ++comparison_counter && gap > 0; gap /= 2)
    {
        for (i = gap; ++comparison_counter && i < n; i += 1)
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

double FlashSort(int array[], const int &n)
{
    clock_t start = clock();
    int min_val = array[0];
    int max_index = 0;
    int m = int(0.45 * n);
    vector<int> l = vector<int>(m, 0);
    int i, temp, k;

    for (i = 1; i < n; ++i)
    {
        if (array[i] < min_val)
        {
            min_val = array[i];
        }
        if (array[i] > array[max_index])
        {
            max_index = i;
        }
    }

    if (array[max_index] == min_val)
    {
        return (clock() - start);
    }

    double c1 = (double)(m - 1) / (array[max_index] - min_val);

    for (i = 0; i < n; ++i)
    {
        k = int(c1 * (array[i] - min_val));
        ++l[k];
    }

    for (i = 1; i < m; ++i)
    {
        l[i] += l[i - 1];
    }

    temp = array[max_index];
    array[max_index] = array[0];
    array[0] = temp;

    int nmove = 0;
    int j = 0;
    k = m - 1;
    int t = 0;
    int flash, hold;
    while (nmove < n - 1)
    {
        while (j > l[k] - 1)
        {
            j++;
            k = int(c1 * (array[j] - min_val));
        }
        flash = array[j];
        if (k < 0)
        {
            break;
        }
        while (j != l[k])
        {
            k = int(c1 * (flash - min_val));
            hold = array[t = --l[k]];
            array[t] = flash;
            flash = hold;
            ++nmove;
        }
    }

    InsertionSort(array, n);
    return (clock() - start);
}

void FlashSortCounting(int array[], const int &n, uint64_t &comparison_counter)
{
    int min_val = array[0];
    int max_index = 0;
    int m = int(0.45 * n);
    vector<int> l = vector<int>(m, 0);
    int i, temp, k;

    for (i = 1;++comparison_counter && i < n; ++i)
    {
        if (++comparison_counter && array[i] < min_val)
        {
            min_val = array[i];
        }
        if (++comparison_counter && array[i] > array[max_index])
        {
            max_index = i;
        }
    }

    if (++comparison_counter && array[max_index] == min_val)
    {
        return;
    }

    double c1 = (double)(m - 1) / (array[max_index] - min_val);

    for (i = 0; ++comparison_counter && i < n; ++i)
    {
        k = int(c1 * (array[i] - min_val));
        ++l[k];
    }

    for (i = 1; ++comparison_counter && i < m; ++i)
    {
        l[i] += l[i - 1];
    }

    temp = array[max_index];
    array[max_index] = array[0];
    array[0] = temp;

    int nmove = 0;
    int j = 0;
    k = m - 1;
    int t = 0;
    int flash, hold;
    while (++comparison_counter && nmove < n - 1)
    {
        while (++comparison_counter && (j > l[k] - 1))
        {
            j++;
            k = int(c1 * (array[j] - min_val));
        }
        flash = array[j];
        if (++comparison_counter &&(k < 0))
        {
            break;
        }
        while (++comparison_counter && (j != l[k]))
        {
            k = int(c1 * (flash - min_val));
            hold = array[t = --l[k]];
            array[t] = flash;
            flash = hold;
            ++nmove;
        }
    }

    InsertionSortCounting(array, n, comparison_counter);
}

double ShakerSort(int arr[], const int &n)
{
    clock_t start = clock();
    int index = -1;
    int left = 0;
    int right = n - 1;
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
        {
            break;
        }
        temp_index = index;
        for (i = left; i < right; ++i)
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
        {
            break;
        }
    }

    return (clock() - start);
}

void ShakerSortCounting(int arr[], const int &n, uint64_t &comparison_counter)
{
    int index = -1;
    int left = 0;
    int right = n - 1;
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
        for (i = left; ++comparison_counter && i < right; ++i)
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
