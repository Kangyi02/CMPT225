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

#include <iostream>
#include "BinaryHeap.h"  // Header file

using std::cout;
using std::endl;
  
// Constructors
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap()
{
    elements = new ElementType[capacity];
    indexOfRoot = 0;    
    elementCount = 0;
}

// Destructor
template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap()
{
    if (elements) 
    {
        delete[] elements;
    }
}

// Description: Returns true if this Binary Heap is empty, otherwise false.
// Postcondition: This Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool BinaryHeap<ElementType>::isEmpty() const
{
    return elementCount == 0;
}

// If the binary heap is full, resize it
template <class ElementType>
bool BinaryHeap<ElementType>::resize()
{
    capacity *= 2;
    ElementType* newElements = new ElementType[capacity];
    if (newElements==nullptr)
        return false;
    for(unsigned i = 0; i < capacity; i++) {
        newElements[i] = elements[i];
    }

    delete[] elements;
    elements = newElements;
    return true;
}

// Description: Returns the number of elements in the Binary Heap.
// Postcondition: The Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const
{
    return elementCount;
}

// Description: Inserts newElement into the Binary Heap. 
//              It returns true if successful, otherwise false.      
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType & newElement)
{
    bool result = false;
    if (elementCount == capacity)
    {
        if (!resize())
            return false;
    }

    elements[elementCount] = newElement;
    elementCount++;

    if (elementCount == 1) 
        return true;
    else 
    {
        reHeapUp(elementCount - 1);
        return true;
    }
    return result;
}

// Utility method
// Description: Recursively put the array back into a ____________ Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfBottom)
{
    unsigned int indexOfNewChild = indexOfBottom;

    // Find indices of children.
    unsigned int indexOfParent = (indexOfNewChild-1)/2;
    unsigned int indexOfLeft = indexOfNewChild % 2;

    // Base case: elements[indexOfRoot] is a leaf as it has no children
    // if (indexOfLeftChild > elementCount - 1) return;

    // If we need to swap, select the smallest child
    // If (elements[indexOfRoot] > elements[indexOfLeftChild])
    if ((elements[indexOfNewChild] <= elements[indexOfParent])) {
        indexOfNewChild = indexOfParent;
       // indexOfParent = elementCount
    }
    else if (indexOfLeft==0&&elements[indexOfNewChild-1] <= elements[indexOfNewChild]) { // Check if there is a right child, is it the smallest?
        // if (elements[indexOfMinChild] > elements[indexOfRightChild])
       // if (!(elements[indexOfMinChild] <= elements[indexOfRightChild]))
            indexOfNewChild = indexOfNewChild-1;
    }

    // Swap parent with smallest of children.
    if (indexOfNewChild != indexOfBottom) {

        ElementType temp = elements[indexOfNewChild];
        elements[indexOfNewChild] = elements[indexOfParent];
        elements[indexOfParent] = temp;

        // Recursively put the array back into a heap
        reHeapUp(indexOfNewChild);
    }
}

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {  

   if(elementCount == 0) 
      throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");

   elements[0] = elements[elementCount - 1];
   elementCount--;
   
   // No need to call reheapDown() is we have just removed the only element
   if ( elementCount > 0 ) 
      reHeapDown(0);
   
   return;   
}

// Description: Retrieves (but does not remove) the necessary element.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1) 
template <class ElementType>
ElementType & BinaryHeap<ElementType>::retrieve() const
{
    if (elementCount == 0) 
    {
        throw EmptyDataCollectionException("failed to retrieve");
    }
    else 
    {
        return elements[elementCount - 1];
    }
}
    
// Print function, for testing purpose
template <class ElementType>
void BinaryHeap<ElementType>::printBinaryHeap()
{
    for (int i = 0; i < elementCount; i++) 
    {
        cout << elements[i] << endl;
    }
}

// Utility method
// Description: Recursively put the array back into a ____________ Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {

   unsigned int indexOfMinChild = indexOfRoot;
   
   // Find indices of children.
   unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
   unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

   // Base case: elements[indexOfRoot] is a leaf as it has no children
   if (indexOfLeftChild > elementCount - 1) return;

   // If we need to swap, select the smallest child
   // If (elements[indexOfRoot] > elements[indexOfLeftChild])
   if ( ! (elements[indexOfRoot] <= elements[indexOfLeftChild]) )
      indexOfMinChild = indexOfLeftChild;

   // Check if there is a right child, is it the smallest?
   if (indexOfRightChild < elementCount) {
      // if (elements[indexOfMinChild] > elements[indexOfRightChild])
      if ( ! (elements[indexOfMinChild] <= elements[indexOfRightChild]) )
         indexOfMinChild = indexOfRightChild;
   }

   // Swap parent with smallest of children.
   if (indexOfMinChild != indexOfRoot) {
      
      ElementType temp = elements[indexOfRoot];
      elements[indexOfRoot] = elements[indexOfMinChild];
      elements[indexOfMinChild] = temp;
      
      // Recursively put the array back into a heap
      reHeapDown(indexOfMinChild);
   }
   return;
} 

