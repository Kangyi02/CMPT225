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
 
 Stack::Stack(): head(nullptr) 
 {
 }
    	
 Stack::~Stack()
 {
	if (!isEmpty())
 		this->popAll();
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
 	if (isEmpty())
	{
		StackNode* pushNode = new StackNode();
 		pushNode->data = newElement;
 		pushNode->next = nullptr;
 		head = pushNode;
	}
 	else
 	{
 		StackNode* current = head;
		StackNode* pushNode = new StackNode();
		pushNode->data = newElement;
 		pushNode->next = nullptr;
 		while (current->next!=nullptr)
 		{
 			current = current->next;
 		}
		
 		current->next = pushNode;
 	}
 }
 
 int Stack::pop()
 {
	StackNode* current = head;
 	if (isEmpty())
 	{
 	 	cout << "Empty list";	
 	}
	else if (head->next==nullptr)
	{
		delete head;
		head = nullptr;
	}
 	else
 	{
 		while (current->next->next!=nullptr)
 		{
 			current = current->next;
 		}

		delete current->next;
		current->next = nullptr;
 	}
	return current->data;
 }
 
void Stack::popAll() 
{
	while (!isEmpty())
 		pop();
}

 int Stack::peek() const
 {
 	int value;
 	
 	if (this->isEmpty())
 	{
 		cout << "Empty list!";
		value = 0;
 	}
 	else
 	{	
		StackNode* current = head;
 		while (current->next!= nullptr)
 		{
 			current = current->next;
 		}
		value = current->data;
 	}
 	
 	return value;
 }
