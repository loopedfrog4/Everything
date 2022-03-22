#include <stdio.h>

int checkIfArrayHasSpecificValue(int val, int arr[], int lengthOfArr){
     
    int isElementPresent = 0;
     
    for (int i = 0; i < lengthOfArr; i++) {
        if (arr[i] == val) {
            isElementPresent = 1;
            break;
        }
    }

    if (isElementPresent == 0){
        return 0;
    }else{
        return 1;
    }
}

void main()
{
    int pageNumbers[25], frameContents[25];
    int counter = 0, i = 0, j = 0, k = 0;
    int numPages = 0, numFrames = 0, totalPageFaults = 0;
    int frameNumber = 0;
    printf("\n Page Replacement Method: FIFO");
    printf("\n Enter the number of pages in the page sequence: ");
    // 20
    scanf("%d", &numPages);
    printf("\n Enter the page numbers in sequence as a string: ");
    // 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
    for (i = 0; i < numPages; i++){
        scanf("%d", &pageNumbers[i]);
    }
    printf("\n Enter the number of frames: ");
    // 3
    scanf("%d", &numFrames);

    printf("\n The Page Replacement Process is \n");
    printf("\tREF STRING");
    for (j = 0; j < numFrames; j++){
        printf("\tPAGE_FRAME_%d", j + 1);
    }
    printf("\tPAGE_FAULT_NUMBER\n");

    for (i = 0; i < numFrames; i++){
        frameContents[i] = -1;
    }

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

    // Counter for if 1) have fault 2) have no fault when printing
    int noPageFaultCounter = 0;
    int yesPageFaultCounter = 0;
    j = 0; // var to restart at Frame 1 when last insert is at Frame N, where n = numFrames
    // Continue from n + 1, where n = numFrames, until end of sequence  string
    for (i = totalPageFaults; i < numPages; i++){
        printf("\t %d \t", pageNumbers[i]);
        // check if page is already in frame
        if (checkIfArrayHasSpecificValue(pageNumbers[i], frameContents, numFrames) == 1){ // Page is in frame already, so no page fault
            for (noPageFaultCounter = 0; noPageFaultCounter < numFrames; noPageFaultCounter++){
                printf("\t%d \t", frameContents[noPageFaultCounter]);
            }
            printf("\t \n");
            continue;
        }else{ // page not in frame, page fault occurs
            frameContents[j] = pageNumbers[i];
            j++;
            totalPageFaults++;
            for (yesPageFaultCounter = 0; yesPageFaultCounter < numFrames; yesPageFaultCounter++){
                printf("\t%d \t", frameContents[yesPageFaultCounter]);
            }
            printf("\t%d\n", totalPageFaults);
        }
        
        if (j >= numFrames){
            j = 0;
        }
    }
        

    /* Find the occurance of page faults and the total number of page faults */
    printf("\n\n Total number of Page Faults using FIFO: %d \n", totalPageFaults);
}