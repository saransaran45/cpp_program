#include<bits/stdc++.h>

using namespace std;
 
void add(int a, int b)
{
  cout << "sum with two variables= " << (a + b)<<endl;
}
 
void add(int a, int b, int c)
{
    cout << endl << "sum with three variables= " << (a + b + c)<< endl;
}
 
int main()
{
    add(18, 2);
    add(5, 8, 4);
 	return 0;
}
