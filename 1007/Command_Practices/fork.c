#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include <unistd.h>
 
 

int main (int argc, char* argv[]) {
    int id = fork();
    if (id != 0){
        fork();
    }

    printf("Hello\n");
    return 0;
}