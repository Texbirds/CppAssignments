#include <iostream>

class MySafeClass {
    int* data;

public:
    // Constructor
    MySafeClass(int value) {
        data = new int(value);
        std::cout << "Constructor: data = " << *data << std::endl;
    }

    // Destructor
    ~MySafeClass() {
        delete data;
        std::cout << "Destructor called\n";
    }

    // Copy constructor
    MySafeClass(const MySafeClass& other) {
        data = new int(*other.data); // deep copy
        std::cout << "Copy constructor\n";
    }

    // Copy assignment operator
    MySafeClass& operator=(const MySafeClass& other) {
        if (this != &other) {
            delete data;                     // clean up own resource
            data = new int(*other.data);     // deep copy
        }
        std::cout << "Copy assignment\n";
        return *this;
    }

    void print() const {
        std::cout << "Value = " << *data << std::endl;
    }
};

int main() {
    MySafeClass a(10);
    MySafeClass b = a; // copy constructor
    MySafeClass c(5);
    c = a;             // copy assignment
    b.print();
    c.print();
    return 0;
}