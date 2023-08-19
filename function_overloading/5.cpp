#include<bits/stdc++.h>
using namespace std;
 
void add(int a, double b ,string c)
{
    cout<<a<<"\t"<<b<<"\t"<<c<<endl;
} 
 
void  add(string a,double b, int c)
{
    cout<<a<<"\t"<<b<<"\t"<<c<<endl;
}

void  add(int a,string b,double c)
{
    cout<<a<<"\t"<<b<<"\t"<<c<<endl;
} 
 
// Driver code
int main()
{
    add(10,2.5,"1st");
    add("2nd",6.7,3);
    add(5,"3rd",6.7);
 
      return 0;
}