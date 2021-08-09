#include <iostream>
#include <math.h>
using namespace std;

class Coordinate{

    private:
        int xCor;
        int yCor;
    public:
        Coordinate(int x,int y):xCor(x),yCor(y){};
        void print(){cout<<"("<<xCor<<","<<yCor<<") ";};
        int get_xcor(){return xCor;};
        int get_ycor(){return yCor;};
        double length(){return sqrt(pow(xCor,2)+pow(yCor,2));};
};

class CoordinateComparator{
    public:
        bool operator()(Coordinate& c1, Coordinate& c2){
            if(c1.get_ycor()<c2.get_ycor())
                return true;
            else return false;
        };

};