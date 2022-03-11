#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define numberOfProcesses 1000

struct process{
    int processNum[numberOfProcesses];
    int arrivalTime[numberOfProcesses];
    int burstTime[numberOfProcesses];
    int ratio[numberOfProcesses];
};

float avgTurnAroundTime = 0.0;
float maxTurnAroundTime = 0.0;
float avgWaitTime = 0.0;
float maxWaitTime = 0.0;


int main () {
    FILE* fp;
    char  line[10];
    int count = 1;
    int i = 0;
    struct process process_arr;

    fp = fopen("testcase1.txt" , "r");
    // Read all line in txt file and store in process_arr
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        const char* arrival = strtok(line, " ");
        const char* burst = strtok(NULL, " ");
        printf("P %d\n Arrival Time %s\n Burst Time %s\n", count, arrival, burst);
        printf("\n");
        process_arr.processNum[i] = count;
        process_arr.arrivalTime[i] = atoi(arrival);
        process_arr.burstTime[i] = atoi(burst);
        count += 1;
        i += 1;
    }

    // Calculate ratio of all the stored processes
    for (int j = 0; j < numberOfProcesses; j++){
        process_arr.ratio[0] = 
    }
    return 0;
}