#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define numberOfProcesses 5

struct process{
    int processNum;
    int arrivalTime;
    int burstTime;
    int waitTime;
    int turnAroundTime;
    float ratio;
    int completed; // 1 = Completed, 0 = Pending
}typedef process;

float avgTurnAroundTime = 0.0;
float maxTurnAroundTime = 0.0;
float avgWaitTime = 0.0;
float maxWaitTime = 0.0;

// Sort processes based on arrival time
void sortByArrivalTime(process arr[]){
    int i, j;

    process temp;
    
    // Selection Sort
    for (i = 0; i < numberOfProcesses - 1; i++) {
        for (j = i + 1; j < numberOfProcesses; j++) {
 
            // Check for lesser arrival time
            if (arr[i].arrivalTime > arr[j].arrivalTime) {
 
                // Swap earlier process to front
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main () {
    FILE* fp;
    char  line[10];
    int count = 1;
    int i = 0;
    process process_arr[numberOfProcesses];

    fp = fopen("testcase3.txt" , "r");
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        const char* arrival = strtok(line, " ");
        const char* burst = strtok(NULL, " ");
        // printf("P %d\n Arrival Time %s\n Burst Time %s\n", count, arrival, burst);
        // printf("\n");
        process_arr[i].processNum = count;
        process_arr[i].arrivalTime = atoi(arrival);
        process_arr[i].burstTime = atoi(burst);
        count += 1;
        i += 1;
    }
    
    // Call helper method to sort array of processes based on arrival time
    sortByArrivalTime(process_arr);
    
    // Print All Processes
    for (int z = 0; z < numberOfProcesses; z++){
        printf("P%d\n", process_arr[z].processNum);
        printf("Arrival: %d\n", process_arr[z].arrivalTime);
        printf("Burst: %d\n", process_arr[z].burstTime);
        printf("\n");
    }

    return 0;
}