// CPU Scheduling Method: FIFO / FCFS
 
#include <stdio.h> 
 
int main () {

    // Initialise necessary variables from specifications, arrival time not included since all processes arrives at T0
    int numProcesses = 0, i = 0, j = 0, prevBurstTime = 0;
    int burstTime[10], backupBurstTime[10], waitTime[10] = {0}, turnAroundTime[10];
    float avgWaitTime = 0.0, avgTurnAroundTime = 0.0;

    // Get user's input of how many processes to calculate for the FCFS algorithm
    // Get use to input burst time for each process
    printf("\n\t Enter the no of processes: "); 
    scanf("%d", &numProcesses); 
    for (i = 0; i < numProcesses; i++) 
    { 
        printf("\n\t Enter Burst Time for process %d: ", i + 1); 
        scanf("%d", &burstTime[i]); 
        backupBurstTime[i] = burstTime[i]; 
    } 

    // Initialise first process to have 0 turn around time
    turnAroundTime[0] = backupBurstTime[0];
    // Calculate wait time & turnaround time for each process from secondary element onwards
    for (i = 1; i < numProcesses; i++){
            
        j = i;
        prevBurstTime += backupBurstTime[j-1];
        waitTime[i] += prevBurstTime;
        turnAroundTime[i] = backupBurstTime[i] + waitTime[i];

    }

    printf("\n\t PROCESS\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\n"); 
    for (i = 0; i < numProcesses; i++) 
        printf("\t P%d \t %d \t\t %d \t\t %d \t\t\t %d \n",  i + 1, backupBurstTime[i], waitTime[i], turnAroundTime[i]); 
        
    // Calculate total wait time and total turnaround time 
    for (i = 0;i < numProcesses; i++){
        avgWaitTime += waitTime[i];
        avgTurnAroundTime += turnAroundTime[i];
    }



    /*Calculate and print the ‘average waiting time’,  
    ‘average turn-around-time’, and 'average response time' */ 
    printf("\n\t The Average Waiting time: %.2f\n", avgWaitTime / numProcesses); 
    printf("\n\t The Average Turnaround time: %.2f\n", avgTurnAroundTime / numProcesses); 

    return 0;
}