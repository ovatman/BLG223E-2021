#include <stdlib.h>
#include <iostream>
#include <queue>
#include "Tree.h"

using namespace std;

Tree::Tree(){

    this->root = new TreeNode('A');

    TreeNode* Rl = new TreeNode('B');
    TreeNode* Rr = new TreeNode('C');
    
    TreeNode* Rll = new TreeNode('D');
    TreeNode* Rlr = new TreeNode('E');
    TreeNode* Rrl = new TreeNode('F');
    TreeNode* Rrr = new TreeNode('G');


    TreeNode* Rlrl = new TreeNode('H');
    Rlr->set_left(Rlrl);
    TreeNode* Rrlr = new TreeNode('I');
    Rrl->set_right(Rrlr);
    TreeNode* Rrrl = new TreeNode('J');
    TreeNode* Rrrr = new TreeNode('K');
    Rrr->set_left(Rrrl);
    Rrr->set_right(Rrrr);

    this->root->set_left(Rl);
    this->root->set_right(Rr);

    this->root->get_left()->set_left(Rll);
    this->root->get_left()->set_right(Rlr);
    this->root->get_right()->set_left(Rrl);
    this->root->get_right()->set_right(Rrr);
    

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

void Tree::printTree(){
        cout<<root->get_data()<<"("
                          <<root->get_left()->get_data()
                            <<"["
                            <<root->get_left()->get_left()->get_data()
                                <<"("
                                <<","
                                <<")"
                            <<","
                            <<root->get_left()->get_right()->get_data()     
                                <<"("
                                <<root->get_left()->get_right()->get_left()->get_data()
                                <<","
                                <<")"
                            <<"]"
                          <<","
                          <<root->get_right()->get_data()
                            <<"["
                            <<root->get_right()->get_left()->get_data()  
                                <<"("
                                <<","
                                <<root->get_right()->get_left()->get_right()->get_data()
                                <<")"
                            <<","
                            <<root->get_right()->get_right()->get_data()
                                <<"("
                                <<root->get_right()->get_right()->get_left()->get_data()
                                <<","
                                <<root->get_right()->get_right()->get_right()->get_data()
                                <<")"
                            <<")"
                          <<")"<<endl;
}