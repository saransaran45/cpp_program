#include<bits/stdc++.h>
using namespace std;

class Obj {
    private :
        int roll_no;
        string name;
    public :
        //Obj(int roll,string na) : roll_no(roll),name(na){};
        // Obj (int roll_no,string name){
        //     this->roll_no = roll_no;
        //     this->name = name;
        //}
        Obj (int roll,string na){
            roll_no = roll;
            name = na;
        }
    int get_roll(){
        return roll_no;
    }
    string get_name(){
        return name;
    }
    ~Obj(){
        cout <<endl<<"calling Destructor ="<<roll_no;
    }

    friend void print(Obj name);

};

void print(Obj name){
    name.roll_no = 11;
    cout << name.roll_no;
}

int main(){
    Obj saran(1,"arul");
    cout << saran.get_roll() << endl;
    print(saran);
    return 0;
}