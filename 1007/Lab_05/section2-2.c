// Ref: https://www.programming9.com/programs/c-programs/285-page-replacement-programs-in-c
#include <stdio.h>

int n,nf;
int in[100];
int p[50];
int hit=0;
int i,j,k;
int pgfaultcnt=0;
 
void getData()
{
    printf("\n Page Replacement Method: LRU (Least Recently Used)\n");

    printf("\n Enter the number of pages in the page sequence: ");
    scanf("%d",&n);

    printf("\n Enter the page numbers in sequence as a string: ");
    for(i=0; i<n; i++)
        scanf("%d",&in[i]);

    printf("\n Enter the number of frames: ");
    scanf("%d",&nf);
}
 
void initialize()
{
    pgfaultcnt=0;
    for(i=0; i<nf; i++)
        p[i]=9999;
}
 
int isHit(int data)
{
    hit=0;
    for(j=0; j<nf; j++)
    {
        if(p[j]==data)
        {
            hit=1;
            break;
        }
 
    }
 
    return hit;
}
 
int getHitIndex(int data)
{
    int hitind;
    for(k=0; k<nf; k++)
    {
        if(p[k]==data)
        {
            hitind=k;
            break;
        }
    }
    return hitind;
}
 
void dispPages()
{
    for (k=0; k<nf; k++)
    {
        if(p[k]!=9999){
            printf("%d \t \t",p[k]);
        }else{
            printf("-1 \t \t");
        }
            
    }
    printf("%d\n", pgfaultcnt);
}
 
void dispPgFaultCnt()
{
    printf("\n\n Total number of page faults using LRU: %d \n", pgfaultcnt);
}
 
void lru()
{
    initialize();
 
    int least[50];

    printf("\n The Page Replacement Process is \n");
    printf("\tREF STRING");
    for (j = 0; j < nf; j++){
        printf("\tPAGE_FRAME_%d", j + 1);
    }
    printf("\tPAGE_FAULT_NUMBER\n");
    
    for(i=0; i<n; i++)
    {
 
        printf("\t%d \t \t",in[i]);
        // printf("\t %d \t \t", in[i]);
        if(isHit(in[i])==0)
        {
 
            for(j=0; j<nf; j++)
            {
                int pg=p[j];
                int found=0;
                for(k=i-1; k>=0; k--)
                {
                    if(pg==in[k])
                    {
                        least[j]=k;
                        found=1;
                        break;
                    }
                    else
                        found=0;
                }
                if(!found)
                    least[j]=-9999;
            }
            int min=9999;
            int repindex;
            for(j=0; j<nf; j++)
            {
                if(least[j]<min)
                {
                    min=least[j];
                    repindex=j;
                }
            }
            p[repindex]=in[i];
            pgfaultcnt++;
 
            dispPages();
        }
        else
            // printf("No page fault!");
            dispPages();
    }
    dispPgFaultCnt();
}
 


int main()
{
    getData();
    lru();
}