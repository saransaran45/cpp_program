#include<bits/stdc++.h>
using namespace std;

int main(){
    string str1,str2,matching;
    cout<<"Enter the first string:";
    cin>>str1;
    cout<<"Enter the second string:";
    cin>>str2;
    for (int i=0 ; i<str1.length() ; i++){
        for (int j=0 ; j<str2.length() ; j++){
            if(str1[i] == str2[j] ){
                if(str1[i] != 'a'||'e'||'i'||'o'||'u'){
                matching += str1[i];
                }
            }
        }
    }
    cout<<"matching letters :"<<matching;
    return 0;
}