#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Page 45/79 of Part1-04 Process Concept 2

void catcher(int);

int main(void)
{
    int i;

    signal(SIGINT, catcher);

    for (i=0;i<100;++i){
        printf("Sleep call %d\n", i);
        sleep(1);
    }

    printf("Exiting.\n");
    exit(0);
}

void catcher(int signo){
    printf("Signal number %d is caught. \n", signo);
}