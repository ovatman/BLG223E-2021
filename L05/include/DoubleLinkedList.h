#pragma once
#include "DoubleNode.h"

class DoubleLinkedList{
    private:
        DoubleNode* head;
        DoubleNode* tail;

    public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        void clear_list();
        void add_node(int);
        void remove_node(int);
        void print_list();
        void reverse_print_list();
        DoubleNode* contains(int);
        DoubleNode* search_prev(int);

};