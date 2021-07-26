#include "Node.h"

Node::Node(int data){
    this->data= data;
}

Node::~Node(){
    delete this->next;
}

void Node::set_data(int data){
    this->data=data;
}

int Node::get_data(){
    return this->data;
}

void Node::set_next(Node* next){
    this->next=next;
}

Node* Node::get_next(){
    return this->next;
}