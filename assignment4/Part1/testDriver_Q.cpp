#include "Queue.h"
#include "Queue.cpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Queue<int> *que = new Queue<int>();

    int i = 3;
    int j = 5;
    int k = 9;
	que->enqueue(i);
    que->print();
    que->dequeue();
    que->enqueue(j);
    que->print();
    que->enqueue(k);
    que->print();
    que->dequeue();
    que->print();
    que->dequeue();
    que->dequeue();
    //que->print();
    delete que;
    que = nullptr;
}