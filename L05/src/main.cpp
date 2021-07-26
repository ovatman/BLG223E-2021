#include <iostream>
#include <stdio.h>
#include "SingleLinkedList.h"

using namespace std;

int main(int argc, char *argv[]){



    SingleLinkedList* s=new SingleLinkedList();

    s->add_node(5);
    s->add_node(1);
    s->add_node(10);
    s->add_node(8);

    s->print_list();
    s->clear_list();
    
    s->add_node(10);
    s->add_node(8);

    s->print_list();

    delete s;

    return EXIT_SUCCESS;
}

