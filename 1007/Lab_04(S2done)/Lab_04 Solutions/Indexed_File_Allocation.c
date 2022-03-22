#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define TOTAL_DISK_BLOCKS 32
#define TOTAL_DISK_INODES 8
int blockStatus[TOTAL_DISK_BLOCKS]; // free = 0
int blockList[TOTAL_DISK_BLOCKS - TOTAL_DISK_INODES]; // list of blocks of a file
 
struct file_table {
    char fileName[20];
        int fileSize;
        int blocks[TOTAL_DISK_BLOCKS - TOTAL_DISK_INODES];
    };
struct file_table fileTable[TOTAL_DISK_BLOCKS - TOTAL_DISK_INODES];
     
int AllocateBlocks(int Size) {
    int i = 0, count = 0, nextBlock = 0;
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
        if (nextBlock<TOTAL_DISK_BLOCKS) {
            if (blockStatus[nextBlock] == 0) {
                blockStatus[nextBlock] = 1;
                blockList[count] = nextBlock;
                count = count + 1;
            }
        }
    }
    if (count == Size) {
        return 0; // success
    }
    else {
        return 1; // not successful
    }
}
     
int main() {
    srand(1234);
    int i = 0, j = 0, numFiles = 0, ret = 0, a = 0, k = 0, l = 0, m = 0;
    char s[20];
    printf("File allocation method : INDEXED\n");
    printf("Total blocks: %d\n", TOTAL_DISK_BLOCKS);
    printf("File allocation start at block: %d\n", TOTAL_DISK_INODES);
    printf("File allocation end at block: %d\n", TOTAL_DISK_BLOCKS-1);
    printf("Size (kb) of each block: 1\n\n");
    printf("Enter no of files: ");
    scanf("%d", &numFiles);
    for(j = 0; j < numFiles; j++) {
        fflush(stdin);
        printf("\n\nEnter the name of file #%d: ", j+1);
        scanf("%s", s);
        fflush(stdin);
        printf("\nEnter the size (kb) of the file #%d: ", j+1);
        scanf(" %d", &a);
        strcpy(fileTable[j].fileName,s);
        fileTable[j].fileSize = a;
    }
    for (i = 0; i < numFiles; i++){
        ret = AllocateBlocks(fileTable[i].fileSize);
        for (k = 0; k < fileTable[i].fileSize; k++) {
            fileTable[i].blocks[k] = blockList[k];
        }
    }
    printf("\n\n%-20s%-20s%-20s\n", "FILE_fileName", "FILE_SIZE", "BLOCKS_OCCUPIED");
    for (l = 0; l < numFiles; l++){
        printf("%-20s%-20d%d", fileTable[l].fileName, fileTable[l].fileSize, fileTable[l].blocks[0]);
        for (m = 1; m < fileTable[l].fileSize; m++) {
            printf("-%d", fileTable[l].blocks[m]);
        }
        printf("\n");
    }
    return 0;
}

