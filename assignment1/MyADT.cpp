/*
 * MyADT.cpp
 * 
 * Class Description: A linear data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - This is a value-oriented data collection: the elements are kept in 
 *                     ascending sort order of search key. 
 *                   - Its data structure is not expandable, i.e., resizable. 
 *
 * Author: AL, Kangyi Zhang
 * Last modified on: Sept.29 2023
 */


#include <iostream>
#include <cctype>
#include "MyADT.h"  // Header file
#include "Profile.h"

using std::cout;
using std::endl;

   
// Default constructor.
MyADT::MyADT() {

   /* Put your code here */
   
   // Dynamically allocate every element in elements
   // Set the number of every element in elementCount to 0
   for (unsigned int i=0; i<MAX_ALPHA; i++) 
   {
   	elements[i] = new Profile[MAX_ELEMENTS];
   	elementCount[i] = 0;
   }
	
}  // end default constructor


// Copy constructor - Covered in Lab 3
MyADT::MyADT(const MyADT& rhs) {

   /* Put your code here */
   
   // Dynamically allocate every element in elements

   for (unsigned int i=0; i<MAX_ALPHA; i++) 
   	elements[i] = new Profile[MAX_ELEMENTS];
	
   // Perform deep copy   
   // Set the number of every element in elementCount to 0
   for (unsigned int i=0; i<MAX_ALPHA; i++) 
   {
   	elementCount[i] = rhs.elementCount[i];
   	for (unsigned int j=0; j < rhs.elementCount[i]; j++) 
   		elements[i][j] = rhs.elements[i][j];
   }
   
}  // end copy constructor


// Destructor
// Description: Destruct this object, releasing heap-allocated memory.
MyADT::~MyADT() {

   /* Put your code here */
   
   // Delete every element in elements because it is in the heap
   for (unsigned int i=0; i<MAX_ALPHA; i++) 
   	delete[] elements[i];
   
} // end destructor

// Description: Returns the total element count of elements currently stored in MyADT.
unsigned int MyADT::getElementCount() const {

   /* Put your code here */
   
   // Set initial element count to 0
   unsigned int totalElementCount = 0;
   
   // Count the total number of elements
   for (unsigned int i=0; i<MAX_ALPHA; i++) 
   	totalElementCount += elementCount[i]; 
   
   // Return the total number of elements
   return totalElementCount;
   
}  // end getElementCount


// Description: Inserts an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
//                Returns "true" when the insertion is successfull,
//                otherwise "false".
bool MyADT::insert(const Profile& newElement) {

   /* Put your code here */
   
   // Get the first letter of newElement
   char firstLetter = newElement.getFirstLetter();
   
   // Get the index by first letter
   unsigned int index = firstLetter - 'A';
   
   // Check if the Friendsbook is full or not
   if (elementCount[index] >= MAX_ELEMENTS) 
   {
   	firstLetter = firstLetter + 32;
   	cout << "FriendsBook is full! Can't join with username initial = " << firstLetter << "." << endl;
   	return false;
   }
   
   // Insert newElement
   // Condition: newElement is not in the FriendsBook
   if ((this->search(newElement)==nullptr)) 
   {
   	elements[index][elementCount[index]]=newElement;
   	elementCount[index]++;
   	return true;
   }
   else 
   {
   	cout << "The username has existed, please change another one." << endl;
   	return false;
   }
   
}  // end insert


// Description: Search for target element. 
//              Returns a pointer to the element if found,
//              otherwise, returns nullptr.
Profile* MyADT::search(const Profile& target) {

   /* Put your code here */
   
   // Get the first letter of target
   char firstLetter = target.getFirstLetter();
   
   // Get the index by first letter
   unsigned int index = firstLetter - 'A';
   
   // Search for target
   for (unsigned int i=0; i<elementCount[index]; i++)
   {
	if (target.getUserName() ==elements[index][i].getUserName())
		return &elements[index][i];
   }   
   return nullptr;
   
}  // end of search

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.
//                Returns "true" when the removal is successfull,
//                otherwise "false".
bool MyADT::remove(const Profile& toBeRemoved) {

   /* Put your code here */

   // Get the first letter of target
   char firstLetter = toBeRemoved.getFirstLetter();
   
   // Get the index by first letter
   unsigned int index = firstLetter - 'A';
   
   // Remove the element
   for (unsigned int i=0; i<elementCount[index]; i++) 
   {
	if (toBeRemoved.getUserName() == elements[index][i].getUserName()) 
	{
		for (unsigned int j=i; j<elementCount[index]-1; j++) 
			elements[index][j] = elements[index][j+1];
		elementCount[index]--;
		return true;
	}	
   }
   return false;
   
}  // end remove


// Description: Remove all elements.
// Postcondition: MyADT goes back to its initialization state.
void MyADT::removeAll() {

   /* Put your code here */
   for (unsigned int i=0; i<MAX_ALPHA; i++) {
   	delete[] elements[i];
   	elements[i] = new Profile[MAX_ELEMENTS];
   	elementCount[i] = 0;
   }
   
}  // end removeAll


// Description: Prints all elements stored in MyADT by ascending order of search key.
// ***For Testing Purposes - Conceptualy, it is not part of this class.***
void MyADT::print() {

   /* Put your code here */
   
   // Print all elements
   for (unsigned int i=0; i<MAX_ALPHA; i++) 
	   for (unsigned int j=0; j<elementCount[i]; j++) 
		   if (elements[i][j].getUserName()!= "TBD")
			   cout << elements[i][j];
} // end of print 

//  End of implementation file
