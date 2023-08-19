#include <iostream>
#include <string>
using namespace std;
int main()
{
    int age;
    cout << "enter your age :";
    cin >> age;
    string res = age>=18 ? "you are eligible for voting" : "you are not eligible for voting";
    cout << res;
    return 0;
}