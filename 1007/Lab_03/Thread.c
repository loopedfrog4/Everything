#include <stdio.h>
#include <pthread.h>
#define BUFFER_SIZE 5


void *producer(void *args){
    while (1){
        // Produce the random number bounded between 1 to 999
        int rand_num = rand() % 1000;


    }
}

void *consumer(void *args){
    while (1){
        
    }
}


int main(int argc, char *argv[]){
    printf("In main thread\n");
    return 0;
}