#include <iostream>
#include <stdio.h>
#include "MyStack.h"
#include "MyQueue.h"

using namespace std;

const int MAX_GRADES=10;
void remove(int*,int);
void removal_problem();
void stack_examples();
void queue_examples();

int main(){

    //removal_problem();
    //stack_examples();
    queue_examples();

    return EXIT_SUCCESS;
}
void queue_examples(){
    MyQueue q;
    for(int i=0;i<15;i++){
        q.enqueue(i);
        q.enqueue(i*2);
        cout<<q.dequeue()<<" ";
    }
        
    cout<<endl;
}

void stack_examples(){
    MyStack s;
    for(int i=0;i<15;i++)
        s.push(i);
        
    for(int i=0;i<5;i++)
        if(!s.isEmpty())
            cout<<s.pop()<<" ";
    
    s.push(100);
    s.push(200);

    cout<<endl;
}

void removal_problem(){
    int grade = 0;

    int* grades = new int[MAX_GRADES];

    for(int i=0;i<MAX_GRADES;i++){
        grades[i]=i+1;
    }

    remove(grades, 9);

    
    remove(grades, 3);

    for(int i=0;i<MAX_GRADES;i++){
        cout<<grades[i]<<" ";
    }


    cout<<endl;


}
void remove(int* arr,int index){
    arr[index] = -1;
}