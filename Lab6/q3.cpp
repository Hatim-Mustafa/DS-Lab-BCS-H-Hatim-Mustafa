#include <iostream>
using namespace std;

#define MAX_SIZE 50

class Queue {
    int front = -1, rear = -1;
    int arr[MAX_SIZE];

    public:

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full, cannot enqueue " << value << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = value;
    }

    int dequeue () {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue\n";
            return -1;
        }
        return arr[front++];
    }

    void display () {
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << endl;
        }
    }
};

int main () {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(31);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << endl;
    q.enqueue(41);
    q.display();
    cout << endl;
    cout << q.dequeue() << endl;
}