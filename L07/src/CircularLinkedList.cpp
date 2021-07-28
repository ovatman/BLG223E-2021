#include <iostream>
#include <stdio.h>
#include "CircularLinkedList.h"

using namespace std;

CircularLinkedList::CircularLinkedList(){
    head=new DoubleNode(-1, true);
    head->set_next(head);
    head->set_prev(head);
}

CircularLinkedList::~CircularLinkedList(){
    DoubleNode* p = head;
    DoubleNode* n = head;

    while(!n->is_sentinel()){
        n=p->get_next();
        delete p;
        p=n;
    }
    delete head;
}

DoubleNode* CircularLinkedList::contains(int data){

    DoubleNode* p=head->get_next();
    while(!p->is_sentinel() && p->get_data()!=data)
        p=p->get_next();
    
    if(p->is_sentinel())
        return NULL;
    else return p;

}


DoubleNode* CircularLinkedList::search_prev(int data){
    DoubleNode *p=head->get_next();

    if(p->is_sentinel() || data<=p->get_data())
        return head;
    else{
        while(!p->is_sentinel()){
            if(p->get_next()->get_data()>=data)
                return p;
            p=p->get_next();
        }
        return p->get_prev();
    }

}


void CircularLinkedList::clear_list(){
    DoubleNode* p = head->get_next();
    DoubleNode* n = head->get_next();

    while(!n->is_sentinel()){
        n=p->get_next();
        delete p;
        p=n;
    }
    head->set_next(head);
    head->set_prev(head);
}

void CircularLinkedList::add_node(int n){
    
    DoubleNode* new_node = new DoubleNode(n, false);
    
    DoubleNode* prev = this->search_prev(n);


    DoubleNode* old_next= prev->get_next();
    new_node->set_next(old_next);
    new_node->set_prev(prev);
    prev->set_next(new_node);
    old_next->set_prev(new_node);
    

}

void CircularLinkedList::remove_node(int n){
    
    DoubleNode* rem_node = this->contains(n);
    if(rem_node==NULL){
        cout<<"Element not found"<<endl;
        return;
    }

    DoubleNode* prev = rem_node->get_prev();

    DoubleNode* next= rem_node->get_next();
    prev->set_next(next);
    next->set_prev(prev);
    
    delete rem_node;
    
}

void CircularLinkedList::print_list(){
    DoubleNode* p=head->get_next();

    cout << "||->";
    
    while(!p->get_next()->is_sentinel()){
        cout<<p->get_data()<<"->";
        p=p->get_next();
    }
    if(!p->is_sentinel())
        cout<<p->get_data();
    cout<<endl;

}


void CircularLinkedList::reverse_print_list(){
    DoubleNode* p=head->get_prev();


    cout << "R->";
    
    while(!p->get_prev()->is_sentinel()){
        cout<<p->get_data()<<"->";
        p=p->get_prev();
    }
    if(!p->is_sentinel())
        cout<<p->get_data();
    
    cout<<endl;

}