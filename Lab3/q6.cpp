#include <iostream>
using namespace std;

struct SNode {
    int value;
    SNode* next;
    SNode(int v) : value(v), next(nullptr) {}
};

struct MNode {
    int value;
    MNode* next;
    MNode* child;
    MNode(int v) : value(v), next(nullptr), child(nullptr) {}
};

void convert (MNode* head, SNode*& start) {
    while (head != nullptr) {
        start->next = new SNode(head->value);
        start = start->next;
        if (head->child != nullptr) {
            convert(head->child, start);
        }
        head = head->next;
    }
}

int main() {
    MNode* head = new MNode(1);
    head->next = new MNode(2);
    head->next->next = new MNode(3);

    head->next->child = new MNode(4);
    head->next->child->next = new MNode(5);

    SNode* flat = new SNode(-1);
    SNode* tail = flat;

    convert(head, tail);

    SNode* temp = flat->next;
    delete flat;
    flat = temp;
    while (temp != nullptr) {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}
