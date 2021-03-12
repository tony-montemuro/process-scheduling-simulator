//Programmer: 	Tony Montemuro
//Section: 		3
//Lab:			Project
//Date:			November 29th, 2020
//Description:	Testing the methods of the CompletelyFair class.

#include <iostream>

#include "Scheduler.hpp"

using namespace std;

void checkNULL(Process*);

int main()
{
	cout << "Test A: Declare a, an object of type CompletelyFair." << endl;
	CompletelyFair a;
	cout << "a declared and constructed!" << endl;
	
	cout << endl << "Test B: Adding 3 I/O-Bound Processes to a, and 2 CPU-Bound Processes to a." << endl;
	Process* t;							/*					procTree				*/
	for (int i = 1; i <= 3; i++)		/*						0	[proc 1]		*/
	{									/*					   	 \					*/
		t = new IOBoundProcess(i);		/*					  	  0	[proc 2]		*/
		a.addProcess(t);				/*					 	   \				*/
	}									/*				    		0	[proc 3]	*/
	for (int i = 4; i <= 5; i++)		/*				   	  		 \				*/
	{									/*				  			  0	[proc 4]	*/
		t = new CPUBoundProcess(i); 	/*				 			   \			*/
		a.addProcess(t);				/*								0 [proc 5]	*/
	}									/*		Tree is unbalanced since all Processes have a CPU-Time of 0 to start.		*/
	cout << "Processes successfully added to procTree!" << endl;
	cout << "Current length of tree: " << a.processBSTSize() << endl;
	
	cout << endl << "Test C: Use popNext to find the first un-blocked process in tree. Since all are unblocked, it should return Process with ID 1." << endl;
	Process* p1 = a.popNext(1);
	cout << "Process Returned and Removed from Queue has ID of: " << p1->getID() << endl;
	cout << "Current length of tree: " << a.processBSTSize() <<  endl;
	
	cout << endl << "Test D: Declare b, an empty object of type CompletelyFair, and attempt to run the popNext method. Should return 0 pointer." << endl;
	CompletelyFair b;
	t = b.popNext(1);
	checkNULL(t);
	
	cout << "Test E: Declare c, an object of type CompletelyFair, and fill it with blocked IO-Bound Processes." << endl;
	cout << "Then, the popNext method will be run. Should return 0." << endl;
	CompletelyFair c;
	for (int i = 0; i < 5; i++)
	{
		Process* t = new IOBoundProcess(i);
		c.addProcess(t);
	}
	//Although a negative curCyle is not possible under normal circumstances, this is simply being done for testing purposes
	t = c.popNext(-1);
	checkNULL(t);
	
	cout << "Test F: Declare d, an object of type CompletelyFair, and fill the first half of the queue with blocked IO-Bound Processes," << endl;
	cout << "and the second half of the queue with CPU-Bound Processes. Then, run the popNext method on d. It should return the first" << endl;
	cout << "CPU-Bound Process, which will have an ID of 5." << endl;
	RoundRobin d;
	for (int i = 0; i < 5; i++)
	{
		Process* t = new IOBoundProcess(i);
		d.addProcess(t);
	}
	for (int i = 5; i < 10; i++)
	{
		Process* t = new CPUBoundProcess(i);
		d.addProcess(t);
	}
	//Although a negative curCyle is not possible under normal circumstances, this is simply being done for testing purposes
	t = d.popNext(-1);
	if (t->getID() == 5)
	{
		cout << "Test was successful, popNext method removed and returned the 5th element of the tree." << endl << endl;
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
