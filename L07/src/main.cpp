#include <iostream>
#include <stdio.h>
#include <list>
#include <vector>
#include <time.h>

#include "CircularLinkedList.h"

using namespace std;

void circular_linked_list();
void stl_list();

int main(int argc, char *argv[]){

    //circular_linked_list();
    stl_list();

    return EXIT_SUCCESS;
}

void stl_list(){

    list<int> a_list;
    //vector<int> a_list;

    clock_t start = clock();

    for(int i=0;i<500000;i++)
        a_list.insert(a_list.begin(),i);    //check how vector behaves n: 100000-500000
        //a_list.push_front(i);   // check how list and vector compares
    
    //checkut the following website for a more detialed comparison: https://baptiste-wicht.com/posts/2012/12/cpp-benchmark-vector-list-deque.html
    
    clock_t end = clock();

    cout<< (double)(end - start) * 1000 / CLOCKS_PER_SEC << " milliseconds" << endl;

}

void circular_linked_list(){
   
    CircularLinkedList* s=new CircularLinkedList();

    s->add_node(5);
    s->add_node(1);
    s->add_node(10);
    s->add_node(8);

    s->print_list();
    s->reverse_print_list();

    s->clear_list();

    s->add_node(5);
    s->add_node(1);
    s->add_node(10);
    s->add_node(8);

    if(s->contains(10))
        cout<<"s contains 10"<<endl;
        
    s->remove_node(5);
    s->remove_node(1);
    if(!s->contains(1))
        cout<<"s does not contain 1"<<endl;
    s->remove_node(10);

    s->print_list();
    s->reverse_print_list();

    s->remove_node(8);
    
    s->print_list();
    s->reverse_print_list();
    delete s;

}

