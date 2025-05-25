#include "Shape.h"
#include <cmath>
using namespace std;

Shape::Shape()
    : color("white"), filled(false), side1(1.0), side2(1.0), side3(1.0) {
}

Shape::Shape(double side1, double side2, double side3) :
	color("white"), filled(false), side1(side1), side2(side2), side3(side3) {
}

Shape::Shape(const std::string& color, bool filled) :
    color(color), filled(filled) {
}

std::string Shape::getColor() const {
    return color;
}

void Shape::setColor(const std::string& color) {
    this->color = color;
}

bool Shape::isFilled() const {
    return filled;
}

void Shape::setFilled(bool filled) {
    this->filled = filled;
}

std::string Shape::toString() const {
    return "Shape";
}

double Shape::getSide1() const {
	return side1;
}

double Shape::getSide2() const {
	return side2;
}

double Shape::getSide3() const {
	return side3;
}

double Shape::getArea() const {
    double s = (side1 + side2 + side3) / 2.0;
    double area = std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    return area;
}

double Shape::getPerimeter() const {
	return side1 + side2 + side3;
}
