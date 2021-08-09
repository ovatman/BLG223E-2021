#include <vector>
#include <algorithm>
#include "BSTNode.h"

using namespace std;

class BSTree{
    private:
        BSTNode* root;
        void preorder_traverse(BSTNode*);
        void inorder_traverse(BSTNode*);
        void postorder_traverse(BSTNode*);
        void postorder_destruct(BSTNode*);
        BSTNode* recursive_build(vector<int>);
    
    public:
        BSTree(vector<int> v);
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