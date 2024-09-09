#include "Queue.h"
#include <iostream>
using namespace std;
// Private method to resize the dynamic array
void Queue::resize(unsigned len) {
    if(len < INITIAL_CAPACITY) return; // Safety check

    int* newElements = new int[len];
    unsigned currentCount = elementCount;

    for(unsigned i = 0; i < currentCount; i++) {
        newElements[i] = elements[(frontindex + i) % capacity];
    }

    delete[] elements;
    elements = newElements;
    capacity = len;
    frontindex = 0;
    backindex = currentCount;
}

// Constructor
Queue::Queue() : 
    elementCount(0), 
    capacity(INITIAL_CAPACITY), 
    frontindex(0), 
    backindex(0) {
    elements = new int[capacity];
}

// Destructor
Queue::~Queue() {
    if ( elements ) {
        delete[] elements;
    }
}

// Inserts element x at the back
void Queue::enqueue(int x) {
    if(elementCount == capacity) { // If the queue is full, double the capacity
        resize(2 * capacity);
    }

    elements[backindex] = x;
    backindex = (backindex + 1) % capacity;
    elementCount++;
}

// Removes the frontmost element
void Queue::dequeue() {
    if(isEmpty()) {
        // Handle error, e.g., throw an exception.
        throw std::runtime_error("Queue is empty!");
    }

    frontindex = (frontindex + 1) % capacity;
    elementCount--;

    // Optional: Resize down if the number of elements is less than a quarter of the capacity
    if(elementCount < capacity / 4) {
        resize(capacity / 2);
    }
}

// Returns a copy of the frontmost element
int Queue::peek() const {
    if(isEmpty()) {
        // Handle error, e.g., throw an exception.
        cout<<"Queue is empty!";
    }
    return elements[frontindex];
}

// Returns true if and only if queue empty
bool Queue::isEmpty() const {
    return elementCount == 0;
}
