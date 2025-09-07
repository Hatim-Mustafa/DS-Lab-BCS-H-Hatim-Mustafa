#include <iostream>
using namespace std;

struct SNode {
    int value;
    SNode* next;
    SNode(int v) : value(v), next(nullptr) {}
};

struct DNode {
    int value;
    DNode* next;
    DNode* prev;
    DNode(int v) : value(v), next(nullptr), prev(nullptr) {}
};

void convertToCircular (SNode* head) {
    SNode* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head;
}

DNode* convertToDouble (const SNode* head) {
    DNode* start = new DNode(head->value);
    SNode* t = head->next; 
    DNode* temp = start;
    while (t != nullptr) {
        DNode* prev = temp;
        temp->next = new DNode(t->value);
        temp = temp->next;
        temp->prev = prev;
        t = t->next;
    }
    return start;
}

void freeList(SNode* head) {
    while (head != nullptr) {
        SNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void freeListD(DNode* head) {
    while (head != nullptr) {
        DNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main () {
    int n;
    SNode* list1 = new SNode(1);
    list1->next = new SNode(2);
    list1->next->next = new SNode(3);
    list1->next->next->next = new SNode(4);
    list1->next->next->next->next = new SNode(5);
    list1->next->next->next->next->next = new SNode(6);

    DNode* doublyhead = convertToDouble(list1);
    convertToCircular(list1);

    freeList(list1);
    freeListD(doublyhead);
}