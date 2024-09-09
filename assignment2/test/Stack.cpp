/* 
 * Stack.cpp
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author:
 * Date:
 */
 
 #include <iostream> 
 #include "Stack.h"
 
 using std::cout;
 
 Stack::Stack(): head(nullptr) {}
    	
 Stack::~Stack()
 {
 	while (!isEmpty())
 		this->pop();
 	delete head;
 }
 
 bool Stack::isEmpty() const
 {
 	bool result = true;
 	if (head!=nullptr)
 		result = false;
 	return result;
 }
 
 void Stack::push(int newElement)
 {
 	StackNode* pushNode = new StackNode();
 	pushNode->data = newElement;
 	pushNode->next = nullptr;
 	
 	if (isEmpty())
 		head = pushNode;
 	else
 	{
 		StackNode* current = head;
 		while (current->next!=nullptr)
 		{
 			current = current->next;
 		}
 		current->next = pushNode;
 		pushNode->next = nullptr;
 	}
 	

 }
 
 void Stack::pop()
 {
 	if (this->isEmpty())
 	{
 	 	cout << "Empty list";	
 	}
 	
 	if (head->next == nullptr)
 	{
 		delete head;
 		head = nullptr;
 	}	
 	else
 	{
 		StackNode* current = head;
 		StackNode* previous;
 		
 		while (current->next!=nullptr)
 		{
 			previous = current;
 			current = current->next;
 		}
 		current = nullptr;
 		delete current;
 	}
 }
 
 int Stack::peek() const
 {
 	int value = 0;
 	StackNode* current = head;
 	if (this->isEmpty())
 	{
 		cout << "Empty list!";
 	}
 	else
 	{	
 		while (current->next!=nullptr)
 		{
 			current = current->next;
 		}
 	}
 	value = current->data;
 	return value;
 }
