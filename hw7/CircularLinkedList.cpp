#include <iostream>
#include "CircularLinkedList.h"

CircularLinkedList::CircularLinkedList() {
    size = 0;
    head = NULL;

}
CircularLinkedList::~CircularLinkedList() {

}
void CircularLinkedList::push(int i, ClockDirection d) {
    if (head == NULL) {
        head = new Node();
        head->data = i;
        head->next = head;
        head->prev = head;
        size = 1;
    } else {
        if (d == Clockwise) {
            Node* newHead = new Node();
            Node* tmp = head->next;
            head->next = newHead;
            newHead->prev = head;
            newHead->next = tmp;
            head = newHead;
        } else {
            Node* newHead = new Node();
            Node* tmp = head->prev;
            head->prev = newHead;
            newHead->next = head;
            newHead->prev = tmp;
            head = newHead;
        }
        size++;
    }
}
int CircularLinkedList::pop(ClockDirection d) {

}
int CircularLinkedList::peek() {

}
void CircularLinkedList::rotate(unsigned int n, ClockDirection d) {

}
ostream& operator<<(ostream& os, const CircularLinkedList& bi) {
    // Print in ClockWise direction
    Node* tmp = bi.head;
    do {
        if (tmp != NULL) {
            os << tmp->data << ", ";
        }
        tmp = tmp->next;
    } while (tmp!=bi.head);
    os << std::endl;
    return os;
}
