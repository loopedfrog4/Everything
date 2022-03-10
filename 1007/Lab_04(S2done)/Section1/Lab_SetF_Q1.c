#include <stdio.h>  
#include <stdlib.h>  
 
#define TOTAL_DISK_BLOCKS 32 
#define TOTAL_DISK_INODES 6  

int blockStatus[TOTAL_DISK_BLOCKS]; // free = 0  
int blockStart; 
 
struct file_table {  
    char fileName[20];  
    int startBlock; 
    int fileSize; 
    int allotStatus; 
}; 
struct file_table fileTable[TOTAL_DISK_BLOCKS - TOTAL_DISK_INODES]; 
 
int AllocateBlocks(int Size) { 
    int i = 0, count = 0, inList = 0, nextBlock = 0; 
    int allocStartBlock = TOTAL_DISK_INODES; 
    int allocEndBlock = TOTAL_DISK_BLOCKS - 1; 
 
    // check whether sufficient free blocks are available 
    for (i = 0; i < (TOTAL_DISK_BLOCKS - TOTAL_DISK_INODES); i++) 
        if (blockStatus[i] == 0) 
            count++; 
    if (count < Size) 
        return 1;  // not enough free blocks     
 
    count = 0; 
    while (count < Size) { 
        nextBlock = (rand() % (allocEndBlock - allocStartBlock + 1)) + allocStartBlock;  
        for (i = nextBlock; i < (nextBlock + Size); i++) 
        { 
            if (blockStatus[i] == 0) 
                count = count + 1; 
            else { 
                count = 0; 
                break; 
            } 
        } 

    }             
    blockStart = nextBlock; 
 
    if (count == Size)  
        return 0; // success 
    else 
        return 1; // not successful 
}

void main()  {  
    int i =0, j = 0, numFiles = 0, nextBlock = 0, ret = 1;  
    char s[20];

    
    printf("File Allocation Method: SEQUENTIAL\n");
    printf("Total blocks: %d\n", TOTAL_DISK_BLOCKS);
    printf("File Allocation start at block: %d\n", TOTAL_DISK_INODES);
    printf("File Allocation end at block: %d\n", TOTAL_DISK_BLOCKS - 1);
    printf("Size (kb) of each block: %d\n", 2);
    printf("\n");
    printf("Enter no of files: ");
    scanf("%d", &numFiles);
    printf("\n");

    for(i = 0; i < numFiles; i++) {  
        printf("Enter the name of file #%d: ", i+1);
        scanf("%s", fileTable[i].fileName);
        printf("Enter the size (kb) of file #%d: ", i+1);
        scanf("%d", &fileTable[i].fileSize);
        printf("\n");
        ret = AllocateBlocks(fileTable[i].fileSize);
        if (ret != 0){
            printf("Fail");
            exit(0);
        }
        
        fileTable[i].startBlock = blockStart;
        for (j = blockStart; j < (blockStart + fileTable[i].fileSize); j++){
            blockStatus[j] = 1;
        }


    }

    //Seed the pseudo-random number generator used by rand() with the value seed 
    srand(654); 

    printf("FILE_fileName \t FILE_SIZE \t BLOCKS_OCCUPIED\n");
    for(i = 0; i < numFiles; i++) {  
        
        printf("%s \t %d \t", fileTable[i].fileName, fileTable[i].fileSize);
        for (j = fileTable[i].startBlock; j < (fileTable[i].startBlock + fileTable[i].fileSize); j++){
            printf("%d-", j);
        }
        printf("\n");
    } 

}