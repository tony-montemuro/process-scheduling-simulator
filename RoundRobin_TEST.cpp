//Programmer: 	Tony Montemuro
//Section: 		3
//Lab:			Project
//Date:			November 29th, 2020
//Description:	Testing the methods of the RoundRobin class.

#include <iostream>
#include "Scheduler.hpp"
#include "Process.hpp"

using namespace std;

void checkNULL(Process*);

int main() {
	cout << "Test A: Declare a, an object of type RoundRobin." << endl;
	RoundRobin a;
	cout << "a declared and constructed!" << endl << endl;
	
	cout << "Test B: Add 15 IO-Bound Processes to a, and 10 CPU-Bound Processes to a." << endl;
	for (int i = 1; i <= 15; i++)
	{
		Process* t = new IOBoundProcess(i);
		a.addProcess(t);
	}
	for (int i = 16; i <= 25; i++)
	{
		Process* t = new CPUBoundProcess(i);
		a.addProcess(t);
	}
	cout << "Processes added!" << endl; 
	cout << "Current length of queue: " << a.processQueueSize() << endl << endl;
	
	cout << "Test C: Use popNext to find the first un-blocked process in queue. Since all are unblocked, it should return Process with ID 1." << endl;
	Process* p1 = a.popNext(1);
	cout << "Process Returned and Removed from Queue has ID of: " << p1->getID() << endl;
	cout << "Current length of queue: " << a.processQueueSize() <<  endl << endl;
	
	cout << "Test D: Declare b, an empty object of type RoundRobin, and attempt to run the popNext method. Should return 0 pointer." << endl;
	RoundRobin b;
	Process* p2 = b.popNext(1);
	checkNULL(p2);
	
	cout << "Test E: Declare c, an object of type RoundRobin, and fill it with blocked IO-Bound Processes." << endl;
	cout << "Then, the popNext method will be run. Should return 0." << endl;
	RoundRobin c;
	for (int i = 0; i < 5; i++)
	{
		Process* t = new IOBoundProcess(i);
		c.addProcess(t);
	}
	//Although a negative curCyle is not possible under normal circumstances, this is simply being done for testing purposes
	Process* p3 = c.popNext(-1);
	checkNULL(p3);
	
	cout << "Test F: Declare d, an object of type RoundRobin, and fill the first half of the queue with blocked IO-Bound Processes," << endl;
	cout << "and the second half of the queue with CPU-Bound Processes. Then, run the popNext method on d. It should return the first" << endl;
	cout << "CPU-Bound Process, which will have an ID of 5." << endl;
	RoundRobin d;
	for (int i = 0; i < 5; i++)
	{
		Process* t = new IOBoundProcess(i);
		c.addProcess(t);
	}
	for (int i = 5; i < 10; i++)
	{
		Process* t = new CPUBoundProcess(i);
		d.addProcess(t);
	}
	//Although a negative curCyle is not possible under normal circumstances, this is simply being done for testing purposes
	Process* p4 = d.popNext(-1);
	if (p4->getID() == 5)
	{
		cout << "Test was successful, popNext method removed and returned the 5th element of the queue." << endl << endl;
	}
	else
	{
		cout << "Test F failed." << endl << endl;
	}
	return 0;
}

void checkNULL(Process* p)
{
	/*
		Precond: p is of type Process*.
		Postcond: If p is 0, success is printed to console. Otherwise, not successful is printed to console.
	*/
	if (p == 0)
	{
		cout << "popNext method successfully returned 0." << endl << endl;
	}
	else
	{
		cout << "popNext method did not successfully return 0." << endl << endl;
	}	
}
