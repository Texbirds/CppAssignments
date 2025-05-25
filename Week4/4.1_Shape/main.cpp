#include <iostream>
#include "Shape.h"

int main() {
    using std::cout;
    using std::endl;

    Shape shape1;
    cout << "Default constructor:" << endl;
    cout << "Side1: " << shape1.getSide1() << ", Side2: " << shape1.getSide2()
        << ", Side3: " << shape1.getSide3() << endl;
    cout << "Color: " << shape1.getColor() << ", Filled: " << std::boolalpha << shape1.isFilled() << endl;
    cout << "Perimeter: " << shape1.getPerimeter() << ", Area: " << shape1.getArea() << endl << endl;

    Shape shape2(3.0, 4.0, 5.0);
    cout << "Constructor with sides:" << endl;
    cout << "Side1: " << shape2.getSide1() << ", Side2: " << shape2.getSide2()
        << ", Side3: " << shape2.getSide3() << endl;
    cout << "Perimeter: " << shape2.getPerimeter() << ", Area: " << shape2.getArea() << endl << endl;

    Shape shape3("blue", true);
    cout << "Constructor with color and filled:" << endl;
    cout << "Color: " << shape3.getColor() << ", Filled: " << std::boolalpha << shape3.isFilled() << endl;
    cout << "Side1: " << shape3.getSide1() << ", Side2: " << shape3.getSide2()
        << ", Side3: " << shape3.getSide3() << endl;
    cout << "Perimeter: " << shape3.getPerimeter() << ", Area: " << shape3.getArea() << endl << endl;

    shape3.setColor("green");
    shape3.setFilled(false);
    cout << "After changing color and filled status:" << endl;
    cout << "Color: " << shape3.getColor() << ", Filled: " << std::boolalpha << shape3.isFilled() << endl << endl;

    return 0;
}
