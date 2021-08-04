#include "BSTNode.h"

class BSTree{
    private:
        BSTNode* root;
        void preorder_traverse(BSTNode*);
        void inorder_traverse(BSTNode*);
        void postorder_traverse(BSTNode*);
        void postorder_destruct(BSTNode*);
    
    public:
        BSTree();
        ~BSTree();
                
        void add(int);
        bool contains(int);
        void remove(int);

        void printPreOrder();
        void printInOrder();
        void printPostOrder();
        void printBreadthFirst();

};