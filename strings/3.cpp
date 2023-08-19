#include<bits/stdc++.h>
using namespace std;

int main(){
    string name;
    int len{},count = 1;
    printf("Enter string :");
    getline(cin,name);
    len = name.length();
    for(int i=0 ; i<len ;i++){
        if(name[i] ==' '){
            count+=1;
        }
    }
    cout << name <<" have " << count << " words";
    return 0;
}