// C program for Highest Response Ratio Next (HRRN) Scheduling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining process details
struct process
{
	char name;
	int arrivalTime, burstTime, remainingBurstTime, waitTime, turnaroundTime;
	int completed;
} p[255];

// Sorting Processes by Arrival Time
void sortByArrival(int numberOfProcess)
{
	struct process temp;
	int i, j;

	// Selection Sort applied
	for (i = 0; i < numberOfProcess - 1; i++)
	{
		for (j = i + 1; j < numberOfProcess; j++)
		{

			// Check for lesser arrival time
			if (p[i].arrivalTime > p[j].arrivalTime)
			{

				// Swap earlier process to front
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

struct ProcessesData
{
	int arrivaltimes[255];
	int bursttimes[255];
	int processno;
};

struct ProcessesData readFile(char *FileName)
{

	FILE *testcase;

	testcase = fopen(FileName, "r");

	int i = 0;
	int arrivaltimes[255];
	int bursttimes[255];

	if (testcase == NULL)
	{
		printf("Error in opening testcase file\n");
		fclose(testcase);
		exit(0);
	}

	while (fscanf(testcase, "%d %d", &arrivaltimes[i], &bursttimes[i]) != EOF)
	{
		i++;
	}

	arrivaltimes[i] = '\0';
	bursttimes[i] = '\0';

	fclose(testcase);

	struct ProcessesData processdata = {.processno = i};
	memcpy(processdata.arrivaltimes, arrivaltimes, sizeof arrivaltimes);
	memcpy(processdata.bursttimes, bursttimes, sizeof bursttimes);

	return processdata;
}

int main()
{
	int i, j, runTime, sum_burstTime = 0;
	char c;
	float avgwaitTime = 0, avgturnaroundTime = 0, maxwaitTime=0, maxturnaroundTime = 0;

	// File reading to array here
	printf("Enter in the input test case file:");
	char filename[15];
	scanf("%14s", &filename);
	struct ProcessesData processdata = readFile(filename);
	int numberOfProcesses = processdata.processno;

	// Initializing the structure variables
	for (i = 0, c = 'A'; i < numberOfProcesses; i++, c++)
	{
		p[i].name = c;
		p[i].arrivalTime = processdata.arrivaltimes[i];
		p[i].burstTime = processdata.bursttimes[i];
		p[i].remainingBurstTime = processdata.bursttimes[i];
		p[i].turnaroundTime = 0;
		p[i].waitTime = 0;

		// Variable for Completion status
		// Pending = 0
		// Completed = 1
		p[i].completed = 0;

		// Variable for sum of all Burst Times
		sum_burstTime += p[i].burstTime;
	}

	// Sorting the structure by arrival times
	sortByArrival(numberOfProcesses);

	// Set lower limit to response ratio
	float hrr = -9999;

	// Response Ratio Variable
	float temp;

	// Variable to store next process selected
	int currentprocess = -999;

	// Variables for current time and ime quantum
	int currenttime = 0;
	int quantum = 0;

	// To track number of completed processes
	int completedprocesses = 0;

	//To track total wait time of all ready processes
	int queueTotalWaitTime = 0;

	//To track number of ready processes in queue
	int queueCount = 0;

	//To track wt(running proc)/len(waiting procs) + bt(remaining)
	double currentProcScore = 0;

	// While loop to perform running of all processes.
	while (completedprocesses < numberOfProcesses)
	{
		//Calc total wait time of all queued processes
		queueTotalWaitTime = 0;
		queueCount = 0;
		for (int y = 0; y < numberOfProcesses; y++){
			//If waiting, add to queueTotalWaitTime
			if (p[y].arrivalTime <= runTime && p[y].completed != 1){
				if (y != currentprocess){
					queueTotalWaitTime += p[y].waitTime;
					queueCount++;
				}
			}

		}

		// This is debug code, leaving here in case need to check more shid
		// printf("Currentprocess: %d\n", currentprocess);
		// if (currentprocess >= 0){
		// 	printf("ProcName: %c\n", p[currentprocess].name);
		// 	printf("WT: %d\n", p[currentprocess].waitTime);
		// 	printf("QueueCount: %d\n", queueCount);
		// 	printf("BTLeft: %d\n", p[currentprocess].remainingBurstTime);
		// }

		//Do the actual check. If fail, process as usual
		//If succeed and ready proc wt is more, which to swap to?
		if (queueCount != 0){	//If queue == 0, a prog is running with no queue

		
			currentProcScore = (p[currentprocess].waitTime / queueCount) + p[currentprocess].remainingBurstTime;
			if ((queueTotalWaitTime > currentProcScore) || p[currentprocess].completed == 1){
				//swippity swappity to which one???
				//This is probably supposed to go outside of the HRR 

		
				// To reset response ratio for each iteration.
				hrr = -9999;
				// To determine which process to run
				for (i = 0; i < numberOfProcesses; i++)
				{
					// Checking if process has arrived and is Incomplete
					if (p[i].arrivalTime <= runTime && p[i].completed != 1)
					{
						// Calculating Response Ratio
						temp = (float)(p[i].burstTime + (runTime - p[i].arrivalTime)) / (float)p[i].burstTime;

						// Checking for Highest Response Ratio
						if (hrr < temp)
						{
							// Storing Response Ratio
							hrr = temp;

							// Storing Location
							currentprocess = i;
						}
						else if (hrr == temp)
						{
							if (p[currentprocess].burstTime > p[i].burstTime)
							{
								currentprocess = i;
							}
						}


					}
				}

			}
		}
		// else if (currentprocess == -999){		//This is solely here to account for if scheduling just started and only 1 proc is ready, but might not be needed
		// 	hrr = -9999;
		// 		// To determine which process to run
		// 		for (i = 0; i < numberOfProcesses; i++)
		// 		{
		// 			// Checking if process has arrived and is Incomplete
		// 			if (p[i].arrivalTime <= runTime && p[i].completed != 1)
		// 			{
		// 				// Calculating Response Ratio
		// 				temp = (float)(p[i].burstTime + (runTime - p[i].arrivalTime)) / (float)p[i].burstTime;

		// 				// Checking for Highest Response Ratio
		// 				if (hrr < temp)
		// 				{
		// 					// Storing Response Ratio
		// 					hrr = temp;

		// 					// Storing Location
		// 					currentprocess = i;
		// 				}
		// 				else if (hrr == temp)
		// 				{
		// 					if (p[currentprocess].burstTime > p[i].burstTime)
		// 					{
		// 						currentprocess = i;
		// 					}
		// 				}


		// 			}
		// 		}
		// }

		// Process to run has been selected. Increase wait time and turnaround time of all ready processes.
		for (j = 0; j < numberOfProcesses; j++)
		{
			if (p[j].arrivalTime <= runTime && p[j].completed != 1)
			{
				// Check if its not the current process
				if (j != currentprocess)
				{
					p[j].waitTime++;
					p[j].turnaroundTime++;
				}
			}
		}
		// To decrement the remaining burst time of current process and increase turnaround time.
		p[currentprocess].remainingBurstTime--;
		p[currentprocess].turnaroundTime++;

		// If process has 0 remaining burst time, count as completed.
		if (p[currentprocess].remainingBurstTime == 0)
		{
			p[currentprocess].completed = 1;
			completedprocesses++;
		}
		// Increase the runtime by 1
		runTime++;
	}

	// Print statement logic
	printf("\nName\tArrival Time\tBurst Time\tWaiting Time");
	printf("\tTurnAround Time");

	for (j = 0; j < numberOfProcesses; j++)
	{
		avgwaitTime += p[j].waitTime;
		avgturnaroundTime += p[j].turnaroundTime;
		printf("\n%c\t\t%d\t\t", p[j].name, p[j].arrivalTime);
		printf("%d\t\t%d\t\t", p[j].burstTime, p[j].waitTime);
		printf("%d", p[j].turnaroundTime);
		if (p[j].waitTime > maxwaitTime){
			maxwaitTime = p[j].waitTime;
		}
		if (p[j].turnaroundTime > maxturnaroundTime) {
			maxturnaroundTime = p[j].turnaroundTime;
		}
	}

	printf("\nAverage waiting time:%f\n", avgwaitTime / numberOfProcesses);
	printf("Maximum waiting time:%f\n", maxwaitTime);
	printf("Average Turn Around time:%f\n", avgturnaroundTime / numberOfProcesses);
	printf("Maximum Turn Around time:%f\n", maxturnaroundTime);
	return 0;
}