#include <iostream>
using namespace std;

#define MAX_SIZE 10

class Queue{
    int front = -1, rear = -1;
    int arr[MAX_SIZE];

    public:
    bool isFull() {
        if ((rear+1)%MAX_SIZE == front) {
            return true;
        }
        return false;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full, cannot enqueue " << value << endl;
            return;
        }
        else if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear+1)%MAX_SIZE;
        }
        arr[rear] = value;
    }

    int dequeue () {
        int x;
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue\n";
            return -1;
        }
        else if (front == rear) {
            x = arr[front];
            front = rear = -1;
        }
        else {
            x = arr[front];
            front = (front+1)%MAX_SIZE;
        }
        return x;
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
    cout << q.dequeue() << endl;
}