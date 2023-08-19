#include<bits/stdc++.h>
using namespace std;

int main(){
    string name;
    int len,i,count =1,max;
    cout << "Enter a full name :";
    getline(cin,name);
    len = name.length();
    for(i=0;i<len;i++){
        if(name[i] == ' '){
            count += 1;
        }
    }
    max = count;
    for(i =0; i<len ; i++){
        if(name[i] !=' ' && count == max){
            cout << name[i] << ".";
            max--;
        }else if(name[i] == ' ' && max != 1){
            cout << name[i+1] << ".";
            max--;
        }else if(name[i] == ' ' && max == 1){
            for(int j =i+1 ; j<len ;j++){
                cout << name[j];
            }
        }
    }
    return 0;
}