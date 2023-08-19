#include <bits/stdc++.h>
using namespace std;

int main()
{
    string name;
    cout << "Enter a string :";
    getline(cin, name);
    int len = name.length();
    //cout << len;
    for (int i = len; i >= 0; i--)
    {
        cout << name[i];
    }
    return 0;
}