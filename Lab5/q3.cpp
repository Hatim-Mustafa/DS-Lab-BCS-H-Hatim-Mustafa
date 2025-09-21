#include <iostream>
using namespace std;

int sumTail(int n, int total) {
    if (n == 0) {
        return total;
    }
    return sumTail(n - 1, total + n);
}

int sumNonTail(int n, int total) {
    if (n == 0) {
        return 0;
    }
    return n + sumNonTail(n - 1, total);
}

int main () {
    cout << sumNonTail(5, 0) << endl;
    cout << sumTail(5, 0) << endl;
}

/**In tail recursion, each recursive call passes the updated total and does nothing after the call. 
Compiler can optimize this into a loop (tail call optimization, TCO). Stack depth remains constant hence very efficient.

In non-tail recursion, each call waits for the recursive result to return before finishing.
Stack frames pile up until the base case is reached. Needs O(n) stack space → risk of stack overflow for large n.**/