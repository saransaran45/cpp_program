#include <bits/stdc++.h>
using namespace std;

class MyClass {
public:
    void print() const {
        cout << "Const print called" << endl;
    }
    
    void print() {
        cout << "Non-const print called" << endl;
    }
};

int main() {
    const MyClass obj1;
    MyClass obj2;
    
    obj1.print();  // calls const version of print()
    obj2.print();  // calls non-const version of print()
    
    return 0;
}