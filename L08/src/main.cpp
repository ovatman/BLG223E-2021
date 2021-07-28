#include <iostream>
#include <stdio.h>
#include <stack>

#define RIGHT   1
#define LEFT    2
#define UP      3
#define DOWN    4

#define MAZE_HOR_SIZE    8
#define MAZE_VER_SIZE    8
#define WALL   '#'
#define PATH   ' '
#define GONE   'o'

using namespace std;

void recursion_examples();
int factorial(int);
int power(int,int);
int fibonacci(int);
int iter_sum(int*, int);
int recur_sum(int*, int, int);

void recursive_hanoi(int disks);
void recursive_maze();
void hanoi_move(stack<char> pegs[3], int, int, int, int);
void recursive_maze();
bool find_path_recursive(char maze[MAZE_VER_SIZE][MAZE_HOR_SIZE], int , int , int , int , int );
void print_maze(char maze[MAZE_VER_SIZE][MAZE_HOR_SIZE]);

int main(int argc, char *argv[]){

    recursion_examples();
    return EXIT_SUCCESS;
}

void recursion_examples(){

    int arr[10]={1,2,3,4,5,6,7,8,9,10};

    //cout<<factorial(5)<<endl;
    //cout<<power(3,5)<<endl;
    //cout<<fibonacci(5)<<endl;
    //cout<<iter_sum(arr,10)<<endl;
    //cout<<recur_sum(arr,0,10)<<endl;

	//recursive_hanoi(10);
	recursive_maze();
}

void recursive_hanoi(int disks){
	int source = 0;
	int dest = 2;
	int temp = 1;

	stack<char> pegs[3];

	for (int i = 0; i < disks; i++)
		pegs[0].push(64 + disks - i);

	hanoi_move(pegs, disks, source, dest, temp);
}


void hanoi_move(stack<char> pegs[3], int disks, int source, int dest, int temp){
	if (disks >= 1) {
		hanoi_move(pegs, disks - 1, source, temp, dest);
        cout << "Disk "<< pegs[source].top() << " moved from disk "<< source << " to disk "<<dest <<endl;
		pegs[dest].push(pegs[source].top());
        pegs[source].pop();
		hanoi_move(pegs, disks - 1, temp, dest, source);
	}
}


void recursive_maze(){
	
	char maze[MAZE_VER_SIZE][MAZE_HOR_SIZE] = {{'#','#',' ','#'},
				      						   {' ',' ',' ',' '},
										       {'#',' ','#','#'},
				    						   {'#','#','#','#'},
		};
	int enter_y=1;
	int enter_x=0;
	int exit_y=1;
	int exit_x=3;
	

	/*char maze[MAZE_VER_SIZE][MAZE_HOR_SIZE] = {{'#','#','#','#','#','#','#','#'},
				      						   {' ',' ','#','#','#',' ',' ',' '},
										       {'#',' ','#','#','#',' ','#','#'},
				    						   {'#',' ',' ',' ',' ',' ',' ','#'},
				       						   {'#',' ','#',' ','#','#',' ','#'},
				      						   {'#',' ','#','#',' ','#',' ','#'},
				     						   {'#',' ',' ','#',' ',' ',' ','#'},
				    						   {'#','#','#','#','#','#','#','#'}
		};
	int enter_y=1;
	int enter_x=0;
	int exit_y=1;
	int exit_x=7;*/

	if (find_path_recursive(maze, enter_y, enter_x, exit_y, exit_x, LEFT))
		cout << "!!!! PATH found !!!!" << endl << endl;

	print_maze(maze);

}

bool find_path_recursive(char maze[MAZE_VER_SIZE][MAZE_HOR_SIZE], int cur_y, int cur_x, int exit_y, int exit_x, int camefrom) {	
	maze[cur_y][cur_x] = GONE;

	if (cur_x == exit_x && cur_y == exit_y)
		return true;

	print_maze(maze);	

	if ( cur_x > 0 && maze[cur_y][cur_x - 1] != WALL && camefrom != LEFT ) 
		if ( find_path_recursive(maze, cur_y, cur_x - 1, exit_y, exit_x, RIGHT) ) 
			return true;

	if ( cur_y < MAZE_VER_SIZE-1 && maze[cur_y + 1][cur_x] != WALL && camefrom != DOWN ) 
		if ( find_path_recursive(maze, cur_y + 1, cur_x, exit_y, exit_x, UP) ) 
			return true;

	if ( cur_y > 0 && maze[cur_y - 1][cur_x] != WALL && camefrom != UP ) 
		if ( find_path_recursive(maze, cur_y - 1, cur_x, exit_y, exit_x, DOWN)) 
			return true;

	if ( cur_x < MAZE_HOR_SIZE-1 && maze[cur_y][cur_x + 1] != WALL && camefrom != RIGHT) 
		if ( find_path_recursive(maze, cur_y, cur_x + 1, exit_y, exit_x, LEFT) ) 	
			return true;

	maze[cur_y][cur_x] = PATH; // delete incorrect paths
	//print_maze(maze); // display the return from the incorrect paths as well

	return false;
}

void print_maze(char maze[MAZE_VER_SIZE][MAZE_HOR_SIZE]){
    for (int i = 0; i < MAZE_VER_SIZE; i++) {
        for (int j = 0; j < MAZE_HOR_SIZE; j++)
            cout << maze[i][j];
        cout << endl;
    }
    cout << endl << endl;
}

int factorial(int n){
    if(n<=0)
        return 1;
    
    return n*factorial(n-1);
}


int power(int base,int exp){
    if(exp<=0)
        return 1;
    
    return base*power(base, exp-1);
}


int fibonacci(int n){
    if(n<=1)
        return 1;
    
    return fibonacci(n-1)+fibonacci(n-2);
}

int iter_sum(int* arr, int len){

    int sum=0;

    for(int i=0;i<len;i++)
        sum+=arr[i];
    
    return sum;
}

int recur_sum(int* arr, int cur,int len){

    if(cur==len)
        return 0;
    
    return arr[cur]+recur_sum(arr,cur+1,len);
}