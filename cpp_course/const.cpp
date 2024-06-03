#include <bits/stdc++.h>
using namespace std;

int main()
{
    // if the const is on the left of * , Data is const
    //  if the const is on the right of *, pointer is const
    const int i = 8;
    const int k = 10;

    const_cast<int &>(i) = 6;
    cout << i << "\n";

    int j = 12;
    static_cast<const int &>(j) = 7;
    // j = j+2;
    cout << j << "\n";

    // const int * p1 = &i;
    // cout << &p1 << "\n";
    // p1 = p1++;
    // p1 = &k;
    // cout << &p1<<"\n";

    // int const * p4;

    // int* const p2;

    // const int* const p3;

    return 0;
}