#include <iostream>
#include <stdio.h>
#include <stack>

#include "Tree.h"

using namespace std;

int main(int argc, char *argv[]){

    Tree* t=new Tree();

    t->printTree();
    t->printPreOrder();
    t->printInOrder();
    t->printPostOrder();
    t->printBreadthFirst();
    return EXIT_SUCCESS;
}
