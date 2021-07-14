#include "Calculator.h"

int Calculator::add(int a,int b){
    return a+b;
}
int Calculator::sub(int a,int b){
    return a-b;
}
int Calculator::mult(int a,int b){
    return a*b;
}
int Calculator::div(int a,int b){
    if(b==0)
        return 0;
    return a/b;
}