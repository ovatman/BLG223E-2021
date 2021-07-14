#include "MyStack.h"

MyStack::MyStack(){
    top=-1;
}
bool MyStack::push(int element){
    if(!this->isFull()){
        arr[++top]=element;
        return true;
    }
    return false;
}
int MyStack::pop(){
    if(!this->isEmpty()){
        return arr[top--];
    }

    return -1;
}
int MyStack::peek(){
    if(!this->isEmpty()){
        return arr[top];
    }

    return -1;
}

bool MyStack::isEmpty(){
    return top == -1;
}
bool MyStack::isFull(){
    return top == MAX_STACK_SIZE-1;
}
void MyStack::clear(){
    top=-1;
}