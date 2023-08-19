#include<bits/stdc++.h>
using namespace std;

int main(){
    string name{};
    cout << "Enter the string :";
    getline (cin,name);
    int len = name.length();
    for(int i=0;i<len;i++){
        for(int j=1;j<=len-i;j++){
            cout << name.substr(i,j) <<" ";
        }
    }
    return 0;
}