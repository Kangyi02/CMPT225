all: td

td: hashFunctionTestDriver.o Dictionary.o Profile.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o UnableToInsertException.o
	g++ -Wall -o td hashFunctionTestDriver.o Dictionary.o Profile.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o UnableToInsertException.o

hashFunctionTestDriver.o: hashFunctionTestDriver.cpp
	g++ -Wall -c hashFunctionTestDriver.cpp 

Dictionary.o: Dictionary.h Dictionary.cpp
	g++ -Wall -c Dictionary.cpp
	
Profile.o: Profile.h Profile.cpp
	g++ -Wall -c Profile.cpp
	
ElementDoesNotExistException.o: ElementDoesNotExistException.h ElementDoesNotExistException.cpp
	g++ -Wall -c ElementDoesNotExistException.cpp

ElementAlreadyExistsException.o: ElementAlreadyExistsException.h ElementAlreadyExistsException.cpp
	g++ -Wall -c ElementAlreadyExistsException.cpp
		
EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp
	
UnableToInsertException.o: UnableToInsertException.h UnableToInsertException.cpp
	g++ -Wall -c UnableToInsertException.cpp

clean:
	rm -f td *.o
