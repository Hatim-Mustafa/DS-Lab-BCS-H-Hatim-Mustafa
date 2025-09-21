#include <iostream>
using namespace std;

void print (int n) {
    if (n== 1) {
        cout << 1 << endl;
    }
    else {
        cout << n << endl;
        print(n-1);
    }
}

void functionB (int n);

void functionA (int n) {
    if (n == 1) {
        cout << n << endl;
    }
    else {
        cout << n << endl;
        functionB(n-1);
    }
}

void functionB (int n) {
    if (n == 1) {
        cout << n << endl;
    }
    else {
        cout << n << endl;
        functionA(n-1);
    }
}

int main () {
    int n = 15;

    functionA(n);
}