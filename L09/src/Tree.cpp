#include <stdlib.h>
#include <iostream>
#include <queue>
#include "Tree.h"

using namespace std;

Tree::Tree(string preorder, string inorder){

    this->root = recursive_construct(preorder,inorder);

}

Tree::~Tree(){
    if(this->root != NULL)
        this->postorder_destruct(this->root);
    this->root=NULL;
}

void Tree::postorder_destruct(TreeNode* n){
    if(n!=NULL){
        this->postorder_destruct(n->get_left());
        this->postorder_destruct(n->get_right());
        delete n;
    }
}

TreeNode* Tree::recursive_construct(string preorder, string inorder){
    if(preorder.length()==0)
        return NULL;
    if(preorder.length()==1)
        return new TreeNode(preorder[0]);

    char root_data = preorder[0];
    string in_left = inorder.substr(0,inorder.find(root_data));
    string in_right = inorder.substr(inorder.find(root_data)+1);

    string pre_left="";
    string pre_right="";

    for(char c:preorder.substr(1)){
        int i = in_right.find(c);
        if(i>=0)
            break;
        pre_left += c;
    }
    if(pre_left.length()>0)
        pre_right = preorder.substr(preorder.find(pre_left[pre_left.length()-1])+1);
    else pre_right = preorder.substr(preorder.find(root_data)+1);

    TreeNode* local_root = new TreeNode(root_data);
    local_root->set_left(recursive_construct(pre_left, in_left));
    local_root->set_right(recursive_construct(pre_right, in_right));
    return local_root;
}

void Tree::preorder_traverse(TreeNode* n){

    if(n!=NULL){
        cout<<n->get_data();
        this->preorder_traverse(n->get_left());
        this->preorder_traverse(n->get_right());
    }

}

void Tree::inorder_traverse(TreeNode* n){

    if(n!=NULL){
        this->inorder_traverse(n->get_left());
        cout<<n->get_data();
        this->inorder_traverse(n->get_right());
    }

}

void Tree::postorder_traverse(TreeNode* n){

    if(n!=NULL){
        this->postorder_traverse(n->get_left());
        this->postorder_traverse(n->get_right());
        cout<<n->get_data();
    }

}

void Tree::printPreOrder(){
    this->preorder_traverse(this->root);
    cout<<endl;
}

void Tree::printInOrder(){
    this->inorder_traverse(this->root);
    cout<<endl;
}

void Tree::printPostOrder(){
    this->postorder_traverse(this->root);
    cout<<endl;
}


void Tree::printBreadthFirst(){
    TreeNode* temp;
    queue<TreeNode*> q;
    if(this->root == NULL)
        return;

    q.push(this->root);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout<<temp->get_data();
        if(temp->get_left()!=NULL)
            q.push(temp->get_left());
        
        if(temp->get_right()!=NULL)
            q.push(temp->get_right());
    }
    
    cout<<endl;
}
