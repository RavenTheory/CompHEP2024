//main.cpp


#include <iostream>
#include "measurement.h" //header of the measurement library
using namespace std;



int main(){

    //Creating the clasS:
    measurement c(6.6, 3.4);

    double arr[2][2] = {{1.0, 0.5},{0.5, 0.9,}};

    c.setM(arr);

    cout << "The x coordinate is "  << c.getx() << endl ;
    cout << "The y coordinate is "  << c.gety() << endl ;
    cout << "The error matrix is:"<< endl ;
    const double* M_ptr = c.getM();
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << M_ptr[i * 2 + j] << " ";
        }
        cout << "\n";
    }

    cout << "The distance is "      << c.distance() << endl ;
    cout << "The error of distance is "  <<c.error() << endl ;
    cout << "The signigicane is" << c.getx() << endl ;

    cout << "If we get to this line then the library works" << endl;






    return 0;
}
