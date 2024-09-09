/*
 * MyADTTestDriver.cpp - Assignment 1
 * 
 * File Description: The test driver, to test MyADT class
 *
 * ***You cannot remove/change the code provided in this file.***
 *
 * Author: Kangyi Zhang
 * Modified on: Sept. 29, 2023
 */

#include <iostream>
#include <cctype>
#include <string>
#include "MyADT.h"  // Header file
#include "Profile.h"

using std::cout;
using std::endl;

int main() {

	// Test case 1:
	// Test default constructor and getElementCount()	
        // Create a List of size CAPACITY 0 using default constructor.
        cout << "***Create a default MyADT -> testing constructor MyADT()***" << endl;
        cout << "- Expected Result: empty List." << endl;
        MyADT * members =new MyADT();
        cout << "- The address of members('that' variable): " << &members << endl;
        cout << "- Pointer to the heap address: " << members << endl;
        cout << "- The numbers of members: " << members->getElementCount() << endl;
	
	// Test case 2:	
        // Create profile data, test insert()
        Profile memberB[] = {Profile("bob"), Profile("baby"), Profile("bag"), Profile("book"), Profile("berkey")};
	Profile memberZ[] = {Profile("zky"), Profile("zip"), Profile("zeng"), Profile("zhang"), Profile("zxcvb")};
	Profile memberK[] = {Profile("kate"), Profile("kss"), Profile("kang"), Profile("kfc"), Profile("koo")};
	
	// If insert failed, output error message
	cout << "***Testing insert(), insert 3 profile objects to MyADT***" << endl;
	for (unsigned int i = 0; i < 5; i++) 
	{
		if (!members->insert(memberB[i]))
			cout << "- Insert failed!" << endl;
		if (!members->insert(memberZ[i]))
			cout << "- Insert failed!" << endl;
		if (!members->insert(memberK[i]))
			cout << "- Insert failed!" << endl;
	}
	
	// Output the number of members after insertion
	cout << "- MyADT " << "has " << members->getElementCount() << " elements." << endl;
	
	// Test case 3:	
        // Test print()
        cout << "***Testing print()***\n" << "- Print MyADT members: " << endl;
        members->print();
        
        // Test case 4:	
        // Test remove()
        // Remove kss
        cout << "***Testing remove(), remove 'kfc' profile***" << endl;

        if (members->remove(Profile("kfc")))
		cout << "- Remove succeed!" << endl; 
		
	// Print the number and elements after remove
	cout << "- MyADT " << "has " << members->getElementCount() << " elements." << endl;
	cout << "- Print MyADT members: " << endl;
	members->print();
	
	// Remove zeng
	cout << "- Testing remove(), remove 'zeng' profile." << endl;

        if (members->remove(Profile("zeng")))
		cout << "- Remove succeed!" << endl; 
		
	// Print the number and elements after remove
	cout << "- MyADT " << "has " << members->getElementCount() << " elements." << endl;
	cout << "- Print MyADT members: " << endl;
	members->print();
		
	// Test case 5:	
        // Test search()
        cout << "***Testing search(), search 'kang' profile***" << endl;
	
	// Create a profile pointer
	Profile *toBeSearched = nullptr;
	toBeSearched = members->search(Profile("kang"));
	
	// Print message
        if (toBeSearched==nullptr)
		cout << "- Profile 'kang' not found!" << endl; 
	else
		cout << "- Profile 'kang' found!" << endl;
	
	// Test case 6:	
        // Test MyADT copy constructor
        cout << "***Testing copy constructor***" << endl;
        MyADT * membersCopy = new MyADT(*members);
        
        // Print the address of the pointer and elements
        cout << "- The address of membersCopy('that' variable): " << &membersCopy << endl;
        cout << "- Pointer to the heap address: " << membersCopy << endl;
        
        // Print the number and elements of the copy constructor membersCopy
        cout << "- Copied MyADT membersCopy " << "has " << membersCopy->getElementCount() << " elements." << endl;
	membersCopy->print();
		
	// Test case 7:	
        // Test removeAll()
      	cout << "***Testing removeAll()***" << endl;
        membersCopy->removeAll();
        // Print the number and elements of the copy constructor membersCopy
        cout << "- Copied MyADT membersCopy " << "has " << membersCopy->getElementCount() << " elements." << endl;
	membersCopy->print();
            
	// Test case 8:	
        // Test destructor
        cout << "***Testing destructor***" << endl;
        
        // Detete membersCopy
        cout << "- Delete membersCopy" << endl;
        delete membersCopy;
        membersCopy = nullptr;
        if (!membersCopy)
        	cout << "- Success, no memory leak!" << endl;
        
        // Detete members	
        cout << "- Delete members" << endl;
        delete members;
        members = nullptr;
        if (!members)
        	cout << "- Success, no memory leak!" << endl;
	
	return 0;
}
