// Resource Ref: https://www.geeksforgeeks.org/highest-response-ratio-next-hrrn-cpu-scheduling/

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
    int completedTime;
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

int findFirstArrivalTime(process arr[]){
    int posMin = 0;
    for (int i = 1; i < numberOfProcesses; i++){
        if (arr[posMin].arrivalTime > arr[i].arrivalTime){
            posMin = i;
        }
    }
    return arr[posMin].arrivalTime;
}

int FindMaxWaitingTime(process arr[]){
    int posMax = 0;
    for (int z = 1; z < numberOfProcesses; z++){
        if (arr[posMax].waitTime < arr[z].waitTime){
            posMax = z;
        }
    }
    return arr[posMax].waitTime;
}

float FindMaxTurnAroundTime(process arr[]){
    int posMax = 0;
    for (int x = 1; x < numberOfProcesses; x++){
        if (arr[posMax].turnAroundTime < arr[x].turnAroundTime){
            posMax = x;
        }
    }
    return arr[posMax].turnAroundTime;
}


int main () {
    FILE* fp;
    char  line[10];
    int count = 1;
    int i = 0;
    int sumBurstTime = 0;
    process process_arr[numberOfProcesses];

    fp = fopen("random.txt" , "r");
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        const char* arrival = strtok(line, " ");
        const char* burst = strtok(NULL, " ");
        process_arr[i].processNum = count;
        process_arr[i].arrivalTime = atoi(arrival);
        process_arr[i].burstTime = atoi(burst);
        process_arr[i].completed = 0;
        sumBurstTime += atoi(burst);
        count += 1;
        i += 1;
    }
    
    // Call helper method to sort array of processes based on arrival time
    sortByArrivalTime(process_arr);
    printf("\nProcess Number\tArrival Time\tBurst Time\tWaiting Time");
    printf("\tTurnAround Time");
    for (int t = process_arr[0].arrivalTime; t < sumBurstTime;) {
 
        // Set lower limit to response ratio
        float hrr = -9999;
 
        // Response Ratio Variable
        float temp;
 
        // Variable to store next process selected
        int loc;
        for (i = 0; i < numberOfProcesses; i++) {
 
            // Checking if process has arrived and is Incomplete
            if (process_arr[i].arrivalTime <= t && process_arr[i].completed != 1) {
 
                // Calculating Response Ratio
                temp = (process_arr[i].burstTime + (t - process_arr[i].arrivalTime) + (numberOfProcesses / 2)) / process_arr[i].burstTime;
 
                // Checking for Highest Response Ratio
                if (hrr < temp) {
 
                    // Storing Response Ratio
                    hrr = temp;
 
                    // Storing Location
                    loc = i;
                }
            }
        }
 
        // Updating time value
        t += process_arr[loc].burstTime;
 
        // Calculation of waiting time
        process_arr[loc].waitTime = t - process_arr[loc].arrivalTime - process_arr[loc].burstTime;
 
        // Calculation of Turn Around Time
        process_arr[loc].turnAroundTime = t - process_arr[loc].arrivalTime;
 
        // Sum Turn Around Time for average
        avgTurnAroundTime += process_arr[loc].turnAroundTime;
 
        // Updating Completion Status
        process_arr[loc].completed = 1;
 
        // Sum Waiting Time for average
        avgWaitTime += process_arr[loc].waitTime;
        printf("\n%d\t\t%d\t\t", process_arr[loc].processNum, process_arr[loc].arrivalTime);
        printf("%d\t\t%d\t\t", process_arr[loc].burstTime, process_arr[loc].waitTime);
        printf("%d\t", process_arr[loc].turnAroundTime);
    }

    printf("\nAverage Turn Around time:%f\n", avgTurnAroundTime / numberOfProcesses);
    printf("Max Turn Around time: %f\n", FindMaxTurnAroundTime(process_arr));
    printf("Average waiting time:%f\n", avgWaitTime / numberOfProcesses);
    printf("Max Waiting Time: %f\n", FindMaxWaitingTime(process_arr));

    return 0;
}