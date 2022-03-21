#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define numberOfProcesses 10

int main() 
{
    int a[numberOfProcesses],b[numberOfProcesses],x[numberOfProcesses],i,j,smallest,count=0,time;
    int n = numberOfProcesses;
    double avg=0,tt=0,end;

    FILE* fp;
    char  line[10];
    int count2 = 1;
    int i2 = 0;

    fp = fopen("testcase1.txt" , "r");
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        const char* arrival = strtok(line, " ");
        const char* burst = strtok(NULL, " ");
        a[i2] = atoi(arrival);
        b[i2] = atoi(burst);
        x[i2] = b[i2];
        count2 += 1;
        i2 += 1;
    }

    b[numberOfProcesses]= 9;

    for(time=0;count!=n;time++)
    {
        smallest=numberOfProcesses;
        for(i=0;i<n;i++)
        {
            if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
            smallest=i;
        }
        b[smallest]--;
        if(b[smallest]==0)
        {
            count++;
            end=time+1;
            avg=avg+end-a[smallest]-x[smallest];
            tt= tt+end-a[smallest];
        }
    }
    printf("\n\nAverage waiting time = %lf\n",avg/n);
    printf("Average Turnaround time = %lf",tt/n);
    return 0;
}