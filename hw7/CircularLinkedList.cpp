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
        Node* newHead = new Node();
	newHead->data = i;
        if (d == ClockWise) {
            Node* tmp = head->next;
            head->next = newHead;
            newHead->prev = head;
            newHead->next = tmp;
        } else {
            Node* tmp = head->prev;
            head->prev = newHead;
            newHead->next = head;
            newHead->prev = tmp;
        }
        head = newHead;
        size++;
    }
}
int CircularLinkedList::pop(ClockDirection d) {
  return 1;
}
int CircularLinkedList::peek() {
 return 2;
}
void CircularLinkedList::rotate(unsigned int n, ClockDirection d) {
 return;
}
ostream& operator<<(ostream& os, const CircularLinkedList& bi) {
    // Print in ClockWise direction
    Node* tmp = bi.head;
    bool first = true;
    do {
        if (tmp != NULL) {
	  if (first) {
            os << tmp->data;
	    first = false;
	  } else {
            os << "," << tmp->data;
	  }
        }
        tmp = tmp->next;
    } while (tmp!=bi.head);
    os << std::endl;
    return os;
}
