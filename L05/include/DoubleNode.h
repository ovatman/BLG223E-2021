#pragma once
class DoubleNode{
    private:
        int data;
        DoubleNode* next;
        DoubleNode* prev;

    public:
        DoubleNode(int);
        void set_data(int);
        int get_data();
        void set_next(DoubleNode*);
        DoubleNode* get_next();
        void set_prev(DoubleNode*);
        DoubleNode* get_prev();

};