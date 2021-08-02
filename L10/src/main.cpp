#include <iostream>
#include <stdio.h>
#include <stack>
#include <set>
#include <unordered_set>

using namespace std;

void set_example();
void unordered_set_example();
void recursive_permutation(char*, int, int);

int main(int argc, char *argv[]){

    //set_example();
    
    //unordered_set_example();

    char *arr = new char[3];
	for(int i=0;i<3;i++)
		arr[i] = 65+i;

    recursive_permutation(arr, 0, 2);

    return EXIT_SUCCESS;
}

void set_example(){
	set<int> set1;
 
	for(int i=1;i<10;i++)
    	set1.insert(i*10);
	set1.insert(50); 
    set1.insert(10);
 
    for (const int i : set1)
        cout << i << " ";
    cout << endl;
 
    set<int> set2(set1.begin(), set1.end());
 
    for (const int i : set2)
        cout << i << " ";
    cout << endl;
 
 	set2.erase(80);
    set2.erase(set2.find(20), set2.find(60));
    for (const int i : set2)
        cout << i << " ";
    cout << endl;

}

void unordered_set_example(){
    unordered_set<string> set1 ; 

    set1.insert("tolga") ; 
    set1.insert("ovatman") ; 
    set1.insert("blg223") ; 
    set1.insert("123412") ; 
    set1.insert("data structures") ; 
      
    for (string s : set1)
        cout << s << " ";
    cout << endl;
}

void recursive_permutation(char* arr, int start, int end){
    int i;
    if (start == end) { 
  	    for (i = 0; i <= end; i++) 
       	    cout << arr[i] << " ";
     	cout << endl;
    }
    else { 
        for (i = start; i <= end; i++){
  	 	    std::swap(arr[start], arr[i]);
  	 	    recursive_permutation(arr, start + 1, end);
  	 	    std::swap(arr[start], arr[i]);
        }
  	}	
}
