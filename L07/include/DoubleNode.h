#pragma once
#include <stdio.h>

class DoubleNode{
    private:
        int data;
        const bool sentinel;
        DoubleNode* next;
        DoubleNode* prev;

    public:
        DoubleNode(int data, bool sent):sentinel(sent){
            this->data= data;
            this->next=NULL;
            this->prev=NULL;
        }
        void set_data(int);
        int get_data();
        void set_next(DoubleNode*);
        DoubleNode* get_next();
        void set_prev(DoubleNode*);
        DoubleNode* get_prev();
        bool is_sentinel();

};