#include<bits/stdc++.h>
using namespace std;

int main(){
    string  name = "I am okay,Task completed";
    string r;
    int len = name.length();
    for(int i=0;i<len ; i++){
        if( name[i] == 'A' || name[i] == 'E'  || name[i] == 'I' || name[i] == 'O' || name[i] == 'U' || name[i] == 'a'
        || name[i] == 'e'|| name[i] == 'i'|| name[i] == 'o'|| name[i] == 'u' || name[i] ==',' ){
            r+=name[i];
            //cout << name[i] <<endl;
        }
        else if(name[i] == ' '){
            r+=' ';
        }
        else{
            r+='*';
        }
    }
    cout << r;
    return 0;
}