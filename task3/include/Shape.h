#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
#include <cmath>

// Color enumeration
enum Color { RED, GREEN, BLUE };

// Base abstract class
class Shape {
protected:
    Color color;

public:
    // Constructors and destructor
    Shape();
    Shape(Color color);
    Shape(const Shape& other);
    virtual ~Shape();

    // Getters and setters
    Color getColor() const;
    void setColor(Color color);

    // Virtual functions
    virtual double calculate_perimeter() const = 0;  // Pure virtual function
    virtual double calculate_area() const = 0;       // Pure virtual function
    virtual void describe() const;                   // Virtual function
    virtual void inflate(double amount) = 0;         // Pure virtual function
};

// Rectangle class derived from Shape
class Rectangle : public Shape {
private:
    double left;
    double bottom;
    double right;
    double top;

    // Helper method to ensure left < right and bottom < top
    void normalize();

public:
    // Constructors and destructor
    Rectangle();
    Rectangle(double left, double bottom, double right, double top, Color color = RED);
    Rectangle(const Rectangle& other);
    ~Rectangle();

    // Getters
    double getLeft() const;
    double getBottom() const;
    double getRight() const;
    double getTop() const;
    double getWidth() const;
    double getHeight() const;
    double getCenterX() const;
    double getCenterY() const;
    double getDiagonal() const;

    // Setters
    void setLeft(double left);
    void setBottom(double bottom);
    void setRight(double right);
    void setTop(double top);
    void setDimensions(double left, double bottom, double right, double top);

    // Overridden virtual methods
    virtual double calculate_perimeter() const override;
    virtual double calculate_area() const override;
    virtual void describe() const override;
    virtual void inflate(double amount) override;
};

// Circle class derived from Shape
class Circle : public Shape {
private:
    double centerX;
    double centerY;
    double radius;

public:
    // Constructors and destructor
    Circle();
    Circle(double centerX, double centerY, double radius, Color color = RED);
    Circle(const Rectangle& rect);  // Special constructor from Rectangle
    Circle(const Circle& other);
    ~Circle();

    // Getters
    double getCenterX() const;
    double getCenterY() const;
    double getRadius() const;

    // Setters
    void setCenterX(double x);
    void setCenterY(double y);
    void setRadius(double radius);
    void setDimensions(double centerX, double centerY, double radius);

    // Overridden virtual methods
    virtual double calculate_perimeter() const override;
    virtual double calculate_area() const override;
    virtual void describe() const override;
    virtual void inflate(double amount) override;
};

// Get the name of a color as a string
std::string colorToString(Color color);

#endif // SHAPE_H 