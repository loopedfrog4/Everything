#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define BUFFER_SIZE 5

void enqueue();
int dequeue();
void show();
void *producer(void *threadId);
void *consumer(void *threadId);

int queue[BUFFER_SIZE];
int count = 0;
int numberOfArguments;
int mainProcessSleepTime;
int numberOfProducers;
int numberOfConsumers;
int numberOfThreads;

pthread_mutex_t mutex;


void enqueue(int num){
    if (count < BUFFER_SIZE){
        queue[count] = num;
        count++;
    }
}

int dequeue(){
    if (count > 0){
        int num = queue[0];
        int i;
        for (i = 0; i < count - 1; i++){
            queue[i] = queue[i + 1];
        }
        count--;
        return num;
    }
    
}

void *producer(void *threadId){
    
    
    while (1){
        pthread_mutex_lock(&mutex);
        // Produce the random number bounded between 1 to 999
        int rand_num = rand() % 1000;
        printf("Producer %ld inserted item %d\n", (long)threadId, rand_num);
        enqueue(rand_num);
        pthread_mutex_unlock(&mutex);
    }
}

void *consumer(void *threadId){
    

    while (1){
        pthread_mutex_lock(&mutex);
        int dequeue_num = dequeue();
        printf("Consumer %ld removed item %d\n", (long)threadId, dequeue_num);
        pthread_mutex_unlock(&mutex);
    }
}


int main(int argc, char *argv[]){

    // numberOfArguments = argc - 1;
    // mainProcessSleepTime = atoi(argv[1]);
    // numberOfProducers = atoi(argv[2]);
    // numberOfConsumers = atoi(argv[3]);
    numberOfArguments = 3;
    mainProcessSleepTime = 10;
    numberOfProducers = 3;
    numberOfConsumers = 2;
    int consumerCount = 0;
    numberOfThreads = numberOfProducers + numberOfConsumers;
    pthread_t workers[numberOfThreads];

    // Dynamically create producer threads
    for (int i = 0; i < numberOfThreads; i++){
        if (i % 2 == 0){
            if (pthread_create(&workers[i], NULL, producer, (void *)i+1) != 0){
                perror("Failed to create thread");
            }
        }else{
            if (pthread_create(&workers[i], NULL, consumer, (void *)consumerCount+1) != 0){
                perror("Failed to create thread");
            }
            consumerCount++;
        }
    }

    for (int i = 0; i < numberOfThreads; i++){
        if (pthread_join(workers[i], NULL) != 0){
            perror("Failed to join thread");
        }
    }

    
    return 0;
}