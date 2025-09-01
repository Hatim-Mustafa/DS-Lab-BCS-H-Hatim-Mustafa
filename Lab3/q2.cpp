#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* join (Node* one, Node* two) {
    Node* head;
    while(one->next != nullptr && two->next != nullptr) {
        if (one->value < two->value) {
            head = two;
            two = two->next;
        }
        else {
            head = one;
            one = one->next;
        }
    }
}