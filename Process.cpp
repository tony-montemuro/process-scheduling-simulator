//Programmer: 	Dr. Booth
//Section: 		3
//Lab:			Project
//Date:			October 19th, 2020
//Description:	Definitions of the methods declared in "Process.hpp". Comments by Tony Montemuro.

#include "Process.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

//Constructor of Process class. Takes in ID integer, and initializes the id proctected variable equal to id parameter. Initializes cpuTime and waitTime to 0.
Process::Process(int id) : id(id)
{
   cpuTime = 0;
   waitTime = 0;
}

//getID() method of Process class. This method simply returns the ID of the process.
int Process::getID() const
{
   return id;
}

//getCPUTime() method of Process class. This method simply returns the amount of CPU time this process has used so far.
int Process::getCPUTime() const
{
   return cpuTime;
}

//getWaitTime(int curCycleNum) method of Process class. Takes in curCycleNum, which is the number of simulated cycles so far.
//If lastTime, which is the time the process last started waiting for the CPU, is greater than or equal to curCycleNum, then waitTime is returned unchanged.
//Otherwise, the waitTime summed with the difference betwenn curCycleNum and lastTime is returned.
int Process::getWaitTime(int curCycleNum) const
{
   int additionalWait = curCycleNum - lastTime;
   if(additionalWait < 0)
   {
      additionalWait = 0;
   }
   return waitTime + additionalWait;
}


//Constructor of CPUBoundProcess class. Takes in ID integer, and intitializes the id protected variable equal to id parameter. Initializes lastTime to 0.
CPUBoundProcess::CPUBoundProcess(int id) : Process(id)
{
   lastTime = 0;
}

//isBlocked(int curCycleNum) method of CPUBoundProcess class. Takes in curCycleNum integer, which is the number of simulated cycles so far.
//This method will return false regardless of the parameter, since a CPU Bound Process is never blocked!
bool CPUBoundProcess::isBlocked(int curCycleNum) const
{
   return false;
}

//useCPU(int curCycleNum, int sliceSize) method of CPUBoundProcess class. Takes in curCycleNum integer, which is the number of simulated cycles so far, and
//sliceSize integer, which is the simulated amount of time this process remains on the CPU. Since the process is CPU-Bound, sliceSize is added to cpuTime protected variable, as the process uses all CPU time given to it.
//The difference between the curCycleTime and the lastTime protected variable are added to the waitTime protected variable. lastTime is set equal to curCycleNum added to sliceSize. Finally, sliceSize is returned.
int CPUBoundProcess::useCPU(int curCycleNum, int sliceSize)
{
   //The process uses all CPU time given to it
   cpuTime += sliceSize;
   
   waitTime += curCycleNum - lastTime;
   //When the process next uses the CPU, it will have been
   //waiting since the end of this window.
   lastTime = curCycleNum + sliceSize;

   return sliceSize;
}

//Constructor of IOBoundProcess class. Takes in ID integer, and intitializes the id protected variable equal to the id parameter. Initializes minBurst protected variable equal to 5,
//maxBurst protected variable equal to 15, minIO protected variable equal to 50, maxIO variable equal to 200, lastTime equal to 0, blockedUntil equal to 0, and remainingBurst equal to 0.
IOBoundProcess::IOBoundProcess(int id) : Process(id), minBurst(5), maxBurst(15), minIO(50), maxIO(200)
{
   lastTime = 0;
   blockedUntil = 0;
   remainingBurst = 0;
}

//isBlocked(int curCycleNum) method of IOBoundProcess class. Takes in curCycleNum integer, which is the number of simulated cycles so far.
//If curCycleNum is less than blockedUntil, this method will return true, and the process will be blocked. Otherwise, this method returns false.
bool IOBoundProcess::isBlocked(int curCycleNum) const
{
   return curCycleNum < blockedUntil;
}

//useCPU(int curCycleNum, int sliceSize) method of IOBoundProcess class. Takes in curCycleNum integer, which is the number of simulated cycles so far, and
//sliceSize integer, which is the simulated amound of time this process remains on the CPU. The first if-statement, which will run if the process was unblocked,
//assigns the next CPU burst (remainingBurst protected variable) equal to a random integer value between 0 and maxBurst. The method then
//declares and initializes the timeUsed integer variable equal to 0. The next if-statement runs if the process is not blocked, which is true when remainingBurst > 0.
//Inside this if-statement, the difference between curCycleTime and lastTime, a protected varialbe, is added to the waitTime protected variable. If the whole widow is used (indicated by remainingBurst being greater than sliceTime),
//then sliceSize is subtracted from remainingBurst, timeUsed is set equal to sliceSize, and lastTime is set equal to the sum of curCycleNum and sliceSize.
//If the whole window is not used (meaning the process will block midway through), then timeUsed is set equal to remainingBurst, remainingBurst is set equal to 0,
//blockedUnti is set equal to the sum of curCycleNum, timeUsed, and a random integer value between ((maxIO - minIO + 1) + minIO) - 1), and lastTime is set equal to blockedUntil.
//At the end of the method, blockedUntil is added to the cpuTime protected variable, and timeUsed is returned.
int IOBoundProcess::useCPU(int curCycleNum, int sliceSize)
{
   //If the process was blocked, and is now unblocked,
   //choose a length for the next CPU burst
   if(curCycleNum >= blockedUntil && remainingBurst == 0)
   {
      remainingBurst = rand()%(maxBurst - minBurst + 1) + minBurst;
   }

   int timeUsed = 0;
   if(remainingBurst > 0) //If the process is not blocked...
   {
      waitTime += curCycleNum - lastTime;

      if(remainingBurst > sliceSize) //If the whole window will be used...
      {
	 remainingBurst -= sliceSize;
	 timeUsed = sliceSize;

	 //When the process next uses the CPU, it will have been
	 //waiting since the end of this window.
	 lastTime = curCycleNum + sliceSize;
      }
      else //Otherwise the process will block without using the whole window
      {
	 timeUsed = remainingBurst;
	 remainingBurst = 0;

	 //Choose a time for the IO request to complete
	 blockedUntil = curCycleNum + timeUsed + rand()%(maxIO - minIO + 1) + minIO;
	 //When the process next uses the CPU, it will have been
	 //waiting since it unblocked (not since the end of this window).
	 lastTime = blockedUntil;
      }
   }

   cpuTime += timeUsed;
   return timeUsed;
}
