#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <fstream>
#include <sstream>
#include "Calculator.h"

using namespace std;

void stack_examples();
void queue_examples();
void deque_examples();
void vector_example();

int main(int argc, char *argv[]){

    //stack_examples();
    //queue_examples();
    //deque_examples();
    //vector_example();

    if(argc < 2){
        cout<<"Please provide a filename"<<endl;
        return EXIT_FAILURE;
    }

    fstream infile;
    string line;
    Calculator c;

    infile.open(argv[1],ios::in);
    
    if(infile.is_open()){
        while(getline(infile,line)){
            stringstream ss(line);

            string command;
            int op1,op2;

            ss >> command >> op1 >> op2;
            if(command.compare("ADD")==0){
                cout<<c.add(op1,op2)<<" ";
            }   
            else if(command.compare("SUB")==0){
                cout<<c.sub(op1,op2)<<" ";
            }
            else if(command.compare("MULT")==0){
                cout<<c.mult(op1,op2)<<" ";
            }
            else if(command.compare("DIV")==0){
                cout<<c.div(op1,op2)<<" ";
            }
            else{
                cout<<"Unknown command"<<endl;
            }


        }
    }

    infile.close();
    return EXIT_SUCCESS;
}

void vector_example(){
    vector<int> v;

    cout<<v.capacity()<<endl;
    cout<<v.size()<<endl;


    for(int i=0;i<15;i++){
        v.push_back(i);
        cout<<v.capacity()<<endl;
    }

    //cout<<v.capacity()<<endl;
    cout<<v.size()<<endl;
    
    v[0]=100;
    v.pop_back();

    for(int i:v)
        cout << i <<" ";

    cout<<endl;

    for(int i=0;i<v.size();i++)
        cout << v[i] <<" ";


    cout<<endl;
    vector<int>::iterator it;

    for(it=v.begin();it!=v.end();it++)
        cout<<*it<<" ";
    
    cout<<endl;

    
    for(vector<int>::reverse_iterator rit=v.rbegin();rit!=v.rend();rit++)
        cout<<*rit<<" ";
    
    cout<<endl;
}

void deque_examples(){
    deque<int> dq;

    dq.push_front(1);
    dq.push_front(2);
    dq.push_back(-1);
    dq.push_back(-2);
    dq.pop_back();
    dq.pop_front();

    for(auto i:dq){
        cout<<i<<" ";
    }

}

void queue_examples(){
    queue<int> q;

    for(int i=0;i<15;i++){
        q.push(i);
        q.push(i*2);
        cout<<q.front()<<"-";
        cout<<q.back()<<" ";
        q.pop();
    }

    cout<<endl;

}

void stack_examples(){
stack<int> s;

    for(int i=0;i<15;i++)
        s.push(i);
        
    for(int i=0;i<15;i++){
        if(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }

    cout<<endl;
}