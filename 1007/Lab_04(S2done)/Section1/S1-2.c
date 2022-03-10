#include <stdio.h>  
#include <stdlib.h> 
 
#define TOTAL_DISK_BLOCKS 32 
#define TOTAL_DISK_INODES 8  
int blockStatus[TOTAL_DISK_BLOCKS]; // free = 0 
int blockList[TOTAL_DISK_BLOCKS - TOTAL_DISK_INODES]; // list of blocks of a file 
 
struct file_table {
    char fileName[20];  
    int fileSize;  
    struct block *sb;  
}; 
struct file_table fileTable[TOTAL_DISK_BLOCKS - TOTAL_DISK_INODES]; 
 
struct block {  
    int blockNumber;  
    struct block *next;  
};  
 
int AllocateBlocks(int Size) { 
    
} 
 
void main()  
{  
    int i = 0, j = 0, numFiles = 0, nextBlock= 0, ret = 1;  
    char s[20]; struct block *temp; 
    --- 
    for (i = 0; i < numFiles; i++) {  
        --- 
        ret = AllocateBlocks(fileTable[i].fileSize); 
        --- 
    } 
--- 
//Seed the pseudo-random number generator used by rand() with the value seed 
srand(1234); 
--- 
}