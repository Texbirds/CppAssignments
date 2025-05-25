#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
    double side1, side2, side3;
    Shape();
    Shape(double side1, double side2, double side3);
    Shape(const std::string& color, bool filled);
    std::string getColor() const;
    void setColor(const std::string& color);
    bool isFilled() const;
    void setFilled(bool filled);
    std::string toString() const;
    double getSide1() const;
    double getSide2() const;
    double getSide3() const;
    double getArea() const;
	double getPerimeter() const;

private:
    std::string color;
    bool filled;
};

#endif
