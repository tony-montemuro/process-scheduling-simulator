//Programmer: 	Erik Talvitie & Tony Montemuro
//Section: 		3
//Lab:			Project
//Date:			November 28th, 2020
//Description:	Declaration of Scheduler class, as well as subclasses RoundRobin, FastRoundRobin, and CompletelyFair.

/*********************************
 * Solution to CPS 222 Project 2 *
 * Author: Erik Talvitie         *
 *********************************/

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "List.hpp"
#include "ArrayList.hpp"
#include "LinkedList.hpp"
#include "Process.hpp"
#include "BSTMultimap.hpp"

class Scheduler
{
  public:
   //virtual destructor that does nothing
   virtual ~Scheduler() {}
   //adds the given process to the processes to be scheduled
   virtual void addProcess(Process* proc) = 0;
   //revmoes and returns the next process in the schedule (and returns 0 if there is no avaliable process)
   virtual Process* popNext(int curCycle) = 0;
};

class RoundRobin : public Scheduler
{
	protected:
		List<Process*>* procQueue;
	public:
		RoundRobin();
		virtual ~RoundRobin();
		virtual void addProcess(Process* proc);
		virtual Process* popNext(int curCycle);
		virtual int processQueueSize(); //for testing
};

class FastRoundRobin : public RoundRobin
{
	public:
		FastRoundRobin();	
};

class CompletelyFair : public Scheduler
{
	protected:
		BSTMultimap<int, Process*>* procTree;
	public:
		CompletelyFair();
		virtual ~CompletelyFair();
		virtual void addProcess(Process* proc);
		virtual Process* popNext(int curCycle);
		virtual int processBSTSize(); //for testing
};

#endif

