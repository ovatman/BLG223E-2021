#include <iostream>
#include <stdio.h>
#include "DoubleLinkedList.h"

using namespace std;

DoubleLinkedList::DoubleLinkedList(){
    head=NULL;
    tail=NULL;
}

DoubleLinkedList::~DoubleLinkedList(){
    DoubleNode* p = head;
    DoubleNode* n = head;

    while(n!=NULL){
        n=p->get_next();
        delete p;
        p=n;
    }
}

DoubleNode* DoubleLinkedList::contains(int data){

    DoubleNode* p=head;
    while(p!=NULL && p->get_data()!=data)
        p=p->get_next();
    return p;

}


DoubleNode* DoubleLinkedList::search_prev(int data){
    DoubleNode *p=head;

    if(data<=head->get_data())
        return NULL;
    else{
        while(p->get_next()){
            if(p->get_next()->get_data()>=data)
                return p;
            p=p->get_next();
        }
        return p;
    }

}


void DoubleLinkedList::clear_list(){
    DoubleNode* p = head;
    DoubleNode* n = head;

    while(n!=NULL){
        n=p->get_next();
        delete p;
        p=n;
    }

    head=NULL;
    tail=NULL;
}

void DoubleLinkedList::add_node(int n){
    
    DoubleNode* new_node = new DoubleNode(n);
    if(head==NULL){
        head=new_node;
        tail=new_node;
    }
    else{
        DoubleNode* prev = this->search_prev(n);

        if(prev==NULL){
            new_node->set_next(head);
            head->set_prev(new_node);
            head=new_node;
        }
        else if(prev==tail){
            tail->set_next(new_node);
            new_node->set_prev(tail);
            tail=new_node;
        }
        else{
            DoubleNode* old_next= prev->get_next();
            new_node->set_next(old_next);
            new_node->set_prev(prev);
            prev->set_next(new_node);
            old_next->set_prev(new_node);
        }
    }
    

}

void DoubleLinkedList::remove_node(int n){
    
    DoubleNode* rem_node = this->contains(n);
    if(n==NULL){
        cout<<"Element not found"<<endl;
        return;
    }

    DoubleNode* prev = rem_node->get_prev();
   
    if(head==tail){
        delete head;
        head=NULL;
        tail=NULL;
    }
    else{
        if(rem_node==head){
            DoubleNode* old_head=head;
            head=head->get_next();
            head->set_prev(NULL);
        }
        else if(rem_node==tail){
            tail=prev;
            tail->set_next(NULL);
        }
        else{
            DoubleNode* next= rem_node->get_next();
            prev->set_next(next);
            next->set_prev(prev);
        }   
        delete rem_node;
    }

}

void DoubleLinkedList::print_list(){
    DoubleNode* p=head;
    
    cout << "||->";
    while(p!=tail){
        cout<<p->get_data()<<"->";
        p=p->get_next();
    }
    if(p!=NULL)
        cout<<p->get_data()<<endl;

}


void DoubleLinkedList::reverse_print_list(){
    DoubleNode* p=tail;
    
    cout << "R->";
    while(p!=head){
        cout<<p->get_data()<<"->";
        p=p->get_prev();
    }
    if(p!=NULL)
        cout<<p->get_data()<<endl;

}