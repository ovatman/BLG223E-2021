#include <iostream>
#include <stdio.h>

using namespace std;

class Student{
    private:
        string name;
        int grade;
    public:
        Student(string);
        ~Student();
        void set_grade(int);
        int get_grade();
        string get_name();
};
