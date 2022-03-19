// // CPU Scheduling Method: FIFO / FCFS
// // Ref: 

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// #define numberOfProcesses 5
// #define swap(T, a, b) do { T tmp = a; a = b; b = tmp; } while (0)

// struct process{
//     int processNum;
//     int arrivalTime;
//     int burstTime;
//     int waitTime;
//     int turnAroundTime;
//     int completedTime;
//     int completed; // 1 = Completed, 0 = Pending
// }typedef process;

// void sort_arrival_time(process arr[]){
//     for(int i=0;i<numberOfProcesses;i++)
//     {
//         for(int j=i+1;j<numberOfProcesses;j++)
//         {
//             if(arr[i].arrivalTime>arr[j].arrivalTime)
//             {
//                 swap(int, arr[i].processNum,arr[j].processNum);
//                 swap(int, arr[i].arrivalTime,arr[j].arrivalTime);
//                 swap(int, arr[i].burstTime,arr[j].burstTime);
//                 // Process id, arrival time as well as burst time of the processes are sorted inaccordance with arrival time.
//             }
//         }
//     }
// }

// void sort_burst_time(process arr[])
// // Function is used to sort the processes with same burst time according to their arrival time.
// {
//     for(int i=0;i<numberOfProcesses;i++)
//     {
//         for(int j=i+1;j<numberOfProcesses;j++)
//         {
//             if(arr[i].arrivalTime==arr[j].arrivalTime)
//             // Condition is checked if two processes have same arrival time.
//             {
//                 if(arr[i].burstTime>arr[j].burstTime)
//                 // In case the arrival time is same, the processes are compared according to their burst time and further sorted.
//                 {
//                     swap(int, arr[i].processNum,arr[j].processNum);
//                     swap(int, arr[i].arrivalTime,arr[j].arrivalTime);
//                     swap(int, arr[i].burstTime,arr[j].burstTime);
//                 }
//             }
//         }
//     }
// }

// void sjf_operations(process arr[])
// // This function is used to calcuate waiting time and turn around time fot the processes.
// {
//     int temp;
//     int value;

//     arr[0].completedTime = arr[0].arrivalTime + arr[0].burstTime;
//     arr[0].turnAroundTime = arr[0].completedTime - arr[0].arrivalTime;
//     arr[0].waitTime = arr[0].turnAroundTime - arr[0].burstTime;
//     // For the first process the completion time, waiting time an turn around time are initialised.

//     for (int i = 0; i < numberOfProcesses; i++){
//         printf("Process: %d\n", arr[i].processNum);
//         printf("Arrival Time: %d\n", arr[i].arrivalTime);
//         printf("Burst Time: %d\n", arr[i].burstTime);
//         printf("Completed Time: %d\n", arr[i].completedTime);
//         printf("Wait Time: %d\n", arr[i].waitTime);
//         printf("\n");
//     }

//     for(int i=1;i<numberOfProcesses;i++)
//     // Process from the seconf are iterated to till the last process in reached.
//     {
//     temp = arr[i-1].completedTime;
//     int low = arr[i].burstTime;
//     for(int j=i;j<numberOfProcesses;j++)
//     {
//         if(temp >= arr[j].arrivalTime && low >= arr[j].burstTime)
//         // Completion time of previous process is compare with the arrival time of current process as well the burst time is compared.
//         {
//         low = arr[j].burstTime;
//         value = j;
//         }
//     }
//     arr[value].completedTime = temp + arr[value].burstTime;
//     arr[value].turnAroundTime = arr[value].completedTime - arr[value].arrivalTime;
//     arr[value].waitTime = arr[value].turnAroundTime - arr[value].burstTime;
//     // Value of completion time, waiting time and turn around time is calculated using formulae.
    
//     printf("\n");

//     for (int i = 0; i < numberOfProcesses; i++){
//         printf("Process: %d\n", arr[i].processNum);
//         printf("Arrival Time: %d\n", arr[i].arrivalTime);
//         printf("Burst Time: %d\n", arr[i].burstTime);
//         printf("Wait Time: %d\n", arr[i].waitTime);
//         printf("Turnaround Time: %d\n", arr[i].turnAroundTime);
//         printf("\n");
//     }

//     }
// }

// void print_table(process arr[])
// // Table is printed which prints the calculated value as the output.
// {
//     printf("\n");

//     printf("Process \t Arrival Time \t Burst Time \t Waiting Time \t Turn Around Time\n");
//     for(int i=0;i<numberOfProcesses;i++)
//     {
    
//         printf("%d \t\t %d \t\t %d \t\t %d \t\t %d\n", arr[i].processNum, arr[i].arrivalTime, arr[i].burstTime, arr[i].waitTime, arr[i].turnAroundTime);
//     }

//     printf("\n");
// }

// int main () {
//     FILE* fp;
//     char  line[10];
//     int count = 1;
//     int i = 0;
//     int sumBurstTime = 0;
//     process process_arr[numberOfProcesses];

//     fp = fopen("testcase2.txt" , "r");
//     while (fgets(line, sizeof(line), fp) != NULL)
//     {
//         const char* arrival = strtok(line, " ");
//         const char* burst = strtok(NULL, " ");
//         process_arr[i].processNum = count;
//         process_arr[i].arrivalTime = atoi(arrival);
//         process_arr[i].burstTime = atoi(burst);
//         process_arr[i].completed = 0;
//         sumBurstTime += atoi(burst);
//         count += 1;
//         i += 1;
//     }

//     sort_arrival_time(process_arr);
//     sort_burst_time(process_arr);
//     sjf_operations(process_arr);
//     print_table(process_arr);

//     return 0;

    
    

// }


// CPU Scheduling Method: FIFO / FCFS
// Ref: 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define numberOfProcesses 5
#define swap(T, a, b) do { T tmp = a; a = b; b = tmp; } while (0)

struct process{
    int processNum;
    int arrivalTime;
    int burstTime;
    int waitTime;
    int turnAroundTime;
    int completedTime;
    int completed; // 1 = Completed, 0 = Pending
}typedef process;

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

process lowestArrivalTimeProcess(process arr[]){
    //Initialize min with first element of array. 
    process j = arr[0];   
    int min = j.arrivalTime;
      
    //Loop through the array    
    for (int i = 0; i < numberOfProcesses; i++) {     
        //Compare elements of array with min    
        if(arr[i].arrivalTime < min){
            min = arr[i].arrivalTime;
            j = arr[i]; 
        }  
            
    }      

    return j;
}

process biggestArrivalTimeProcess(process arr[]){
    //Initialize min with first element of array. 
    process j = arr[0];   
    int min = j.arrivalTime;
      
    //Loop through the array    
    for (int i = 0; i < numberOfProcesses; i++) {     
        //Compare elements of array with min    
        if(arr[i].arrivalTime > min){
            min = arr[i].arrivalTime;
            j = arr[i]; 
        }  
            
    }      
    return j;
}

void sjf(process arr[]){
    process lowestArrivalProcess = biggestArrivalTimeProcess(arr);
    
    printf("\n");

}

int main () {
    FILE* fp;
    char  line[10];
    int count = 1;
    int i = 0;
    int sumBurstTime = 0;
    process process_arr[numberOfProcesses];

    fp = fopen("testcase3.txt" , "r");
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

    sortByArrivalTime(process_arr);
    sjf(process_arr);

    return 0;
}