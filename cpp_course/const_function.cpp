#include <bits/stdc++.h>
using namespace std;

class Dog
{
    int age;
    string name;

public:
    Dog()
    {
        age = 5;
        name = "ram";
    }

    // const parameter to reference variable
    void setAge(const int &a)
    {
        age = a;
        age++;
    }

    int getAge() { return age; }

    // const return value
    const string &getName() { return name; }

    // const function
    void printDogName() const { cout << "const " << name << endl; }
    void printDogName() { cout << "non_const " << name << endl; }
};

int main()
{
    Dog d;
    int i = 5;
    d.setAge(i);
    cout << d.getAge() << endl;
    const string &name = d.getName();
    // name = "seetha";
    d.printDogName();

    const Dog d2;
    d2.printDogName();
}