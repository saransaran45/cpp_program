#include<bits/stdc++.h>
using namespace std;

int main(){
    string name;
    int flag{},len{};
    cout << "Enter a string :";
    getline(cin,name);
    len = name.length();
    len = len-1;
    for(int i=0 ; i<=len/2; i++){
        if(name[i] != name[len-i]){
            flag =1;
        }
    }
    string result = (flag==0) ? " is palindrome" : " is not palindrome";
    cout << name << result;
    return 0;
}