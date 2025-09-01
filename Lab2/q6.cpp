#include <iostream>
using namespace std;

class SafePointer {
private:
    int* ptr;  

public:
    SafePointer() : ptr(nullptr) {}

    void allocate() {
        if (ptr == nullptr)
            ptr = new int;
    }

    void setValue(int n) {
        if (ptr == nullptr) {
            allocate();
        }
        *ptr = n;
    }

    int getValue() const {
        if (ptr == nullptr) {
            cout << "Pointer not initialized!" << endl;
            return -1;
        }
        return *ptr;
    }

    void release() {
        delete ptr;
        ptr = nullptr;
    }

    ~SafePointer() {
        release();
    }
};

int main() {
    const int size = 5;
    SafePointer students[size];  

    int mark;
    for (int i = 0; i < size; i++) {
        cin >> mark;
        students[i].setValue(mark);
    }

    for (int i = 0; i < size; i++) {
        cout << "Student " << (i + 1) << ": " << students[i].getValue() << endl;
    }
}
