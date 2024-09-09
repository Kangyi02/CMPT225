/*
 * FriendsBook.cpp - Assignment 1
 * 
 * Class Description: Social network application (partial implementation).
 *
 * In this version, we use our MyADT.
 *
 * ***You cannot remove/change the code provided in this file.***
 *
 * Author: AL
 * Modified on: Sept. 14, 2023
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Profile.h"
#include "MyADT.h"

using std::cout;
using std::ws;
using std::cin;
using std::endl;


void join(MyADT & theMembers) {

   /* Put your code here */
   
   string username, name, email, birthday;
   // Ask the user to input the username 
   cout << "Enter a username, only lower letters allowed, no space: ";
   cin >> username;
   
   // Ask the user to input the name 
   cout << "Enter your fisrt name, no space: "; 
   cin >> name; 
   
   // Ask the user to input the email 
   cout << "Enter your email: ";
   cin >> email;
      
   // Ask the user to input the birthday 
   cout << "Enter your birthay(month/date/year), no space: ";
   cin >> birthday;
   
   // Create a temprate Profile object
   Profile temp(username, name, email, birthday);   
   //setUserName(temp->userName);
   
   // Insert the temp profile to MyADT
   bool result = theMembers.insert(temp);
   
   // Output whether or not join the FriendsBook successfully
   if (result)  
   	cout << "You joined FriendsBook successfully!" << endl;
   else
   	cout << "Failed to join!" << endl;
}

void leave(MyADT & theMembers) {

   /* Put your code here */
   
   // Ask the user to input the username they want to delete
   string userName;
   cout << "Enter your username to delete your profile: ";
   cin >> userName;
   
   // Create a temprate Profile object
   Profile temp(userName);
   
   // Remove the profile from MyADT
   bool result = theMembers.remove(temp);
   
   // Output whether or not leave the FriendsBook successfully
   if (result)
   	cout << "You left the FriendsBook successfully." << endl;
   else
   	cout << "Failed to leave. Can't find the username." << endl;
}

void search(MyADT & theMembers) {

   /* Put your code here */  
   
   // Ask the user to input the username they want to delete
   string userName;
   cout << "Please enter the username you want to search: ";
   cin >> userName;
   
   // Create a temprate Profile object
   Profile temp(userName);
   
   // Search the profile from MyADT, then output
   if (theMembers.search(temp)==nullptr)
   	cout << "Profile not found!" << endl;
   else
   	cout << "Profile found!" << endl;
}

void modify(MyADT & theMembers) {

   /* Put your code here */
   string username;
   
   // Ask the user to input the profile they want to modify
   cout << "Input the username you want to modify: ";
   cin >> username;

   // Create a temp profile using one parameter constructor
   Profile temp1(username);
   Profile* temp2 = theMembers.search(temp1);
   
   // Condition: username is in the Friendsbook
   if (temp2!=nullptr) {
   	string newName, newEmail, newBirthday;
   	
   	// Get name, email, birthday from temp
   	newName = temp2->getName();
   	newEmail = temp2->getEmail();
   	newBirthday = temp2->getBirthday();
   	
   	// Remove the profile first	
   	theMembers.remove(temp1);

   	// Keep going until the user modified
   	bool done = false;
   	char input = 0;
   	while (not done) {
        	// Print menu to output
        	cout << "\n***Modify your FriendsBook!***" << endl << endl;
        	cout << endl << "Enter ..." << endl;
        	cout << "n -> to modify your name." << endl;
        	cout << "e -> to modify your email." << endl;
        	cout << "b -> to modify your birthday." << endl;
        	cout << "f -> to exit modify." << endl;

        	cout << "Your choice: ";
        	cin >> input;
        	cout << endl;

        	switch(input) {
        	// Modify the name
            	case 'n': 
   			cout << "Input your new name, only lower letters allowed: ";
   			cin >> newName;
   	    	break;
   	    
   	    	// Modify the email
            	case 'e': 
   			cout << "Input your new email: ";
   			cin >> newEmail;
            	break;
            
            	// Modify the birthday
            	case 'b': 
   			cout << "Input your new birthay, month date year: ";
   			cin >> newBirthday; 
            	break;
            
            	// Exit the modify
            	case 'f': 
            		cout << "\n----Modify finished!\n" << endl; 
                      	done = true; break;
            	default: cout << "Please try again!" << endl;
        	}}
   	  	
   	// Create a new profile
   	Profile newtemp(username, newName, newEmail, newBirthday);
   	
   	// Inseert to MyADT
   	theMembers.insert(newtemp);
   	
   	// Output the information
   	cout << "You've modified your profile successfully!" << endl;
   }
   else
   	cout << "Can't find the profile, modify failed.";
}

void print(MyADT & theMembers) {

   /* Put your code here */
   theMembers.print();
}

int main() {

    // Variables declaration
    MyADT members = MyADT();  // Object MyADT on the stack, its arrays on the heap
    bool done = false;
    char input = 0;
        
    // Keep going until the user exits
    while (not done) {
        // Print menu to stdout
        cout << "\n----Welcome to FriendsBook!" << endl << endl;
        cout << endl << "Enter ..." << endl;
        cout << "j -> to join FriendsBook by creating a profile." << endl;
        cout << "l -> to leave FriendsBook." << endl;
        cout << "s -> to search for a friend on FriendsBook." << endl;
        cout << "m -> to modify your profile on FriendsBook." << endl;
        cout << "p -> to print all members on FriendsBook." << endl;
        cout << "x -> to exit FriendsBook." << endl << endl;


        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);
        switch(input) {
            case 'j': join(members); break;
            case 'l': leave(members); break;
            case 's': search(members); break;
            case 'm': modify(members); break;
            case 'p': print(members); break;
            case 'x': cout << "\n----Bye!\n" << endl; 
                      done = true; break;
            default: cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }

    return 0;
}
