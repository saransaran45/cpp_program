#include<bits/stdc++.h>
using namespace std;

void display(vector<int>& arr){
    for(auto const& a:arr){
        cout << a << " ";
    }
}

void solve(vector<int>&arr,int n){
    stack<int>st;
    for(int i=n-1; i>=0; i--){
        int temp = arr[i];
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        
        if(!st.empty()){
            arr[i] = st.top();
        }else{
            arr[i] = -1;
        }
        st.push(temp);
    }
    display(arr);
}

int main(){
    vector<int>arr = {7,6,9,5,19,8};
    int n = arr.size();
    solve(arr,n);
    return 0;
}