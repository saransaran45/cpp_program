#include <bits/stdc++.h>
using namespace std;
 
 
int add(int a, int b)
{
  return a+b;
}
 
float add(double a, double b)
{
    return a+b;
}
 
// Driver code
int main()
{
	int a;
	float b;
    a=add(10, 2);
    b=add(5.3, 6.2);
    cout<< "addition of integers = "<<a<<endl;
    cout<< "addition of float numbers = "<<b<<endl;
 
    return 0;
}