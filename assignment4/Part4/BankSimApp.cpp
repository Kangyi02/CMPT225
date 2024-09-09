/*
 * BankSimApp.cpp
 *
 * Description: BankSimApp.
 *
 * Author: KZ
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
#include "Queue.h"
#include "Event.h"
#include "BinaryHeap.h"
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

// Processes an arrival event
void processArrival(Event arrivalEvent, PriorityQueue<Event> *eventPriorityQueue,
                    Queue<Event> *bankLine, bool tellerAvailable, int currentTime)
{
    // Remove this event from the event queue
    eventPriorityQueue->dequeue();

    Event customer = arrivalEvent;
    if (bankLine->isEmpty() && tellerAvailable)
    {
        int departureTime = currentTime + customer.getLength();
        Event newDepartureEvent('A', departureTime);
        eventPriorityQueue->enqueue(newDepartureEvent);
        tellerAvailable = false;
    }
    else
        bankLine->enqueue(customer);
}

// Processes an departure event
void processDeparture(Event departureEvent, PriorityQueue<Event> *eventPriorityQueue,
                      Queue<Event> *bankLine, bool tellerAvailable, int currentTime)
{
    // Remove this event from the event queue
    eventPriorityQueue->dequeue();

    if (!bankLine->isEmpty())
    {
        // Customer at front of line begins transaction
        Event &customer = bankLine->peek();
        bankLine->dequeue();
        int departureTime = currentTime + customer.getTime();
        Event newDepartureEvent('D', departureTime);
        eventPriorityQueue->enqueue(newDepartureEvent);
    }
    else
        tellerAvailable = true;
}

// Performs the simulation
void simulate()
{
    cout << "Simulation Begins" << endl;
    Queue<Event> *que = new Queue<Event>();
    PriorityQueue<Event> *priQue = new PriorityQueue<Event>();
    int currentTime = 0;
    float totalWaitTime = 0.0;
    bool tellerAvailable = true;
    int arrivalTime, length;

    string delimiter = " ";
    string aLine = "";
    size_t pos;

    while (getline(cin, aLine))
    {
        pos = aLine.find(delimiter);
        arrivalTime = stoi(aLine.substr(0, pos));
        aLine.erase(0, pos + delimiter.length());
        length = stoi(aLine);
        Event a('A', arrivalTime, length);
        priQue->enqueue(a);
        totalWaitTime += length;
    }

    while (!priQue->isEmpty())
    {

        Event newEvent = priQue->peek();
        currentTime = newEvent.getTime();

        if (newEvent.getType() == 'A')
        {
            processArrival(newEvent, priQue, que, tellerAvailable, currentTime);
        }
        else
        {
            processDeparture(newEvent, priQue, que, tellerAvailable, currentTime);
        }
    }

    return;
}

int main()
{
    simulate();
}