#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

int main () {
    int n;
    Node* list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);
    list1->next->next->next = new Node(4);
    list1->next->next->next->next = new Node(5);
    list1->next->next->next->next->next = new Node(6);
    list1->next->next->next->next->next->next = list1;

    cin >> n;

    Node* temp = list1;
    Node* prev;

    while (temp->next != temp) {
        for (int i = 0; i < n-1; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
        temp = prev->next;
    }
    cout << temp->value << endl;
    delete temp;
}