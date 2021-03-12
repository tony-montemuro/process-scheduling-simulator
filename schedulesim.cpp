//Programmer: 	Tony Montemuro
//Section: 		3
//Lab:			Project
//Date:			November 28th, 2020
//Description:	This is the main file, where the Process Schedule simulations are run.

#include "simulate.hpp"

#include <iostream>
#include <climits>

using namespace std;

int main(int argc, char** argv)
{
   int numCPUBound = atoi(argv[1]);
   int numIOBound = atoi(argv[2]);
   int numCycles = atoi(argv[3]);

   Scheduler* schedArr[] = {new RoundRobin(), new FastRoundRobin(), new CompletelyFair()};

   string labels[] = {"Round Robin (Array List)", "Round Robin (Linked List)", "Completely Fair (BST)"};
   
   for(int i = 0; i < 3; i++)
   {
      double* results = simulate(schedArr[i], numCPUBound, numIOBound, numCycles);
      cout << labels[i] << endl;
      cout << "Time per schedule: " << results[0] << endl;
      cout << "CPU Bound CPU Time: " << results[1] << endl;
      cout << "CPU Bound Wait Time: " << results[2] << endl;
      cout << "IO Bound CPU Time: " << results[3] << endl;
      cout << "IO Bound Wait Time: " << results[4] << endl << endl;
      delete[] results;
      delete schedArr[i];
   }
}


