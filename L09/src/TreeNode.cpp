#include <stdlib.h>
#include "TreeNode.h"

TreeNode::TreeNode(char data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}


void TreeNode::set_data(char data){
    this->data=data;
}

char TreeNode::get_data(){
    return this->data;
}
void TreeNode::set_left(TreeNode* left){
    this->left=left;
}
TreeNode* TreeNode::get_left(){
    return this->left;
}
void TreeNode::set_right(TreeNode* right){
    this->right=right;
}
TreeNode* TreeNode::get_right(){
    return this->right;
}
        