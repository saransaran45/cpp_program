#include<bits/stdc++.h>

using namespace std;

int main(){
    string val,ans,answer;
    cout<<"Enter the string=";
    getline(cin,val);
    int len{},count{};
    for(int i=0;i<val.length();i++){
        if(isspace(val[i]) || i==val.length()-1){
            if(i==val.length()-1){
                count++;
                ans+=val[i];
            }
            if(len<count){
                answer=ans;
                ans.clear();
                len=count;
                count=0;
                continue;
            }
        }
        count++;
        ans+=val[i];
    }
    cout<<"\nLargest word in "<<val<<" is "<<answer;
    return 0;
}