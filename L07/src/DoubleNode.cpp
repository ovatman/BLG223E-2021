#include "DoubleNode.h"

void DoubleNode::set_data(int data){
    this->data=data;
}

int DoubleNode::get_data(){
    return this->data;
}

void DoubleNode::set_next(DoubleNode* next){
    this->next=next;
}

DoubleNode* DoubleNode::get_next(){
    return this->next;
}

void DoubleNode::set_prev(DoubleNode* prev){
    this->prev=prev;
}

DoubleNode* DoubleNode::get_prev(){
    return this->prev;
}

bool DoubleNode::is_sentinel(){
    return this->sentinel;
}