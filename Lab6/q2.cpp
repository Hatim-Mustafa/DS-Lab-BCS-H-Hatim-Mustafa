#include <iostream>
using namespace std;

struct Node {
    string value;
    Node* next;
    Node(string x): value(x), next(nullptr) {}
    Node(): value(""), next(nullptr) {}
};

class Stack {
    Node* top;

public: 

    Stack() { top = nullptr; }
    bool push(string x);
    string pop();
    string peek();
    void display();
};

bool Stack::push(string x)
{
    if (top == nullptr) {
        top = new Node(x);
        if (!top) {
            cout << "Heap Overflow\n";
            return false;
        }
        return true;
    }
    else {
        Node* temp = new Node(x);
        if (!temp) {
            cout << "Heap Overflow\n";
            return false;
        }
        temp->next = top;
        top = temp;
        return true;
    }
}

string Stack::pop()
{
    if (!top) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        string x = top->value;
        Node* temp = top;
        top = top->next;
        delete temp;
        return x;
    }
}

string Stack::peek()
{
    if (!top) {
        cout << "No Browser History";
        return 0;
    }
    else {
        return top->value;
    }
}

void Stack::display() {
    cout << "Showing browser history\n";
    Node* temp = top;
    while (temp) {
        cout << temp->value << endl;
        temp = temp->next;
    }
}

int main () {
    Stack s;
    s.push("www.facebook.com");
    s.push("www.fast.com");
    s.push("www.netflix.com");
    cout << s.peek() << endl;
    s.pop();
    s.display();
}