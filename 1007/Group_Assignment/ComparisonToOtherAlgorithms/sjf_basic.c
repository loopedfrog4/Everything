#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define numberOfProcesses 5
#define SWAP(T, a, b) do { T tmp = a; a = b; b = tmp; } while (0)

void sort_arrival_time(int arrival_time[],int process[],int burst_time[])
// Function is used to sort the processes on the basis of their arrival time.
// In case, two processes have same arrival time they will be placed next to each other.
{
  for(int i=0;i<numberOfProcesses;i++)
  {
    for(int j=i+1;j<numberOfProcesses;j++)
    {
      if(arrival_time[i]>arrival_time[j])
      {
        SWAP(int, process[i],process[j]);
        SWAP(int, arrival_time[i],arrival_time[j]);
        SWAP(int, burst_time[i],burst_time[j]);
        // Process id, arrival time as well as burst time of the processes are sorted inaccordance with arrival time.
      }
    }
  }
}

void sort_burst_time(int arrival_time[],int process[],int burst_time[])
// Function is used to sort the processes with same burst time according to their arrival time.
{
  for(int i=0;i<numberOfProcesses;i++)
  {
    for(int j=i+1;j<numberOfProcesses;j++)
    {
      if(arrival_time[i]==arrival_time[j])
      // Condition is checked if two processes have same arrival time.
      {
        if(burst_time[i]>burst_time[j])
        // In case the arrival time is same, the processes are compared according to their burst time and further sorted.
        {
          SWAP(int, process[i],process[j]);
          SWAP(int, arrival_time[i],arrival_time[j]);
          SWAP(int, burst_time[i],burst_time[j]);
        }
      }
    }
  }
}

void sjf_operations(int arrival_time[],int waiting_time[],int burst_time[],int turn_around_time[],int completion_time[])
// This function is used to calcuate waiting time and turn around time fot the processes.
{
  int temp;
  int value;

  completion_time[0] = arrival_time[0] + burst_time[0];
  turn_around_time[0] = completion_time[0] - arrival_time[0];
  waiting_time[0] = turn_around_time[0] - burst_time[0];
  // For the first process the completion time, waiting time an turn around time are initialised.

  for(int i=1;i<numberOfProcesses;i++)
  // Process from the second are iterated to till the last process in reached.
  {
    temp = completion_time[i-1];
    int low = burst_time[i];
    for(int j=i;j<numberOfProcesses;j++)
    {
      if(temp >= arrival_time[j] && low >=burst_time[j])
      // Completion time of previous process is compare with the arrival time of current process as well the burst time is compared.
      {
        low = burst_time[j];
        value = j;
      }
    }
    // completion_time[value] = temp + burst_time[value];
    // turn_around_time[value] = completion_time[value] - arrival_time[value];
    // waiting_time[value] = turn_around_time[value] - burst_time[value];
    completion_time[value] = temp + burst_time[value];
    turn_around_time[value] = completion_time[value] - arrival_time[value];
    waiting_time[value] = turn_around_time[value] - burst_time[value];
    // Value of completion time, waiting time and turn around time is calculated using formulae.
  }
}

int biggestWaitingTimeProcess(int arr[]){
    //Initialize min with first element of array.    
    int min = arr[0];
      
    //Loop through the array    
    for (int i = 0; i < numberOfProcesses; i++) {     
        //Compare elements of array with min    
        if(arr[i] > min){
            min = arr[i]; 
        }  
            
    }      
    return min;
}

int biggestTurnAroundTimeProcess(int arr[]){
    //Initialize min with first element of array.    
    int min = arr[0];
      
    //Loop through the array    
    for (int i = 0; i < numberOfProcesses; i++) {     
        //Compare elements of array with min    
        if(arr[i] > min){
            min = arr[i]; 
        }  
            
    }      
    return min;
}

void print_table(int process[],int burst_time[],int waiting_time[],int turn_around_time[],int arrival_time[])
// Table is printed which prints the calculated value as the output.
{
  printf("\n");

  printf("Process \t Arrival Time \t Burst Time \t Waiting Time \t Turn Around Time\n");
  float avg_wt = 0;
  float avg_tat = 0;
  for(int i=0;i<numberOfProcesses;i++)
  {
    avg_wt += waiting_time[i];
    avg_tat += turn_around_time[i];
    printf("%d \t\t %d \t\t %d \t\t %d \t\t %d\n", process[i], arrival_time[i], burst_time[i], waiting_time[i], turn_around_time[i]);
  }

  printf("Average waiting time of the processes is : %f\n", avg_wt/numberOfProcesses );
  printf("Max waiting time of the processes is : %d\n",biggestWaitingTimeProcess(waiting_time));
  printf("Average turn around time of the processes is : %f\n",avg_tat/numberOfProcesses);
  printf("Max turn around time of the processes is : %d\n",biggestTurnAroundTimeProcess(turn_around_time));

  printf("\n");
}

int main()
{
    int process[numberOfProcesses];
    int burst_time[numberOfProcesses];
    int waiting_time[numberOfProcesses];
    int completion_time[numberOfProcesses];
    int turn_around_time[numberOfProcesses];
    int arrival_time[numberOfProcesses];

    FILE* fp;
    char  line[10];
    int count = 1;
    int i = 0;

    fp = fopen("testcase3.txt" , "r");
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        const char* arrival = strtok(line, " ");
        const char* burst = strtok(NULL, " ");
        process[i] = count;
        arrival_time[i] = atoi(arrival);
        burst_time[i] = atoi(burst);
        count += 1;
        i += 1;
    }

  sort_arrival_time(arrival_time,process,burst_time);

  sort_burst_time(arrival_time,process,burst_time);

  sjf_operations(arrival_time,waiting_time,burst_time,turn_around_time,completion_time);

  print_table(process,burst_time,waiting_time,turn_around_time,arrival_time);

  return 0;
}
