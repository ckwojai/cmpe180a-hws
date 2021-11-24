#include <iostream>

using std::ostream;

enum ClockDirection {ClockWise, CounterClockWise};

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class CircularLinkedList {
    public:
        CircularLinkedList();
        ~CircularLinkedList();
        void push(int i, ClockDirection d);
        int pop(ClockDirection d);
        int peek();
        void rotate(unsigned int n, ClockDirection d);
        friend ostream& operator<<(ostream& os, const CircularLinkedList& bi);
    private:
        Node* head;
        int size;
};
