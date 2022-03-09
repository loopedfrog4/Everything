#include <stdio.h> 
#define numberOfProcesses 5

struct process{
    int processNum;
    int arrivalTime;
    int burstTime;
};

struct process process_array[numberOfProcesses];

int burstTime[numberOfProcesses];
int arrivalTime[numberOfProcesses];

float avgTurnAroundTime = 0.0;
float maxTurnAroundTime = 0.0;
float avgWaitTime = 0.0;
float maxWaitTime = 0.0;

int main () {


    int c;
    FILE *file;
    file = fopen("testcase1.txt", "r");
    // if (file) {
    //     while ((c = getc(file)) != EOF)
    //         fscanf(file, "%d %d\n", &process_array[i].burstTime, &process_array[i].arrivalTime);
    //         printf("%d %d\n", process_array[i].burstTime, process_array[i].arrivalTime);
    //     fclose(file);
    // }

    int temp;
    fscanf(file, "%d", &temp);
    //Now scan all the line inside the text
    int i;
    for (i = 0; i < numberOfProcesses; i++) {
        fscanf(file, "%d %d\n", &process_array[i].burstTime, &process_array[i].arrivalTime);
        
    }
    
    
    printf("%d", process_array[0].arrivalTime);
    printf("%d", process_array[0].burstTime);

    return 0;
}