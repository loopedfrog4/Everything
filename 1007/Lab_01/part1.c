#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(void)
{
    printf("PID = %d\n", getpid());
    printf("PPID = %d\n", getpid());
    exit(EXIT_SUCCESS);
    
}