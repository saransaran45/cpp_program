#include <bits/stdc++.h>
using namespace std;

void buffleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool val = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                val = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (!val)
        {
            break;
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {28, 3, 15, 68, 53, 55, 4, 15};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(arr2) / sizeof(arr2[0]);
    buffleSort(arr2, len);
    printArray(arr2, len);
    return 0;
}