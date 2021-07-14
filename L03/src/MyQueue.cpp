#include "MyQueue.h"

MyQueue::MyQueue(){
    front = 0;
    back = -1;
    num_of_items = 0;
}

int MyQueue::dequeue(){
    if(!this->isEmpty()){
        int element = arr[front];
        front = (front+1) % MAX_QUEUE_SIZE;
        num_of_items--;
        return element;
    }
    return -1;
}

bool MyQueue::enqueue(int element){
    if(!this->isFull()){
        back = (back+1) % MAX_QUEUE_SIZE;
        arr[back] = element;
        num_of_items++;
        return true;
    }
    return false;
}

int MyQueue::peek_front(){
    if(!this->isEmpty())
        return arr[front];
    return -1;
}

int MyQueue::peek_back(){
    if(!this->isEmpty())
        return arr[back];
    return -1;
}

bool MyQueue::isEmpty(){
    return num_of_items==0;
}

bool MyQueue::isFull(){
    return num_of_items==MAX_QUEUE_SIZE;
}

void MyQueue::clear(){
    front = 0;
    back = -1;
    num_of_items = 0;
}