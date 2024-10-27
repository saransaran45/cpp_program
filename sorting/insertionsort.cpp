// sorted part and unordered part
#include<bits/stdc++.h>
using namespace std;

void display(vector<int>arr,int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

void insertion(vector<int>arr,int n){
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    display(arr,n);
}

int main(){
    vector<int>arr = {5,4,6,2,1};
    int n =arr.size();
    insertion(arr,n);
}