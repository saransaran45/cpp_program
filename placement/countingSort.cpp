#include <bits/stdc++.h>
using namespace std;

void display(vector<int>arr){
    for(auto a:arr){
        cout << a << " ";
    }
}

void countSort(vector<int>&arr,int n){
    vector<int>count(3,0);
    vector<int>ans(n);
    for(auto& a:arr){
        count[a]++;
    }
    for(int i=1; i<3;i++){
        count[i] = count[i]+count[i-1];
    }
    for(int i=n-1; i>=0; i--){
        
        ans[--count[arr[i]]] = arr[i];
    }
    display(ans);
}

int main(){
    vector<int>arr = {1,2,0,1,2,1,1,0,0,2,0,1};
    int n = arr.size();
    countSort(arr,n);
}