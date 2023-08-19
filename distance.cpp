#include<iostream>
#include<string.h>
using namespace std;

class Distance {
    private :
        float feet;
        float inches;
    public :
        void setFeet(float value){
            feet = value;
        }
        void setInches(float value){
            inches = value;
        }
        float getFeet(){
            return (feet);
        }
        float getInches(){
            return (inches);
        }
};

int main(){
    float feet_1,inches_1,feet_2,inches_2;
    Distance distance_1,distance_2;
    cout << "Enter first distance feet and inches :" ;
    cin >> feet_1 >> inches_1;
    distance_1.setFeet(feet_1);
    distance_1.setInches(inches_1);
    cout << "Enter second distance feet and inches :" ;
    cin >> feet_2 >> inches_2;
    distance_2.setFeet(feet_2);
    distance_2.setInches(inches_2);
    cout << "SumOfFeet = " << distance_1.getFeet() + distance_2.getFeet() << "\n";
    cout << "SumOfInches = " << distance_1.getInches() + distance_2.getInches() ;
    return 0;
}