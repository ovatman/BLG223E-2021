#include <iostream>
#include <queue>
#include "BinSTree.h"

using namespace std;


BinSTree::BinSTree(){
    this->root=NULL;    
}

BinSTree::BinSTree(list<int> v){
    if(v.size()==0){
        this->root=NULL;
        return;
    }

    int num_of_nodes = 1;
    queue<Node*> q;

    this->root=new Node(0);
    q.push(this->root);

    while(num_of_nodes<v.size()){
        Node* n = q.front();
        q.pop();
        n->set_left(new Node(0));
        num_of_nodes++;
        q.push(n->get_left());
        if(num_of_nodes==v.size())
            break;
        n->set_right(new Node(0));
        num_of_nodes++;
        q.push(n->get_right());
    }
    
    v.sort();
    this->inorder_construct(this->root,v);
}

void BinSTree::inorder_construct(Node* n, list<int>& v){
    if(n!=NULL){
        inorder_construct(n->get_left(),v);
        n->set_data(v.front());
        v.pop_front();
        inorder_construct(n->get_right(),v);
    }
}

Node* BinSTree::find_par(int data,Node*** child){
    
    if(this->root->get_data() == data)
        return NULL;
    
    Node* temp = root;
    while(temp!=NULL){
        if(temp->get_left()->get_data() == data ){
            (*child)=temp->get_left_addr();
            return temp;
        }
        if(temp->get_right()->get_data() == data){
            (*child)=temp->get_right_addr();
            return temp;
        }

        if(temp->get_data()>data)
            temp = temp->get_left();
        else if(temp->get_data()<data)
            temp = temp->get_right();
        else{ 
            return NULL;
        }
    }
    return NULL;

}
void BinSTree::remove(int data){

    if(this->root == NULL || !this->contains(data))
        return;

    Node** child;
    Node* par = find_par(data,&child);
    
    Node* left_child = (*child)->get_left();
    Node* right_child= (*child)->get_right();
    
    if(par == NULL){
        if(this->root->get_left()!=NULL){
            Node* t = this->root;
            this->root=this->root->get_left();
            Node* p = this->root;
            while(p->get_right()!=NULL)
                p=p->get_right();
            p->set_right(t->get_right());            
            delete t;
        }
        else{
            Node* t = this->root;
            this->root=this->root->get_right();
            delete t;
        }
    }
    else{
        if(*child != NULL){
            delete (*child);
            (*child) = left_child;
            Node* t = (*child);
            while(t->get_right()!=NULL)
                t=t->get_right();
            t->set_right(right_child);
        }
        else{ 
            delete (*child);
            (*child) = right_child;
        }
    }

}

bool BinSTree::contains(int data){
    if(this->root == NULL)
        return false;
    
    Node* temp = root;
    while(temp!=NULL){
        if(temp->get_data()>data)
            temp = temp->get_left();
        
        else if(temp->get_data()<data)
            temp = temp->get_right();
        
        else{ 
            return true;
        }
    }

    return false;

}


void BinSTree::add(int data){
    Node* n = new Node(data);

    if(this->root == NULL){
        root=n;
        return;
    }
    Node* temp = root;
    while(temp!=NULL){
        if(temp->get_data()>data){
            if(temp->get_left()==NULL){
                temp->set_left(n);
                return;
            }
            temp = temp->get_left();
        }
        else if(temp->get_data()<data){
            if(temp->get_right()==NULL){
                temp->set_right(n);
                return;
            }
            temp = temp->get_right();
        }
        else{ 
            delete n;
            return;
        }
    }

}

BinSTree::~BinSTree(){
    if(this->root != NULL)
        this->postorder_destruct(this->root);
    this->root=NULL;
}

void BinSTree::postorder_destruct(Node* n){
    if(n!=NULL){
        this->postorder_destruct(n->get_left());
        this->postorder_destruct(n->get_right());
        delete n;
    }
}

void BinSTree::preorder_traverse(Node* n){

    if(n!=NULL){
        cout<<n->get_data()<<" ";
        this->preorder_traverse(n->get_left());
        this->preorder_traverse(n->get_right());
    }

}

void BinSTree::inorder_traverse(Node* n){

    if(n!=NULL){
        this->inorder_traverse(n->get_left());
        cout<<n->get_data()<<" ";
        this->inorder_traverse(n->get_right());
    }

}

void BinSTree::postorder_traverse(Node* n){

    if(n!=NULL){
        this->postorder_traverse(n->get_left());
        this->postorder_traverse(n->get_right());
        cout<<n->get_data()<<" ";
    }

}

void BinSTree::printPreOrder(){
    this->preorder_traverse(this->root);
    cout<<endl;
}

void BinSTree::printInOrder(){
    this->inorder_traverse(this->root);
    cout<<endl;
}

void BinSTree::printPostOrder(){
    this->postorder_traverse(this->root);
    cout<<endl;
}


void BinSTree::printBreadthFirst(){
    Node* temp;
    queue<Node*> q;
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
