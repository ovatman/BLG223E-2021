#include <iostream>
#include <stdio.h>
#include "BinSTree.h"
using namespace std;

int main(int argc, char *argv[]){

    BinSTree* t = new BinSTree();

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

    if(t->contains(30))
        t->printInOrder();

    if(t->contains(6))
        t->printInOrder();

    delete t;
    return EXIT_SUCCESS;
}
