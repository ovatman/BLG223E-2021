#pragma once
#include "DoubleNode.h"

class CircularLinkedList{
    private:
        DoubleNode* head;

    public:
        CircularLinkedList();
        ~CircularLinkedList();
        void clear_list();
        void add_node(int);
        void remove_node(int);
        void print_list();
        void reverse_print_list();
        DoubleNode* contains(int);
        DoubleNode* search_prev(int);

};