/*
 * BSTTestDriver.cpp
 *
 * Description: Drives the testing of the BST ADT class.
 *
 * Author: AL
 * Last Modification Date: Oct. 2023
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BST.h"
#include "WordPair.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"

using std::cin;
using std::cout;
using std::ifstream;

void display(WordPair &anElement)
{
   cout << anElement;
}

// As you discover what main() does, record your discoveries by commenting the code.
// If you do not like this main(), feel free to write your own.
// Remember, this is a test driver. Feel free to modify it as you wish!
int main(int argc, char *argv[])
{

   BST *testing = new BST();

   string aLine = "";
   string aWord = "";
   string englishW = "";
   string translationW = "";
   string filename = "dataFile.txt";
   string delimiter = ":";
   size_t pos = 0;
   WordPair translated;

   ifstream myfile(filename);
   if (myfile.is_open())
   {
      cout << "Reading from a file:" << endl;
      while (getline(myfile, aLine))
      {
         pos = aLine.find(delimiter);
         englishW = aLine.substr(0, pos);
         aLine.erase(0, pos + delimiter.length());
         translationW = aLine;
         WordPair aWordPair(englishW, translationW);
         // insert aWordPair into "testing" using a try/catch block
         try
         {
            cout << "Inserting an element...";
            testing->insert(aWordPair);
            display(aWordPair);
         }
         catch (ElementAlreadyExistsException &anException)
         {
            cout << "Failed to insert, Element Already Exists!" << anException.what() << '\n';
         }
         catch (UnableToInsertException &anException)
         {
            cout << "Failed to insert!" << anException.what() << '\n';
         }
      }
      myfile.close();

      // If user entered "display" at the command line ...
      if ((argc > 1) && (strcmp(argv[1], "display") == 0))
      {
         // ... then display the content of the BST.
      }
      else if (argc == 1)
      {
         // while user has not entered CTRL+D
         while (getline(cin, aWord))
         {

            WordPair aWordPair(aWord);
            // retrieve aWordPair from "testing" using a try/catch block
            // print aWordPair
            try
            {
               WordPair print = testing->retrieve(aWordPair);
               display(print);
            }
            catch (EmptyDataCollectionException &anException)
            {
               cout << "Retrieve failed because " << anException.what() << endl;
            }
            catch (ElementAlreadyExistsException &anException)
            {
               cout << "Retrieve failed because " << anException.what() << endl;
            }
            catch (ElementDoesNotExistException &anException)
            {
               cout << "Retrieve failed because " << anException.what() << endl;
            }
         }
      }
   }
   else
      cout << "Unable to open file";

   delete testing;
   return 0;
}
