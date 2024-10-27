#include<bits/stdc++.h>
using namespace std;
int n{};

void display(vector<int>arr){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}

void squr(vector<int>arr){
    int i=0,j=n;
    vector<int>arr2;
    while(i<=j){
        if(abs(arr[i]) >= abs(arr[j-1])){
            arr2.push_back(arr[i]*arr[i]);
            cout <<"i :" << i << endl;
            i++;
            
        }else{
            arr2.push_back(arr[j-1]*arr[j-1]);
            j--;
            cout <<"j :" << j << endl;
        }
        
    }
    
    display(arr2);
    
}

int main(){
    vector<int>arr{-2,-1,0,1,2,3,9};
    n = arr.size();
    squr(arr);
}