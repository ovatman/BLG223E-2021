#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include "Coordinates.h"
using namespace std;


void heap_stl();
void priority_queues();
void comparator_examples();

int main(int argc, char *argv[]){

    //heap_stl();
    //priority_queues();
    comparator_examples();
   

    return EXIT_SUCCESS;
}

void comparator_examples(){
    vector<Coordinate> v;
    v.push_back(Coordinate(6,2));
    v.push_back(Coordinate(3,5));
    v.push_back(Coordinate(4,4));
    v.push_back(Coordinate(5,8));
    v.push_back(Coordinate(1,1));
    v.push_back(Coordinate(7,0));

    CoordinateComparator cc;

    //sort(v.begin(),v.end(),cc);
    //make_heap(v.begin(), v.end(),cc);

    sort(v.begin(),v.end(), [](Coordinate& c1, Coordinate& c2)->bool{
        return (c1.get_ycor()<c2.get_ycor());
    } 
    );

    make_heap(v.begin(), v.end(),[](Coordinate& c1, Coordinate& c2)->bool{
        return (c1.length()<c2.length());
    } 
    );
  
    for(auto c:v)
        c.print();
}

void priority_queues(){
    priority_queue<int,vector<int>,std::greater<int>> mypq;

    mypq.push(30);
    mypq.push(20);
    mypq.push(40);
    mypq.push(10);
    mypq.push(400);
    while(!mypq.empty()){
        cout<<mypq.top()<<" ";
        mypq.pop();
    }
    cout<<endl;
}

void heap_stl(){
    vector<int> v1 = {12, 35, 21, 10, 11, 8, 22, 23, 30};

    make_heap(v1.begin(), v1.end(), std::greater<>{});

    for(int i:v1)
        cout<<i<<" ";
    cout <<endl;

    v1.push_back(45);

    push_heap(v1.begin(), v1.end());
    pop_heap(v1.begin(), v1.end());
    v1.pop_back();

    //sort_heap(v1.begin(), v1.end());
    if(is_heap(v1.begin(), v1.end()))
        cout<<"This is a heap!!"<<endl;



}

