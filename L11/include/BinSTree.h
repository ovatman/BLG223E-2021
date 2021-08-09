#include <list>
#include "Node.h"
using namespace std;

class BinSTree{
    private:
        Node* root;
        void preorder_traverse(Node*);
        void inorder_traverse(Node*);
        void postorder_traverse(Node*);
        void postorder_destruct(Node*);
        Node* find_par(int, Node***);
        void inorder_construct(Node*,list<int>&);
    
    public:
        BinSTree();
        BinSTree(list<int> v);
        ~BinSTree();


        void add(int);
        bool contains(int);
        void remove(int);


        void printPreOrder();
        void printInOrder();
        void printPostOrder();
        void printBreadthFirst();

};