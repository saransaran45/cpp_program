#include <bits/stdc++.h>
using namespace std;

void printMessage(string message, int count = 1) {
    for(int i = 0; i < count; ++i) {
        cout << message << endl;
    }
}

void printMessage(int count, string message = "Hello") {
    for(int i = 0; i < count; ++i) {
        cout << message << endl;
    }
}

int main() {
    printMessage("Hello World");    // calls printMessage(std::string message, int count = 1)
    printMessage("Hello World", 3); // calls printMessage(std::string message, int count = 1)
    printMessage(3);                // calls printMessage(int count, std::string message = "Hello")
    printMessage(3, "Hi");          // calls printMessage(int count, std::string message = "Hello")
    
    return 0;
}