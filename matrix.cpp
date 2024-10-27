#include<bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>&m){
    bool flag = true;
    for(int i=0; i<m.size(); i++){
        if(flag){
            sort(m[i].begin(),m[i].end());
            flag = false;
        }
        else{
            sort(m[i].begin(),m[i].end(),greater<int>());
            flag = true;
        } 
    }
    
    flag = false;
    for(int i=0; i<m.size(); i++){
        vector<int>temp;
        for(int j=0; j<m[0].size(); j++){
            temp.push_back(m[j][i]);
        }
        if(flag){
            sort(temp.begin(),temp.end());
            flag = false;
        }else{
            sort(temp.begin(),temp.end(),greater<int>());
            flag = true;
        }
        for(int k=0; k<m[0].size(); k++){
            m[k][i] = temp[k];
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
    
}

int main(){
    vector<vector<int>>m{{1,2,3},{4,5,6},{7,8,9}};
    helper(m);
    return 0;
}