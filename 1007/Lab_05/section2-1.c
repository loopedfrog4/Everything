#include<stdio.h>
void main()
{
    int pageNumbers[25], frameContents[25];
    int i = 0, j = 0, k = 0;
    int numPages = 0, numFrames = 0, totalPageFaults = 0;
    int minArrivalIndex = 0, min_count = 0, next =0;
    int framePageRepeatCount[25], arrivalIndex[25];
    printf("\n Page Replacement Method: Least Frequently Used (LFU) with FIFO");
    printf("\n Enter the number of pages in the page sequence: ");
    scanf("%d", &numPages);
    //numPages = 20;

    printf("\n Enter the page numbers in sequence as a string: ");
    // 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
    for (i = 0; i < numPages; i++){
        scanf("%d", &pageNumbers[i]);
    }
    
    printf("\nEnter the number of frames: ");
    scanf("%d", &numFrames);
    // 3

    for (i = 0; i < numFrames; i++){
        framePageRepeatCount[i] = -1;
        frameContents[i] = -1;
        arrivalIndex[i] = -1;
    }

    printf("\n The Page Replacement Process is\n");
    printf("\tREF STRING");
    for (j = 0; j < numFrames; j++){
        printf("\tPAGE_FRAME%d", j + 1);
    }
    printf("\tPAGE_FAULT_NUMBER\n");

    // First n, where n = numFrames, is always the same
    for (i = 0; i < numFrames; i++){
        frameContents[i] = pageNumbers[i];
        printf("\t %d \t \t", pageNumbers[i]);
        for (j = 0; j < numFrames; j++){
            printf("%d \t \t", frameContents[j]);
        }
        totalPageFaults++;
        printf("%d\n", totalPageFaults);
    }

    



    /* Find the occurance of page faults and the total number of page faults */
    printf("\n\n Total number of page faults using LFU with FIFO: %d \n", totalPageFaults);
}