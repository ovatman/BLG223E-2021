#include <iostream>
#include <stdio.h>
#include "SingleLinkedList.h"

using namespace std;

SingleLinkedList::SingleLinkedList(){
    head=NULL;
    tail=NULL;
}

SingleLinkedList::~SingleLinkedList(){
    delete head;
}

void SingleLinkedList::clear_list(){
    delete head;    
    head=NULL;
    tail=NULL;
}

Node* SingleLinkedList::search(int data){
    Node *p=head;

    if(data<head->get_data())
        return NULL;
    else{
        while(p->get_next()){
            if(p->get_next()->get_data()>data)
                return p;
            p=p->get_next();
        }
        return p;
    }

}

void SingleLinkedList::add_node(int n){
    Node* new_node = new Node(n);
    if(head==NULL){
        head=new_node;
        tail=new_node;
    }
    else{
        Node* prev = this->search(n);
        
        if(prev==NULL){
            new_node->set_next(head);
            head=new_node;
        }
        else if(prev==tail){
            tail->set_next(new_node);
            tail=new_node;
        }
        else{
            new_node->set_next(prev->get_next());
            prev->set_next(new_node);
        }
    }

}


void SingleLinkedList::print_list(){
    Node* p=head;
    
    cout << "||->";
    while(p!=tail){
        cout<<p->get_data()<<"->";
        p=p->get_next();
    }

    cout<<p->get_data()<<endl;

}