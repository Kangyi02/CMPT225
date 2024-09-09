/* 
 * BinaryHeap.cpp
 *
 * Description: _____ Min______ Binary Heap ADT class.
 *
 * Class Invariant:  Always a ____min_____ Binary Heap.
 * 
 * Author: 
 * Last Modification: Nov. 2023
 *
 */  

#include "PriorityQueue.h"  // Header file
#include "EmptyDataCollectionException.h"
#include <iostream>

using std::cout;
using std::endl;

// Constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue()
{
    binaryHeap = new BinaryHeap<ElementType>();
}

// Destructor
template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue()
{
    delete binaryHeap;
}

// Description: Returns the number of elements currently stored in the Priority Queue.
template <class ElementType>
unsigned int PriorityQueue<ElementType>::getElementCount() const
{
    return binaryHeap->getElementCount();
}

// Description: Returns true if this Priority Queue is empty, otherwise false.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const
{
    return binaryHeap->isEmpty();
}

// Description: Inserts newElement in this Priority Queue and 
//              returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType & newElement)
{
    return binaryHeap->insert(newElement);
}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void PriorityQueue<ElementType>::dequeue()
{
    if (isEmpty())
    {
        throw EmptyDataCollectionException("PQ dequeue failed because it is empty.");
    }
    else
        binaryHeap->remove();
}
   
// Description: Returns (but does not remove) the element with the next 
//              "highest" priority from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType & PriorityQueue<ElementType>::peek() const
{
    if (isEmpty())
    {
        throw EmptyDataCollectionException("PQ peek failed because it is empty.");
    }
    return binaryHeap->retrieve();
}
   
template <class ElementType>
void PriorityQueue<ElementType>::print()
{
    binaryHeap.print();
}