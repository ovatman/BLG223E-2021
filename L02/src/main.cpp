#include <iostream>
#include <stdio.h>
#include "Student.h"
using namespace std;

template <typename T>
T max_num(T first, T second){

    if(first<=second)
        return second;
    else return first;

}

int main(){

    Student* astudent = new Student("Tolga");

    astudent->set_grade(-90);

    cout<< astudent->get_name()<< " "<<astudent->get_grade()<<endl;

    delete astudent;

    cout << max_num<double>(5.3,1.8)<<endl;
    return EXIT_SUCCESS;
}

