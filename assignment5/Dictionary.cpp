/*
 * Dictionary.cpp
 * 
 * Class Description: Dictionary data collection ADT class.
 *                    The implementation of this class is based on 
 *                    the hashing strategy and the open addressing 
 *                    collision resolution strategy called linear probing hashing.             
 * Class Invariant: Each element stored in this Dictionary is unique (no duplications allowed).
 *
 * Author: AL
 * Date: Last modified: Nov. 2023
 */

// You can add more #include statements if you wish.

#include <iostream>
#include <cstring>
#include "Dictionary.h"  
#include "Profile.h"
#include "UnableToInsertException.h"
#include "ElementAlreadyExistsException.h"
#include "EmptyDataCollectionException.h"
#include "ElementDoesNotExistException.h"

using std::cout;
using std::endl;
using std::__cxx11::stoul;

// Constructor
Dictionary::Dictionary() {}

// Destructor
// Description: Destruct a Dictionary object, releasing heap-allocated memory.
Dictionary::~Dictionary() {
  // Release all heap memory
  if ( hashTable != nullptr ) { 
    for ( unsigned int i = 0; i < CAPACITY; i++ ) 
      if ( hashTable[i] != nullptr ) {      
        delete hashTable[i]; // Delete object of Profile class on heap
        hashTable[i] = nullptr;
      }
    delete [] hashTable;
    hashTable = nullptr;	
  }
}

// Description: Returns the total element count currently stored in Dictionary.
// Postcondition: Dictionary remains unchanged.
unsigned int Dictionary::getElementCount() const {
   return elementCount;
}

// Description: Returns the CAPACITY (size) of the Dictionary.
// Postcondition: Dictionary remains unchanged.
unsigned int Dictionary::getCapacity() const{
   return CAPACITY;
}

// Hash Function
// Description: Hashes the given indexingKey producing a "hash table index".
// Time Efficiency: For you to complete!
// Example of Time Efficiency: max(O(1),O(1)) = O(1) 
// Space Efficiency: For you to complete!
// Example of Space Efficiency: O(1)
unsigned int Dictionary::hashFunction( string indexingKey ) {

  // Implement your own hash function here!

  // Time Efficiency Analysis: Two statements done in sequence: max(O(1),O(1)) = O(1) 
  // Space Efficiency Analysis: Hash Function does not require another 
  //                            data structure (of size n) to operate: O(1)
  uint64_t indexingKeyInt = stoul(indexingKey);  // O(1)
  
  // "hashCode" is an intermediate result
  unsigned int hashCode = indexingKeyInt % CAPACITY; // O(1)
 
    const int PRIME = 19;
    for (char charAscii : indexingKey) {
        hashCode = (hashCode * PRIME + charAscii) % CAPACITY;
    }

    return hashCode;
}

// Description: Inserts an element into the Dictionary and increments "elementCount".
//              For this Assignment 5, you do not have to expand the hashTable when it is full. 
// Precondition: newElement must not already be in in the Dictionary.  
// Exception: Throws UnableToInsertException if we cannot insert newElement in the Dictionary.
//            For example, if the operator "new" fails, or Dictionary is full (temporary solution).
// Exception: Throws ElementAlreadyExistsException if newElement is already in the Dictionary. 
void Dictionary::insert( Profile * newElement )  {

   // Put your code here!
   if (elementCount == CAPACITY)
   {
      throw UnableToInsertException("Dictionary is full!");
   }

  if (hashTable == nullptr) {
    hashTable = new Profile * [CAPACITY];
  }

   if (!hashTable) 
   {
      throw UnableToInsertException("Unable to insert!");
   }

    unsigned int hashCode = hashFunction(newElement->getUserName());
    unsigned int indexing = hashCode;
    int i = 1;
    while (hashTable[hashCode] != nullptr) 
    {
        if (hashTable[hashCode]->getUserName() == newElement->getUserName()) {
            throw ElementAlreadyExistsException(newElement->getUserName());
        }
        hashCode = ((i * i) + indexing) % CAPACITY; 
        i++; 
    }

    hashTable[hashCode] = newElement;
    elementCount++;
   
   return;
}


// Description: Returns a pointer to the target element if found.
// Postcondition: Dictionary remains unchanged.
// Exception: Throws EmptyDataCollectionException if the Dictionary is empty.
// Exception: Throws ElementDoesNotExistException if target is not found in the Dictionary.
Profile * Dictionary::get( Profile & target )  {

   // Put your code here!
  if (elementCount == 0)
  {
    throw EmptyDataCollectionException("Empty dictionary!");
  }

  unsigned int hashCode = hashFunction(target.getUserName());
  if (hashTable[hashCode] == nullptr) 
  {
    throw ElementDoesNotExistException(target.getUserName());
  }

  while (hashTable[hashCode] != nullptr) 
  {
      if (hashTable[hashCode]->getUserName() == target.getUserName()) {
          return &target;
      }
      hashCode = (hashCode + 1) % CAPACITY;      
  }
  throw ElementDoesNotExistException(target.getUserName());
   return nullptr; 
}
   
// Description: Prints all elements stored in the Dictionary (unsorted).
// Postcondition: Dictionary remains unchanged.
// Exception: Throws EmptyDataCollectionException if the Dictionary is empty.
void Dictionary::printDictionary()  const {
  if ( elementCount == 0 ) 
     throw EmptyDataCollectionException("In printDictionary(): hashTable is empty.");

  cout << endl << "Printing the Dictionary with " << this->elementCount << " elements: " << endl;
  for (unsigned int index = 0; index < CAPACITY; index++) {
    if ( hashTable[index] != nullptr ) 
		cout << "HashTable[" << index << "] = " << *(hashTable[index]) << endl; 
  }   
  return;
}
