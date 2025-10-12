#include <iostream>
using namespace std;

#define size 10

class Stack {
    int top;

public:
    int a[size]; 

    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    void display();
};

bool Stack::push(int x)
{
    if (top >= (size - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}

int Stack::peek()
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}

void Stack::display() {
    cout << "Printing stack from last element to first\n";
    for (int i = top; i > -1; i--) {
        cout << a[i] << endl;
    }
}

int main () {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.peek() << endl;
    s.pop();
    s.display();
}