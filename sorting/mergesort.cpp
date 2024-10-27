#include <bits/stdc++.h>
using namespace std;

void display(vector<int> arr)
{
    for (auto a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
}

void merge(vector<int> &arr, int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;

    vector<int> arr2(arr.size());

    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            arr2[k] = arr[i];
            i++;
        }
        else
        {
            arr2[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        arr2[k] = arr[i];
        i++;
        k++;
    }

    while (j <= ub)
    {
        arr2[k] = arr[j];
        j++;
        k++;
    }

    for (int i = lb; i <= ub; i++)
    {
        arr[i] = arr2[i];
    }

    display(arr);
}

void mergesort(vector<int> &arr, int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergesort(arr, lb, mid);
        mergesort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main()
{
    vector<int> arr = {7, 6, 5, 4, 3, 2, 1};
    int n = arr.size() - 1;
    int lb = 0;
    mergesort(arr, lb, n);
}
