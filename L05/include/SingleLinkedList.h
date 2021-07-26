#pragma once
#include "Node.h"

class SingleLinkedList{
    private:
        Node* head;
        Node* tail;
        Node* search(int);

    public:
        SingleLinkedList();
        ~SingleLinkedList();
        void clear_list();
        void add_node(int);
        void remove_node(int);
        void print_list();
        bool contains(int);

};