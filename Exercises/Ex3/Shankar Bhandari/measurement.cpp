// Exercise 3 problem 1-2.

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;




class measurement {
private:
    double x, y;
    double r;
    //storing distance r as variable also
    double err; //same for error

public:
    measurement (double a, double b);

    static double M[2][2];

    void setM(double a[2][2]);
    double getx() const ;
    double gety() const;
    double distance() const;
    const double* getM() const;
    //I am assuming error=standard deviation. 
    double error() const;
    double significance();

};

measurement::measurement (double a, double b){
    x = a;
    y = b;
    r = sqrt(pow(x,2) + pow(y, 2));
}

double measurement::M[2][2] = {{0, 0}, {0, 0}};

void measurement::setM(double a[2][2]){
        M[0][0] = a[0][0];
        M[0][1] = a[0][1];
        M[1][0] = a[1][0];
        M[1][1] = a[1][1];
    }
double measurement::getx() const{
    return x;
}
double measurement::gety() const{
    return y;
}  
double measurement::distance() const{
    return r;
}
const double* measurement::getM() const{
    return &M[0][0];
}
//I am assuming error=standard deviation. 
double measurement::error() const{
    return sqrt(pow(x/r,2)*M[0][0] + pow(y/r,2)*M[1][1] + 2*x*y*(1/pow(r,2))*M[0][1]);
}
double measurement::significance(){
    return distance()/error();
}


