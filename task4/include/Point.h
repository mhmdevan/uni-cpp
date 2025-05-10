#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
private:
    double x;
    double y;

public:
    // Constructors
    Point();                      // Default constructor
    Point(double x, double y);    // Parameterized constructor
    Point(const Point& other);    // Copy constructor

    // Assignment operator
    Point& operator=(const Point& other);

    // Getter methods
    double getX() const;
    double getY() const;

    // Setter methods
    void setX(double x);
    void setY(double y);
    void setPoint(double x, double y);

    // Member operator overloads for +=
    Point& operator+=(const Point& other);
    Point& operator+=(double value);

    // Member operator overload for binary +
    Point operator+(const Point& other) const;
    Point operator+(double value) const;

    // Friend operator overloads for -=
    friend Point& operator-=(Point& left, const Point& right);
    friend Point& operator-=(Point& left, double value);

    // Friend operator overloads for binary -
    friend Point operator-(const Point& left, const Point& right);
    friend Point operator-(const Point& left, double value);
    friend Point operator-(double value, const Point& right);

    // Print method
    void print() const;
    
    // Friend function for stream output
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
};

#endif // POINT_H 