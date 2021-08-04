#include <iostream>
#include <stdio.h>
#include "BSTree.h"
using namespace std;

int main(int argc, char *argv[]){

    BSTree* t = new BSTree();

    t->add(10);
    t->add(5);
    t->add(15);
    t->add(3);
    t->add(7);
    t->add(11);
    t->add(20);
    t->add(1);
    t->add(4);
    t->add(6);
    t->add(9);

    t->remove(15);
    
    t->remove(5);

    t->remove(10);

    if(t->contains(7))
        t->printInOrder();

    if(t->contains(5))
        t->printBreadthFirst();

    delete t;
    return EXIT_SUCCESS;
}
