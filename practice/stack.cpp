#include <iostream>
using namespace std;

#define size 10

class Stack {
    char top;

public:
    char a[size]; 

    Stack() { top = 0; }
    bool push(char x);
    char pop();
    char peek();
    void display();

    bool isEmpty() {
        if (top == 0) {
            return true;
        }
        return false;
    }
};

bool Stack::push(char x)
{
    if (top >= (size)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[top++] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

char Stack::pop()
{
    if (top <= 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[--top];
        return x;
    }
}

char Stack::peek()
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
    // cout << "Printing stack from last element to first\n";
    cout << top << endl;
    for (int i = top-1; i > -1; i--) {
        cout << a[i];
    }
}

int main () {
    // Stack s;
    // Stack t;
    // Stack r;
    // string num;
    // cin >> num;
    // for (int i = 0; i < num.length(); i++) {
    //     s.push((int)num[i]-48);
    // }
    // cin >> num;
    // for (int i = 0; i < num.length(); i++) {
    //     t.push((int)num[i]-48);
    // }
    // int n1, n2;
    // string n = "";
    // int e = 0;
    // while (!s.isEmpty() || !t.isEmpty()) {
    //     if (!s.isEmpty()) {
    //         n1 = s.pop();
    //     }
    //     else {
    //         n1 = 0;
    //     }
    //     if (!t.isEmpty()) {
    //         n2 = t.pop();
    //     }
    //     else {
    //         n2 = 0;
    //     }      
    //     if (n1 + n2 + e > 9) {
    //         int n3 = ((n1+n2+e)%10);
    //         r.push(n3);
    //         e = 1;
    //     }
    //     else {
    //         int n3 = ((n1+n2+e));
    //         r.push(n3);
    //         e = 0;
    //     }
    // }
    // r.display();

    string st = "maulajatt";
    bool seen[256] = {false};
    Stack s, t;

    for (int i = 0; i < st.length(); i++) {
        char c = st[i];
        if (seen[c]) continue; // skip duplicates
        seen[c] = true;

        // keep t sorted
        while (!t.isEmpty() && t.peek() < c) {
            s.push(t.pop());
        }
        t.push(c);
        while (!s.isEmpty()) {
            t.push(s.pop());
        }
    }

    t.display();
}