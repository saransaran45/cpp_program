#include<bits/stdc++.h>
using namespace std;

int main(){
    string name = "Welcome to all, Hello Take Your Seat";
    int len = name.length();
    for(int i=0 ; i<len ; i++){
        if(name[i]=='h'||'H' && name[i+1]=='e' && name[i+2] == 'l' && name[i+3]=='l' &&
        name[i+4] == 'o'){
            cout << "Hello is present in the string" ;
            break;
        }
    }
    return 0;
}