#include <iostream>
#include <stdio.h>
#include "SingleLinkedList.h"

using namespace std;

void single_linked_list();

int main(int argc, char *argv[]){

    //single_linked_list();
    
    return EXIT_SUCCESS;
}

void single_linked_list(){
    SingleLinkedList* s=new SingleLinkedList();

    s->add_node(5);
    s->add_node(1);
    s->add_node(10);
    s->add_node(8);

    s->print_list();
    //s->clear_list();
    if(s->contains(10))
        cout<<"s contains 10"<<endl;
    s->remove_node(5);
    s->remove_node(1);
    if(!s->contains(1))
        cout<<"s does not contain 1"<<endl;
    s->remove_node(10);
    s->remove_node(8);

    s->print_list();

    delete s;

}
