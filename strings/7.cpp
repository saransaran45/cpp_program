#include<bits/stdc++.h>
using namespace std;

int  main(){
    string name{},res{};
    cout << "Enter string :";
    getline (cin,name);
    int len = name.length();
    for(int i=0; i<len ;i++){
        res += name[i]+1 ;
    }
    cout << res;
    return 0;
}