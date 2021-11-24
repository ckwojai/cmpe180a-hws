#include <iostream>
#include "CircularLinkedList.h"
using std::cout;
using std::endl;

int main() {

    CircularLinkedList circularLinkedList;
    circularLinkedList.push(1, ClockDirection::ClockWise);
    circularLinkedList.push(2, ClockDirection::ClockWise);
    circularLinkedList.push(3, ClockDirection::ClockWise);
    circularLinkedList.push(4, ClockDirection::ClockWise);

    // should print 4,1,2,3 (any notation but this order)
    cout << circularLinkedList << "\n";

    circularLinkedList.pop(ClockDirection::ClockWise);
    // should print 1,2,3 (any notation but this order)
    cout << circularLinkedList << "\n";

    // should print 1
    cout<<circularLinkedList.peek() << "\n";

    circularLinkedList.rotate(1, CounterClockWise);
    cout << circularLinkedList << "\n";

    return 0;
}
