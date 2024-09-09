/*
 * BinaryHeap.h
 * 
 * Description: Binary Heap ADT class for a Priority Queue ADT class.
 *
 * Class Invariant: Always a ____min_____ Binary Heap.
 *                  
 *
 * Author: KZ
 * Last Modified: Nov. 2023
 */ 

#pragma once
#include "EmptyDataCollectionException.h"
#include "Event.h"

template <class ElementType>
class BinaryHeap {

private:
    static unsigned int const INITIAL_CAPACITY = 50; 
    ElementType *elements;

    int indexOfRoot = 0;    
    unsigned int elementCount = 0;
    unsigned int capacity = INITIAL_CAPACITY;

public:
   // Constructor
   BinaryHeap();

   // Destructor
   ~BinaryHeap();

   // If the binary heap is full, resize it
   bool resize();

   // Description: Returns true if this Binary Heap is empty, otherwise false.
   // Postcondition: This Binary Heap is unchanged by this operation.
   // Time Efficiency: O(1)
   bool isEmpty() const;

   /******* Start of Binary Heap  Public Interface *******/	

   // Description: Returns the number of elements in the Binary Heap.
   // Postcondition: The Binary Heap is unchanged by this operation.
   // Time Efficiency: O(1)
   unsigned int getElementCount() const;

   // Description: Inserts newElement into the Binary Heap. 
   //              It returns true if successful, otherwise false.      
   // Time Efficiency: O(log2 n)
   bool insert(ElementType & newElement);
      
   // Description: Removes (but does not return) the necessary element.
   // Precondition: This Binary Heap is not empty.
   // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
   // Time Efficiency: O(log2 n)
   void remove();

   // Description: Retrieves (but does not remove) the necessary element.
   // Precondition: This Binary Heap is not empty.
   // Postcondition: This Binary Heap is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
   // Time Efficiency: O(1) 
   ElementType & retrieve() const;
 
/******* End of Binary Heap Public Interface *******/
   
   // Print function, for testing purpose
   void printBinaryHeap();

   // Utility method
   // Description: Recursively put the array back into a ____________ Binary Heap.
   void reHeapDown(unsigned int indexOfRoot);

   // Utility method
   // Description: Recursively put the array back into a ____________ Binary Heap.
   void reHeapUp(unsigned int indexOfBottom);

};

#include "BinaryHeap.cpp"
