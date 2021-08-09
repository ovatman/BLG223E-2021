#include <iostream>
#include <queue>
#include "BSTree.h"



BSTNode* BSTree::recursive_build(vector<int> v){
    
    if(v.size()==0)
        return NULL;
    if(v.size()==1)
        return new BSTNode(v[0]);

    
    int mid = v.size()/2;
    vector<int> left(v.begin(),v.begin()+mid);
    vector<int> right(v.begin()+mid+1, v.end());

    BSTNode* n = new BSTNode(v[mid]);
    n->set_left(recursive_build(left));
    n->set_right(recursive_build(right));

    return n;
}


BSTree::BSTree(){
    this->root=NULL;    
}

BSTree::BSTree(vector<int> v){
    sort(v.begin(),v.end()); 
    this->root = this->recursive_build(v); 
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
