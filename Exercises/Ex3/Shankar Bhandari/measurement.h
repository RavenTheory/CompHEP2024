// measurement.h
#pragma once

class measurement {
private:
    double x, y;
    double r;
    double err; // Assuming error is standard deviation
    static double M[2][2]; // Matrix M

public:
    // Constructor
    measurement(double a, double b);

    // Set the matrix M
    void setM(double a[2][2]);

    // Getters for individual coordinates
    double getx() const;
    double gety() const;

    // Compute the distance from the origin
    double distance() const;

    // Get a pointer to the matrix M
    const double* getM() const;

    // Calculate the error (standard deviation)
    double error() const;

    // Compute the significance (distance divided by error)
    double significance();
};






