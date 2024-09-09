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
 
 template <class T> 
 Stack<T>::Stack(): head(nullptr) 
 {
	int data = 0;
 }
    	
 template <class T> 
 Stack<T>::~Stack()
 {
	if (!isEmpty())
 		this->popAll();
	delete head;
 }
 
 template <class T> 
 void Stack<T>::push(T newElement)
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
 
 template <class T> 
 T Stack<T>::pop()
 {
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
 		StackNode* current = head;
 		
 		while (current->next->next!=nullptr)
 		{
 			current = current->next;
 		}

		delete current->next;
		current->next = nullptr;
 	}
    return current->data;
 }
 
 template <class T> 
 T Stack<T>::peek()
 {
 	StackNode* current = head;
 	if (this->isEmpty())
 	{
 		cout << "Empty list!";
 	}
 	else
 	{	
 		while (current->next!= nullptr)
 		{
 			current = current->next;
 		}
 	}
 	
 	return current;
 }

 template <class T> 
 bool Stack<T>::isEmpty() 
 {
 	bool result = true;
 	if (head!=nullptr)
 		result = false;
 	return result;
 }