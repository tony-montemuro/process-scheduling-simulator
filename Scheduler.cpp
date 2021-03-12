//Programmer: 	Tony Montemuro
//Section: 		3
//Lab:			Project
//Date:			November 29th, 2020
//Description:	Definitions of the methods declared in "Scheduler.hpp".

#include <iostream>

#include "Scheduler.hpp"

using namespace std;

//Definitions for RoundRobin methods, a subclass of Scheduler
RoundRobin::RoundRobin()
{
	/*
		Precond: An object of class RoundRobin is declared.
		Postcond: The one procected memeber of RoundRobin, procQueue, which is a pointer to an ArrayList that stores pointers to Processes, is initialized.
	*/
	procQueue = new ArrayList<Process*>();
}

void RoundRobin::addProcess(Process* proc)
{
	/*
		Precond: An object of class RoundRobin is declared and intitialized.
		Postcond: proc is pushed to the back of procQueue.
	*/
	procQueue->pushBack(proc);
}

Process* RoundRobin::popNext(int curCycle)
{
	/*
		Precond: An object of class RoundRobin is declared and initialized.
		Postcond: If proqQueue has no Processes, 0 is returned. If proqQueue has no unblocked processes, 0 is returned. Otherwise, proqQueue returns and removes from queue the first unblocked process in queue.
	*/
	if (procQueue->isEmpty())
	{
		return 0;
	}
	for (int i = 0; i < procQueue->getSize(); i++)
	{
		Process* p = procQueue->getFront();
		if (p->isBlocked(curCycle))
		{
			procQueue->popFront();
			procQueue->pushBack(p);
		}
		else
		{
			procQueue->popFront();
			return p;
		}
	}
	return 0;
}

//used for debugging
int RoundRobin::processQueueSize()
{
	return procQueue->getSize();
}

RoundRobin::~RoundRobin()
{
	/*
		Precond: Destructor is manually called on object using delete, or program has terminated.
		Postcond: procQueue is deleted from memory.
	*/
	delete procQueue;
}

//Definitions for FastRoundRobin methods, a subclass of RoundRobin
FastRoundRobin::FastRoundRobin()
{
	/*
		Precond: An object of class FastRoundRobin is declared.
		Postcond: The one procected memeber of RoundRobin, procQueue, which is a pointer to an ArrayList that stores pointers to Processes, is deleted, and procQueue is reinitialized to point to a LinkedList
				  that stores pointers to Processes.
	*/
	delete procQueue;
	procQueue = new LinkedList<Process*>();
	
}

//Definitions for CompletelyFair methods, a subclass of Scheduler
CompletelyFair::CompletelyFair()
{
	/*
		Precond: An object of class CompletelyFair is declared.
		Postcond: The one procected memeber of CompletelyFair, procTree, which is a pointer to a BSTMultimap that stores keys as integers and values as pointers to Processes, is initialized.
	*/
	procTree = new BSTMultimap<int, Process*>();
}

void CompletelyFair::addProcess(Process* proc)
{
	/*
		Precond: An object of class CompletelyFair is declared and constructed, proc is of type Process*.
		Postcond: proc is inserted into BSTMultimap procTree. It's placement in the tree is dependent on the cpu-time of proc.
	*/
	procTree->insert(proc->getCPUTime(), proc);
}

Process* CompletelyFair::popNext(int curCycle)
{
	/*
		Precond: An object of class CompletelyFair is declared and constructed, curCyle is of type int.
		Postcond: An iterator equal to the process with the minimum CPU-time is obtained, and the first unblocked process in an in-order traversal of procTree is returned.
	*/
	BSTForwardIterator<int, Process*> it = procTree->getMin();
	//Loop that runs until the first unblocked process is found, or until all elements of the tree have been checked and they are all blocked
	while (!it.isPastEnd() && it.getValue()->isBlocked(curCycle))
	{
		it.next();
	}
	Process* p;
	if (!it.isPastEnd())
	{
		p = it.getValue();
		//If the iterator does not point to a sentinel node, remove the node pointed to by it
		it = procTree->remove(it);
	}
	else
	{
		p = 0;
	}
	return p;
}

//used for debugging
int CompletelyFair::processBSTSize()
{
	return procTree->getSize();
}

CompletelyFair::~CompletelyFair()
{
	/*
		Precond: Destructor is manually called on object using delete, or program has terminated.
		Postcond: procTree is deleted from memory.
	*/
	delete procTree;
}



