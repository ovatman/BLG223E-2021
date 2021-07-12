#include <iostream>
#include <stdio.h>

using namespace std;

void pointer_examples();
void array_examples();
void pass_by_ref_examples();
void afunc(int&,int&);


int main(){

    //pointer_examples();
    //array_examples();
    pass_by_ref_examples();

    
    return EXIT_SUCCESS;
}

void pass_by_ref_examples(){

    int x = 3;
    int y = 5;

    afunc(x, y);

    cout << x <<" "<< y <<endl;
}


void afunc(int& a, int& b){
    int temp = b;
    b=a;
    a=temp;
    cout << a <<" "<<b<<endl;
}


void array_examples(){

    int arr[5] = {10,2,3,4,5}; 
    int* ptr = arr;

    // ptr[2] ==> *(ptr+2)

    cout << 2[ptr] << endl;

    for(int i=0;i<5;i++)
        cout<<ptr[i]<<endl;


    int* ptr2 = new int[10];

    for(int i=0;i<10;i++)
        ptr2[i] = 10-i;

    for(int i=0;i<10;i++)
        cout<<ptr2[i]<<" ";
    cout << endl;

    delete[] ptr2;

    int marr[2][3];

    cout<<marr<< " " << marr[0] << " "<< marr[1] <<endl;
    
    int** parr = new int*[2];
    parr[0] = new int[3];
    parr[1] = new int[3];

    cout<<parr<< " " << &parr[0] << " "<< &parr[1] <<endl;

    delete[] parr[0];
    delete[] parr[1];
    delete[] parr;
}

void pointer_examples(){

    int x=10;
    int* ptr;
    
    ptr = &x;
    (*ptr) = 15;

    cout << x << endl;
    cout << &x <<endl;

    cout << ptr <<endl;
    cout << *ptr <<endl;

    double *ptr2 = new double;

    cout<<ptr2<<endl;
    cout<<ptr2+1<<endl;
    *ptr2=100;
    cout<<*ptr2<<endl;
    cout<<(*ptr2)+1<<endl;

    

    delete ptr2;
}