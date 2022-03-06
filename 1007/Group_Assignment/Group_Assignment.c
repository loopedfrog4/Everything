#include <stdio.h> 
#define numberOfProcesses 5

struct process{
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

    char* fileName = "testcase1.txt";

    int c;
    FILE *file;
    file = fopen("testcase1.txt", "r");
    // if (file) {
    //     while ((c = getc(file)) != EOF)
    //         putchar(c);
    //     fclose(file);
    // }

    int temp;
    fscanf("testcase1.txt", "%d", &temp);
    //Now scan all the line inside the text
    int i;
    for (i = 0; i < numberOfProcesses; i++) {
        fscanf(file, "%d %d\n", &process_array[i].burstTime, &process_array[i].arrivalTime);
        printf("%d %d\n", process_array[i].burstTime, process_array[i].arrivalTime);
    }
    


    return 0;
}