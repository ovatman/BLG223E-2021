#pragma once
class Node{
    private:
        int data;
        Node* next;
    public:
        Node(int);
        ~Node();
        void set_data(int);
        int get_data();
        void set_next(Node*);
        Node* get_next();

};