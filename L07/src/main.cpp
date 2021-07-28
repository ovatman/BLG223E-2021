#include <iostream>
#include <stdio.h>
#include "CircularLinkedList.h"

using namespace std;

void circular_linked_list();

int main(int argc, char *argv[]){

    circular_linked_list();

    return EXIT_SUCCESS;
}

void circular_linked_list(){
   
    CircularLinkedList* s=new CircularLinkedList();

    s->add_node(5);
    s->add_node(1);
    s->add_node(10);
    s->add_node(8);

    s->print_list();
    s->reverse_print_list();
    
    s->clear_list();

    s->add_node(5);
    s->add_node(1);
    s->add_node(10);
    s->add_node(8);

    if(s->contains(7))
        cout<<"s contains 10"<<endl;
        
    s->remove_node(5);
    s->remove_node(1);
    if(!s->contains(1))
        cout<<"s does not contain 1"<<endl;
    s->remove_node(10);

    s->print_list();
    s->reverse_print_list();

    s->remove_node(8);
    
    s->print_list();
    s->reverse_print_list();

    delete s;

}

