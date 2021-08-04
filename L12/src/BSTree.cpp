#include <iostream>
#include <queue>
#include "BSTree.h"

using namespace std;


BSTree::BSTree(){
    this->root=NULL;    
}


BSTree::~BSTree(){
    if(this->root != NULL)
        this->postorder_destruct(this->root);
    this->root=NULL;
}

void BSTree::add(int data){
    if(this->root == NULL)
        this->root=new BSTNode(data);  
    else this->root->add(data);
}

bool BSTree::contains(int data){
    return this->root->contains(data);
}

void BSTree::remove(int data){
    if(this->root->get_data()==data){
        if(this->root->get_left()!=NULL){
            BSTNode* t = this->root;
            this->root=this->root->get_left();
            BSTNode* p = this->root;
            while(p->get_right()!=NULL)
                p=p->get_right();
            p->set_right(t->get_right());            
            delete t;
        }
        else{
            BSTNode* t = this->root;
            this->root=this->root->get_right();
            delete t;
        }
    }
    else this->root->remove(data);
}

void BSTree::postorder_destruct(BSTNode* n){
    if(n!=NULL){
        this->postorder_destruct(n->get_left());
        this->postorder_destruct(n->get_right());
        delete n;
    }
}

void BSTree::preorder_traverse(BSTNode* n){

    if(n!=NULL){
        cout<<n->get_data()<<" ";
        this->preorder_traverse(n->get_left());
        this->preorder_traverse(n->get_right());
    }

}

void BSTree::inorder_traverse(BSTNode* n){

    if(n!=NULL){
        this->inorder_traverse(n->get_left());
        cout<<n->get_data()<<" ";
        this->inorder_traverse(n->get_right());
    }

}

void BSTree::postorder_traverse(BSTNode* n){

    if(n!=NULL){
        this->postorder_traverse(n->get_left());
        this->postorder_traverse(n->get_right());
        cout<<n->get_data()<<" ";
    }

}

void BSTree::printPreOrder(){
    this->preorder_traverse(this->root);
    cout<<endl;
}

void BSTree::printInOrder(){
    this->inorder_traverse(this->root);
    cout<<endl;
}

void BSTree::printPostOrder(){
    this->postorder_traverse(this->root);
    cout<<endl;
}


void BSTree::printBreadthFirst(){
    BSTNode* temp;
    queue<BSTNode*> q;
    if(this->root == NULL)
        return;

    q.push(this->root);

    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout<<temp->get_data()<<" ";
        if(temp->get_left()!=NULL)
            q.push(temp->get_left());
        
        if(temp->get_right()!=NULL)
            q.push(temp->get_right());
    }
    
    cout<<endl;
}
