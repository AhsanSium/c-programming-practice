#include <bits/stdc++.h>
using namespace std;

class Student
{

public:
    string name;
    int std_id;

    // Constructor Overloading depends on function parameters
    Student(){} // Will not give error if empty object defined Ex: Student s1;

    Student( string name, int std_id ){
        this->name = name;
        this->std_id = std_id;
    }

    void print_info(){cout << "Name: "<< name <<", ID: "<<std_id<<"\n"; }

};

int main()
{
    Student s1("Ahsan", 39);

    s1.print_info();

    return 0;
}
