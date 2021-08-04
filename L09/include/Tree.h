#include <string>
#include "TreeNode.h"

using namespace std;

class Tree{
    private:
        TreeNode* root;
        void preorder_traverse(TreeNode*);
        void inorder_traverse(TreeNode*);
        void postorder_traverse(TreeNode*);
        TreeNode* recursive_construct(string, string);
        void postorder_destruct(TreeNode*);

    public:
        Tree();
        Tree(string,string);
        ~Tree();
        void printPreOrder();
        void printInOrder();
        void printPostOrder();
        void printBreadthFirst();


};