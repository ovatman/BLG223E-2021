#include "BSTNode.h"
#include <stdlib.h>


BSTNode::BSTNode(int data){
    this->data = data;
    this->left=NULL;
    this->right=NULL;
}

void BSTNode::add(int data){
    if(this->data>data)
        if(this->left != NULL)
            this->left->add(data);
        else this->left = new BSTNode(data);
    else if(this->data<data)
        if(this->right != NULL)
            this->right->add(data);
        else this->right = new BSTNode(data);
    else return;
}


bool BSTNode::contains(int data){
    if(this==NULL)
        return false;
        
    if(this->data>data)
        if(this->left != NULL)
            return this->left->contains(data);
        else return false;
    else if(this->data<data)
        if(this->right != NULL)
            return this->right->contains(data);
        else return false;
    else return true;
}


void BSTNode::remove(int data){
    if(this->data>data)
        if(this->left != NULL && this->left->data==data){
            BSTNode* left_child=this->left->left;
            BSTNode* right_child=this->left->right;
            delete this->left;
            if(left_child!=NULL){
                this->left=left_child;
                BSTNode* t = this->left;
                while(t->right!=NULL)
                    t=t->right;
                t->right=right_child;
            }
            else this->left=right_child;
        }
        else if(this->left != NULL)
            this->left->remove(data);
        else return;
    else if(this->data<data)
        if(this->right != NULL && this->left->data==data){
            BSTNode* left_child=this->right->left;
            BSTNode* right_child=this->right->right;
            delete this->right;
            if(left_child!=NULL){
                this->right=left_child;
                BSTNode* t = this->right;
                while(t->right!=NULL)
                    t=t->right;
                t->right=right_child;
            }
            else this->right=right_child;
        }
        else if(this->right != NULL)
            this->right->remove(data);
        else return;
}

void BSTNode::set_left(BSTNode* left){
    this->left = left;
}

void BSTNode::set_right(BSTNode* right){
    this->right = right;
}

void BSTNode::set_data(int data){
    this->data =data;
}

BSTNode* BSTNode::get_left(){
    return this->left;
}
BSTNode* BSTNode::get_right(){
    return this->right;
}

BSTNode** BSTNode::get_left_addr(){
    return &(this->left);
}
BSTNode** BSTNode::get_right_addr(){
    return &(this->right);
}
int BSTNode::get_data(){
    return this->data;
}