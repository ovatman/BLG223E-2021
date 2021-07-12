#include "Student.h"

Student::Student(string name){
    this->name = name;
    this->grade = 10;
}

Student::~Student(){
    cout<<"Hello from the destructor"<<endl;
}

void Student::set_grade(int sgrade){
    if(sgrade<0)
        grade=0;
    else
        grade = sgrade;
}

int Student::get_grade(){
    return grade;
}

string Student::get_name(){
    return name;
}
