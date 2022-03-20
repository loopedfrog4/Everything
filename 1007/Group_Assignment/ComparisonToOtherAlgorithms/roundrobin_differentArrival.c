#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
# define numberOfProcesses 5

struct process{
    int processNum;
    int arrivalTime;
    int burstTime;
    int waitTime;
    int turnAroundTime;
    int completedTime;
    int completed; // 1 = Completed, 0 = Pending
}typedef process;

int main()
{

    FILE* fp;
    char  line[10];
    int count = 1;
    int j = 0;
    int sumBurstTime = 0;
    process process_arr[numberOfProcesses];
    process temp[numberOfProcesses];

    fp = fopen("testcase1.txt" , "r");
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        const char* arrival = strtok(line, " ");
        const char* burst = strtok(NULL, " ");
        process_arr[j].processNum = count;
        process_arr[j].arrivalTime = atoi(arrival);
        process_arr[j].burstTime = atoi(burst);
        process_arr[j].completed = 0;
        sumBurstTime += atoi(burst);
        count += 1;
        j += 1;
    }

    int i, total = 0, x, counter = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0;
    float average_wait_time, average_turnaround_time;
    
    x = numberOfProcesses;

    printf("Enter Time Quantum:");
    scanf("%d", &time_quantum);
    printf("Process \t Arrival Time \t Burst Time \t Turnaround Time \t Waiting Time\n");
    for(total = 0, i = 0; x != 0;)
    {
        if(temp[i].burstTime <= time_quantum && temp[i].burstTime > 0)
        {
            total = total + temp[i].burstTime;
            temp[i].burstTime = 0;
            counter = 1;
        }
        else if(temp[i].burstTime > 0)
        {
            temp[i].burstTime = temp[i].burstTime - time_quantum;
            total = total + time_quantum;
        }
        if(temp[i].burstTime == 0 && counter == 1)
        {
            x--;
            printf("Process %d \t\t %d \t\t %d \t\t %d \t\t\t %d\n", i + 1, process_arr[i].arrivalTime, process_arr[i].burstTime, total - process_arr[i].arrivalTime, total - process_arr[i].arrivalTime - process_arr[i].burstTime);
            wait_time = wait_time + total - process_arr[i].arrivalTime - process_arr[i].burstTime;
            turnaround_time = turnaround_time + total - process_arr[i].arrivalTime;
            counter = 0;
        }
        if(i == numberOfProcesses - 1)
        {
            i = 0;
        }
        else if(process_arr[i + 1].arrivalTime <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    average_wait_time = wait_time * 1.0 / numberOfProcesses;
    average_turnaround_time = turnaround_time * 1.0 / numberOfProcesses;
    printf("nnAverage Waiting Time:t%f", average_wait_time);
    printf("nAvg Turnaround Time:t%fn", average_turnaround_time);
    return 0;
}