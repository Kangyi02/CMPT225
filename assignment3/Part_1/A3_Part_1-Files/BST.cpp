/*
 * BST.cpp
 *
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 *
 * Author: Inspired from our textbook
 * Date of last modification: Oct. 2023
 */

#include "BST.h"
#include "WordPair.h"
#include <iostream>

using std::cout;
using std::endl;

// You cannot change the prototype of the public methods of this class.
// Remember, if you add public methods to this class, our test driver
// - the one we will use to mark this assignment - will not know about them
// since we will use these public method prototypes to create our test driver.

/* Constructors and destructor */

// Default constructor
BST::BST() {}

// Copy constructor
BST::BST(const BST &aBST)
{
   // to do
   root = copyTreeElement(aBST.root);
   elementCount = aBST.elementCount;
}

// Used for copy constructor, use recusive function to copy
// every element
BSTNode *BST::copyTreeElement(BSTNode *bstNode)
{
   BSTNode *copyNode = new BSTNode();
   if (bstNode == nullptr)
      copyNode = nullptr;
   else
   {
      copyNode->element = bstNode->element;
      if (bstNode->hasLeft())
         copyNode->left = copyTreeElement(bstNode->left);
      if (bstNode->hasRight())
         copyNode->right = copyTreeElement(bstNode->right);
   }

   return copyNode;
}

// Destructor
BST::~BST()
{
   // to do
   elementCount = 0;
   deleteTreeElemenet(root);
}

void BST::deleteTreeElemenet(BSTNode *bstNode)
{
   if (bstNode != nullptr)
   {
      deleteTreeElemenet(bstNode->left);
      deleteTreeElemenet(bstNode->right);
      delete bstNode;
      bstNode = nullptr;
   }
}

/* Getters and setters */

// Description: Returns the number of elements currently stored in the binary search tree.
// Time efficiency: O(1)
unsigned int BST::getElementCount() const
{
   return this->elementCount;
}

/* BST Operations */

// Description: Inserts an element into the binary search tree.
//              This is a wrapper method which calls the recursive insertR( ).
// Precondition: "newElement" does not already exist in the binary search tree.
// Exception: Throws the exception "UnableToInsertException" when newElement
//            cannot be inserted because the "new" operator failed.
// Exception: Throws the exception "ElementAlreadyExistsException"
//            if "newElement" already exists in the binary search tree.
// Time efficiency: O(log2 n)
void BST::insert(WordPair &newElement)
{

   // to do
   BSTNode *newNode = new BSTNode(newElement);
   if (!newNode)
      throw UnableToInsertException("Unable to insert!");

   if (elementCount == 0)
   {
      root = newNode;
      elementCount++;
   }
   else
   {
      if (!insertR(newNode, root))
      {
         delete newNode;
         newNode = nullptr;
         throw ElementAlreadyExistsException("Element already exists!");
      }
   }

}

// Description: Recursive insertion into a binary search tree.
//              Returns true when "anElement" has been successfully inserted into the
//              binary search tree. Otherwise, returns false.
bool BST::insertR(BSTNode *newBSTNode, BSTNode *current)
{

   // to do

   bool result = false;

   if (current->element == newBSTNode->element)
   {
      return false;
   }
   else if (newBSTNode->element < current->element)
   {
      if (current->hasLeft())
      {
         return insertR(newBSTNode, current->left);
      }
      else
      {
         current->left = newBSTNode; 
         elementCount++;
         result = true;
      }
   }
   else
   {
      if (current->hasRight())
      {
         return insertR(newBSTNode, current->right);
      }
      else
      {
         current->right = newBSTNode;
         elementCount++;
         result = true;
      }
   }
   return result;
}

// Description: Retrieves "targetElement" from the binary search tree.
//           This is a wrapper method which calls the recursive retrieveR( ).
// Precondition: Binary search tree is not empty.
// Exception: Throws the exception "EmptyDataCollectionException"
//            if the binary search tree is empty.
// Exception: Throws (propagates) the exception "ElementDoesNotExistException"
//            thrown from the retrieveR(...)
//            if "targetElement" is not in the binary search tree.
// Time efficiency: O(log2 n)
WordPair &BST::retrieve(WordPair &targetElement) const
{

   if (elementCount == 0)
      throw EmptyDataCollectionException("Binary search tree is empty.");

   WordPair &translated = retrieveR(targetElement, root);

   return translated;
}

// Description: Recursive retrieval from a binary search tree.
// Exception: Throws the exception "ElementDoesNotExistException"
//            if "targetElement" is not found in the binary search tree.
WordPair &BST::retrieveR(WordPair &targetElement, BSTNode *current) const
{

   // to do

   while (current != nullptr)
   {
      if (targetElement == current->element)
      {
         return current->element;
      }
      else if (targetElement < current->element)
      {
         current = current->left;
      }
      else if (targetElement > current->element)
      {
         current = current->right;
      }
   }

   throw ElementDoesNotExistException("Element does not exist!");
   
}

// Description: Traverses the binary search tree in order.
//           This is a wrapper method which calls the recursive traverseInOrderR( ).
//           The action to be done on each element during the traverse is the function "visit".
// Precondition: Binary search tree is not empty.
// Exception: Throws the exception "EmptyDataCollectionException"
//         if the binary search tree is empty.
// Time efficiency: O(n)
void BST::traverseInOrder(void visit(WordPair &)) const
{
   if (elementCount == 0)
      throw EmptyDataCollectionException("Binary search tree is empty.");

   traverseInOrderR(visit, root);

   return;
}

// Description: Recursive in order traversal of a binary search tree.
void BST::traverseInOrderR(void visit(WordPair &), BSTNode *current) const
{

   // to do
   if (current != nullptr)
   {
      traverseInOrderR(visit, current->left);
      visit(current->element);
      traverseInOrderR(visit, current->right);
   }

}
