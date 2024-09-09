/*
 * Queue.h
 * 
 * Description: Customer queue.
 *
 * Class Invariant: FIFO or LILO order.
 *                  
 *
 * Author: KZ
 * Last Modified: Nov. 2023
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "EmptyDataCollectionException.h"
#include "Event.h"

template <class ElementType>
class Node {
public:

   // Public attributes
   ElementType & data;            // The data in the node
   Node * next = nullptr;   // Pointer to next node
	
   // Constructors (why no destructor?)
   Node();
   Node(ElementType & theData);
   Node(ElementType & theData, Node * theNextNode);

};

template <class ElementType>
Node<ElementType>::Node() { this->next = nullptr;}

template <class ElementType>
Node<ElementType>::Node(ElementType &theData) : data(theData) { this->next = nullptr;}

template <class ElementType>
Node<ElementType>::Node(ElementType &theData, Node * theNextNode) : data(theData), next(theNextNode) { }

template <class ElementType>
class Queue {

private:
   Node<ElementType> * front;
   Node<ElementType> * back;
   unsigned int elementCount = 0;
public:
   
   // Constructor
   Queue();

   // Destructor
   ~Queue();
   
   /******* Start of Queue Public Interface *******/
		
   // Class Invariant:  FIFO or LILO order

   // Description: Returns true if this Queue is empty, otherwise false.
   // Postcondition: This Queue is unchanged by this operation.
   // Time Efficiency: O(1)
   bool isEmpty() const;
   
   // Description: Inserts newElement at the "back" of this Queue 
   //              (not necessarily the "back" of this Queue's data structure) 
   //              and returns true if successful, otherwise false.
   // Time Efficiency: O(1)
   bool enqueue(ElementType & newElement);
   
   // Description: Removes (but does not return) the element at the "front" of this Queue 
   //              (not necessarily the "front" of this Queue's data structure).
   // Precondition: This Queue is not empty.
   // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
   // Time Efficiency: O(1)
   void dequeue(); 

   // Description: Returns (but does not remove) the element at the "front" of this Queue
   //              (not necessarily the "front" of this Queue's data structure).
   // Precondition: This Queue is not empty.
   // Postcondition: This Queue is unchanged by this operation.
   // Exception: Throws EmptyDataCollectionException if this Queue is empty.
   // Time Efficiency: O(1)
   ElementType & peek() const;
 
/******* End of Queue Public Interface *******/

   void print() const;
};
#endif