#include "CircularLinkedList.h"

CircularLinkedList::CircularLinkedList() {
    size = 0;
    head = NULL;

}
CircularLinkedList::~CircularLinkedList() {
    if (head == NULL) {
        return;
    }
    if (size == 1) {
        delete head;
        return;
    }
    Node* tmp = head->next;
    do {
        tmp = tmp->next;
        delete tmp->prev;
    } while (tmp!=head);
    delete head;
    return;
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
    if (head == NULL) {
        return 0;
    }
    if (size == 1) {
        int pop_value = head->data;
        delete head;
        head = NULL;
        return pop_value;
    }
    Node* old_head = head;
    int pop_value = old_head->data;
    if (d == ClockWise) {
        head = old_head->next;
        head->prev = old_head->prev;
        old_head->prev->next = head;
    } else {
        head = old_head->prev;
        head->next = old_head->next;
        old_head->next->prev = head;
    }
    delete old_head;
    return pop_value;
}

int CircularLinkedList::peek() {
    return head->data;
}
void CircularLinkedList::rotate(unsigned int n, ClockDirection d) {
    if (head == NULL || size == 1) { // if list is empty or only one node
        return;
    }
    auto tmp = head;
    for (unsigned int i=0; i < n; i++) {
        if (d == ClockWise) {
            tmp = tmp->next;
        } else {
            tmp = tmp->prev;
        }
    }
    head = tmp;
    return;
}
ostream& operator<<(ostream& os, const CircularLinkedList& bi) {
    // Print in ClockWise direction
    Node* tmp = bi.head;
    int head_data = bi.head->data;
    bool first = true;
    do {
        if (tmp != NULL) {
            if (first) {
                os << head_data;
                first = false;
            } else {
                os << "," << tmp->data;
            }
        }
        tmp = tmp->next;
    } while (tmp!=bi.head);
    return os;
}
