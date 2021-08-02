#include "TreeNode.h"
class Tree{
    private:
        TreeNode* root;
        void preorder_traverse(TreeNode*);
        void inorder_traverse(TreeNode*);
        void postorder_traverse(TreeNode*);

    public:
        Tree();
        void printTree();
        void printPreOrder();
        void printInOrder();
        void printPostOrder();
        void printBreadthFirst();


};