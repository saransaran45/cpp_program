#include<bits/stdc++.h>
using namespace std;

class Employee{
    private :
        int id;
        string name;
        double salary;
    public:
        Employee(int i,string na,double sal=0) {
            id = i;
            name = na;
            salary = sal;
            // this -> id = id;
            // this -> name = name;
            // this -> salary = salary;
        }
        void setId(int id){
            this->id = id;
        }
        void setName(string name){
            this -> name = name;
        }
        void setSalary(double salary){
            this -> salary = salary;
        }
        int getId(){
            return id;
        }
        string getName(){
            return name;
        }
        double getSalary(){
            return salary;
        }
        void print(){
            cout<<"id ="<<id<<endl;
            cout<<"name ="<<name<<endl;
            cout << "salary ="<<salary<<endl;
        }
};
class PartTimeEmployee : public Employee{
    private :
        double workhour;
    public:
       PartTimeEmployee(int id1,string na,int wh)
       :Employee(id1,na){
            workhour = wh;
            setSalary(workhour);
       }
       void setSalary(int workhour){
        Employee::setSalary(workhour*100);
       }
       void print(){
        Employee::print();
        cout<<"Workhours = "<<workhour<<endl;
       }
};

int main(){
    Employee e1(1,"ram",10000);
    e1.print();

    PartTimeEmployee em2(2,"hari",180);
    em2.print();

    return 0;

}