/* 
 * Stack.h
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author:
 * Date:
 */
 
class Stack {

    private:
        
        // Description:  Nodes for a singly-linked list - Do not modify!
        class StackNode {
            public:
                int data;
                StackNode * next;
        };
        
        // head point to the first element in the linked list
        StackNode * head;

/* Put your code here! */       
        
    /* Stack public interface */
    public:
    	Stack();
    	~Stack();
    	bool isEmpty() const;
    	void push(int newElement);
    	int pop();
        void popAll();
    	int peek() const;
    
/* Put your code here! */   

};
