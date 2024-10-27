//select the minimum element from the unsorted part swap with the unordered starting position

#include<bits/stdc++.h>
using namespace std;

void display(vector<int>arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

void selection(vector<int>arr,int n){
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        if(min != i){
            swap(arr[i],arr[min]);
        }
    }
    display(arr,n);
}

int main(){
    vector<int>arr = {5,4,3,2,1};
    int n = arr.size();
    selection(arr,n);
}