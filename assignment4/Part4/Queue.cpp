/*
 * Queue.cpp
 *
 * Description: Customer queue.
 *
 * Class Invariant: FIFO or LILO order.
 *                  
 *
 * Author: KZ
 * Last Modified: Nov. 2023
 */

#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

// Constructor
template <class ElementType>
Queue<ElementType>::Queue()
{
    front = nullptr;
    back = nullptr;
    elementCount = 0;
}

// Destructor
template <class ElementType>
Queue<ElementType>::~Queue()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

/******* Start of Queue Public Interface *******/
		
// Class Invariant:  FIFO or LILO order

// Description: Returns true if this Queue is empty, otherwise false.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const
{
    return elementCount == 0;
}
   
// Description: Inserts newElement at the "back" of this Queue 
//              (not necessarily the "back" of this Queue's data structure) 
//              and returns true if successful, otherwise false.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::enqueue(ElementType & newElement)
{
    Node<ElementType>* newNode = new Node<ElementType>(newElement);

	if (newNode == nullptr) 
    {
		return false;
	}
	if (isEmpty()) {
		front = newNode;
		back = newNode;
		elementCount++;
	}
	else {
	
		back->next = newNode;
		back = back->next;
		elementCount++;
	}
	return true;
}
   
// Description: Removes (but does not return) the element at the "front" of this Queue 
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.   
// Time Efficiency: O(1)
template <class ElementType>
void Queue<ElementType>::dequeue()
{
    if (isEmpty()) {
		throw EmptyDataCollectionException("failed to dequeue");
	}
	else {
		
		Node<ElementType>* temp = front;
        front = front->next;
        delete temp;
        elementCount--;
	
	}
} 

// Description: Returns (but does not remove) the element at the "front" of this Queue
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType& Queue<ElementType>::peek() const
{
    if (isEmpty())
    {
        throw EmptyDataCollectionException(" in peek(): the Queue is empty.");
    }
    return front->data;
}
 
/******* End of Queue Public Interface *******/

template <class ElementType>
void Queue<ElementType>::print() const 
{
    if (isEmpty()) 
    {
		throw EmptyDataCollectionException("failed to dequeue");
	}
	else 
    {
	    Node<ElementType>* temp = front;

	    while (temp != nullptr) 
        {
		    cout << temp->data<< " ";
		    temp = temp->next;
	    }
	    cout << endl;
	    delete temp;
        temp = nullptr;
    }
}