#include <iostream>
#include <stdio.h>
#include <stack>

#include "Tree.h"

using namespace std;

int main(int argc, char *argv[]){

    Tree* t=new Tree("ABDCEF","DBAECF");

    //t->printTree();
    t->printPreOrder();
    t->printInOrder();
    t->printPostOrder();
    t->printBreadthFirst();

    delete t;
    return EXIT_SUCCESS;
}
