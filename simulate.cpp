//Programmer: 	Tony Montemuro
//Section: 		3
//Lab:			Project
//Date:			November 29th, 2020
//Description:	Definition of the function declared in "simulate.hpp".

#include <iostream>
#include <chrono>
#include "simulate.hpp"

using namespace std;

double* simulate(Scheduler* sched, int numCPUBound, int numIOBound, int numCycles)
{
	/*
		Precond: sched is a pointer to a RoundRobin object, numCPU is a positive integer, numIOBound is a positive integer, numCycles is a positive integer.
		Postcond: A process scheduling has been simulated. This function returns an array of 5 doubles.
					-Index 0: (# nanoseconds simulation took) / (# of times scheduler is used)
					-Index 1: Average CPU time of all CPU-Bound processes
					-Index 2: Average wait time of all CPU-Bound processes
					-Index 3: Average CPU time of all I/O-Bound processes
					-Index 4: Average wait time of all I/O-Bound processes
	*/
	//declare variables
	int cycle = 0;
	double schedCtr = 0.0;// totalCPUTime_cpu = 0.0, totalWaitTime_cpu = 0.0, totalCPUTime_io = 0.0, totalWaitTime_io = 0.0;
	long long int totalCPUTime_cpu = 0, totalWaitTime_cpu = 0, totalCPUTime_io = 0, totalWaitTime_io = 0;
	double numCPUBound_dbl = (double)numCPUBound, numIOBound_dbl = (double)numIOBound;
	double* simData = new double(5);
	Process* p;
	Process* t;
	
	//allocate processes and add to scheduler
	for (int i = 0; i < numCPUBound; i++)
	{
		t = new CPUBoundProcess(i);
		sched->addProcess(t);
	}
	for (int i = 0; i < numIOBound; i++)
	{
		t = new IOBoundProcess(i+numCPUBound);
		sched->addProcess(t);
	}
	
	auto t1 = chrono::system_clock::now();
	//round robin simulator
	while (cycle <= numCycles)
	{
		p = sched->popNext(cycle);
		if (p == 0)
		{
			cycle += 10;
		}
		else
		{
			cycle += p->useCPU(cycle, 10);
			sched->addProcess(p);
		}
		schedCtr++;
	}
	
	//calculate duration of siumulation
	auto t2 = chrono::system_clock::now();
	auto dur = t2 - t1;
	auto durNS = chrono::duration_cast<chrono::nanoseconds>(dur);
	double elapsed = durNS.count();
	
	//pop all processes out of queue and into temporary process pointer to calculate total cpu times and wait times, and deallocate process from memory
	for (int i = 0; i < numCPUBound+numIOBound; i++)
	{
		//Setting curCycle equal to MAX_INT guarantees all processes are removed from the queue and returned to this array
		t = sched->popNext(INT_MAX);
		schedCtr++;
		//if the ID of the process is less than numCPUBound, it is a CPUBoundProcess. otherwise, IOBoundProcess.
		if (t->getID() < numCPUBound)
		{
			totalCPUTime_cpu += t->getCPUTime();
			totalWaitTime_cpu += t->getWaitTime(cycle);
		}
		else
		{
			totalCPUTime_io += t->getCPUTime();
			totalWaitTime_io += t->getWaitTime(cycle);
		}
		delete t;
	}
	
	//allocate each element of simData[] array
	simData[0] = elapsed / schedCtr;
	simData[1] = (double)totalCPUTime_cpu / numCPUBound_dbl;
	simData[2] = (double)totalWaitTime_cpu / numCPUBound_dbl;
	simData[3] = (double)totalCPUTime_io / numIOBound_dbl;
	simData[4] = (double)totalWaitTime_io / numIOBound_dbl;
	
	//return array
	return simData;
}
