#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 3

void enqueue();
int dequeue();
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
sem_t semEmpty;
sem_t semFull;

// Method to add number to back of queue
void enqueue(int num){
    queue[count] = num;
    count++;
    
}

// Method to remove number from back of queue
int dequeue(){
    int num = queue[count-1];
    count--;
    return num;
}

void *producer(void *threadId){
    while (1){
        sleep(rand() % 3);
        sem_wait(&semEmpty);
        pthread_mutex_lock(&mutex);
        // Produce the random number bounded between 1 to 999
        int rand_num = rand() % 1000;
        printf("Producer %ld inserted item %d\n", (long)threadId, rand_num);
        enqueue(rand_num);
        pthread_mutex_unlock(&mutex);
        sem_post(&semFull);
    }
}

void *consumer(void *threadId){
    

    while (1){
        sem_wait(&semFull);
        pthread_mutex_lock(&mutex);
        int dequeue_num = dequeue();
        printf("Consumer %ld removed item \t%d\n", (long)threadId, dequeue_num);
        pthread_mutex_unlock(&mutex);
        sem_post(&semEmpty);
        sleep(rand() % 3);
    }
}


int main(int argc, char *argv[]){

    numberOfArguments = argc - 1;
    mainProcessSleepTime = atoi(argv[1]);
    numberOfProducers = atoi(argv[2]);
    numberOfConsumers = atoi(argv[3]);

    printf("Number of arguments =  %d\n", argc-1);
    printf("Main Process sleep time =  %d\n", mainProcessSleepTime);
    printf("Number of producer(s) =  %d\n", numberOfProducers);
    printf("Number of consumer(s) =  %d\n", numberOfConsumers);

    int consumerCount = 0;
    numberOfThreads = numberOfProducers + numberOfConsumers;
    pthread_t workers[numberOfThreads];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&semEmpty, 0, numberOfThreads);
    sem_init(&semFull, 0, 0);

    // Dynamically create producer & consumer threads
    for (int i = 0; i < numberOfThreads; i++){
        if (i < numberOfProducers){
            if (pthread_create(&workers[i], NULL, producer, (void *)i+1) != 0){
                perror("Failed to create thread");
            }else{
                printf("Producer %d thread created successfully\n", i+1);
            }
        }else{
            if (pthread_create(&workers[i], NULL, consumer, (void *)consumerCount+1) != 0){
                perror("Failed to create thread");
            }else{
                printf("Consumer %d thread created successfully\n", consumerCount+1);
            }
            consumerCount++;
        }
    }

    for (int i = 0; i < numberOfThreads; i++){
        if (pthread_join(workers[i], NULL) != 0){
            perror("Failed to join thread");
        }
    }

    sleep(mainProcessSleepTime);
    printf("Awakened");
    sem_destroy(&semEmpty);
    sem_destroy(&semFull);
    pthread_mutex_destroy(&mutex);
    printf("Number of remaining items on buffer = %d\n", sizeof(queue) / sizeof(int));
    return 0;
}