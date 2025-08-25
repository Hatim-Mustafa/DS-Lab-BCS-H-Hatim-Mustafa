#include <iostream>
using namespace std;

class Box {
private:
    int* value;

public:
    Box(int val = 0) {
        value = new int(val);
    }

    Box(Box& other) {
        value = new int(*other.value);
    }

    Box& operator=(const Box& other) {
        if (this != &other) { 
            delete value;
            value = new int(*other.value);
        }
        return *this;
    }

    ~Box() {
        delete value;
    }

    void setValue(int val) {
        *value = val;
    }

    int getValue() {
        return *value;
    }
};

int main() {
    cout << "Creating Box A with value 10\n";
    Box a(10);

    cout << "\nCreating Box B as a copy of A (Copy Constructor)\n";
    Box b = a; 

    cout << "\nChanging value of B to 20\n";
    b.setValue(20);

    cout << "\nValue in A: " << a.getValue() << endl;  
    cout << "Value in B: " << b.getValue() << endl; 

    cout << "\nCreating Box C and assigning A to C (Copy Assignment)\n";
    Box c;
    c = a; 

    cout << "\nChanging value of C to 30\n";
    c.setValue(30);

    cout << "\nValue in A: " << a.getValue() << endl; 
    cout << "Value in C: " << c.getValue() << endl;    
}