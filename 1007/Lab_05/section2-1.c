// Ref: http://nitcselabprograms.blogspot.com/p/c-program-for-lfu-page-replacement.html
#include <stdio.h>
void print(int frameno,int frame[])
{
    int j;
    for(j=0;j<frameno;j++)
        printf("%d \t \t",frame[j]);
}         
int main()
{
    int i,j,k,n,page[25],frameno,frame[25],move=0,flag,count=0,count1[25]={0}, repindex,leastcount;
    float rate;
    printf("\n Page Replacement Method: Least Frequently Used (LFU) with FIFO");

    printf("\n Enter the number of pages in the page sequence: ");
    scanf("%d",&n);

    printf("\n Enter the page numbers in sequence as a string: ");
    for(i=0;i<n;i++)
        scanf("%d",&page[i]);

    printf("\nEnter the number of frames: ");
    scanf("%d",&frameno);

    for(i=0;i<frameno;i++)
        frame[i]=-1;

    printf("\n The Page Replacement Process is \n");
    printf("\tREF STRING");
    for (j = 0; j < frameno; j++){
        printf("\tPAGE_FRAME_%d", j + 1);
    }
    printf("\tPAGE_FAULT_NUMBER\n");

    for(i=0;i<n;i++)
    {
        printf("\t %d \t \t",page[i]);
        flag=0;
        for(j=0;j<frameno;j++)
        {
            if(page[i]==frame[j])
            {
                flag=1;
                count1[j]++;
                print(frameno,frame);
                printf("%d\n", count);
                break;
            }
        }
        if(flag==0&&count<frameno)
        {
            frame[move]=page[i];
            count1[move]=1;
            move=(move+1)%frameno;
            count++;
            print(frameno,frame);
            printf("%d\n", count);
        }
        else if(flag==0)
        {
            repindex=0;
            leastcount=count1[0];
            for(j=1;j<frameno;j++)
            {
                if(count1[j]<leastcount)
                {
                    repindex=j;
                    leastcount=count1[j];
                }
            }
            
            frame[repindex]=page[i];
            count1[repindex]=1;
            count++;
            print(frameno,frame);
            printf("%d\n", count);
        }
    }
    
    printf("\n\n Total number of page faults using LFU with FIFO: %d \n", count);
    return 0;
}