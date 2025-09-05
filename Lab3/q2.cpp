#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int v) : value(v), next(nullptr) {}
};

Node* join (Node* one, Node* two) {
    if (one == nullptr && two == nullptr) {
        return nullptr;
    }
    else if (one == nullptr) {
        return two;
    }
    else if (two == nullptr) {
        return one;
    }
    Node* head;
    if (one->value > two->value) {
        head = two;
        two = two->next;
    }
    else {
        head = one;
        one = one->next;
    }
    Node* temp = head;
    while(one != nullptr && two != nullptr) {
        if (one->value > two->value) {
            head->next = two;
            two = two->next;
        }
        else {
            head->next = one;
            one = one->next;
        }
        head = head->next;
    }
    if (one == nullptr) {
        head->next = two;
    }
    else {
        head->next = one;
    }
    return temp;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main () {
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    Node* merged = join(list1, list2);

    cout << "Merged List: ";
    printList(merged);

    freeList(merged);
}