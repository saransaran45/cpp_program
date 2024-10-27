#include<bits/stdc++.h>
using namespace std;

bool kadane(vector<int>&arr, int t){
    set<int>count;
    int sum{};
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
        if(sum == t){
            return true;
        }
        if(count.find(sum-t) != count.end()){
            return true;
        }
        count.insert(sum);
    }
    return false;
}

int main(){
    vector<int>arr = {1,3,5,6,7,9};
    int t = 17;
    bool ans = kadane(arr,t);
    cout << ans;
    return 0;
}