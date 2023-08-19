// #include <iostream>  
// using namespace std;  
// void change(int data);  
// int main()  
// {  
// int data = 3;  
// change(data);  
// cout << "Value of the data is: " << data<< endl;  
// return 0;  
// }  
// void change(int data)  
// {  
// data = 5;  
// } 

// #include<bits/stdc++.h>
// using namespace std;
// class Student{
//     private:
//         int rollNo;
//         string name;
//     public:
//         static int count;
//         Student(int rollNo,string name){
//             this->rollNo = rollNo;
//             this->name = name;
//             count++;
//         }
//         void display(){
//             cout<<"Name :"<<name<<endl<<"RollNUmber :"<<rollNo<<endl;
//         }
//         ~Student(){
//             cout<<"Finish code"<<endl;
//         }
// };

// int Student :: count = 0;

// int main(){
//     Student s1 =Student(1,"Arul");
//     Student s2 =Student(2,"Ram");
//     s1.display();
//     s2.display();
//     cout<<"Total Objects :"<<Student::count<<endl;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// class A{
//     private:
        
//     public:
//         int a;
//         void set_a(int val){
//             a = val;
//             cout<<a<<endl;
//         }
//         int get_a(){
//             cout<<a<<endl;
//             return a;
//         }
// };
// class B : public A{
//     private:
//         int b;
//     public:
//         void set_b(int val){
//             b = val;
//         }
        
//         void display(){
//             int res = get_a();
//             cout << res;
//             int result = res*b;
//             cout<<"multiplication of a and b :"<<result<<endl;
//         }
// };

// int main(){
//     A q;
//     q.set_a(15);
//     B s;
//     s.set_b(25);
//     s.display();
//     return 0;
// }