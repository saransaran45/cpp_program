// choose the pivot element and select the correct position for that pivot element.
// swap the pivot element with the exact location
// the element which are located before the pivot elements are less than are equal to the pivot element right side
// of the pivot element values are greater than the pivot element

#include <bits/stdc++.h>
using namespace std;

void display(vector<int> arr)
{
    int n = arr.size();
    for (auto a : arr)
    {
        cout << a << " ";
    }
}

int position(vector<int> &arr, int lb, int ub)
{
    int start = lb, end = ub;
    int pivot = arr[lb];
    while(start < end){
        while(arr[start] <= pivot){
            start ++ ;
        }
        while(arr[end] > pivot){
            end--;
        }
        if(start < end){
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[lb],arr[end]);
    return end;
}

void quick(vector<int> &arr, int lb, int ub)
{
    if(lb<ub){
        int p = position(arr,lb,ub);
        quick(arr,lb,p-1);
        quick(arr,p+1,ub);
    }
}

int main()
{
    vector<int> arr = {7, 2, 4, 8, 4, 2, 6, 9};
    int lb = 0;
    int ub = arr.size() - 1;
    quick(arr, lb, ub);
    display(arr);
}