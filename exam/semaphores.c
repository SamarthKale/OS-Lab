#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5

int buffer[N], in = 0, out = 0;
sem_t empty, full, mutex;

void *producer()
{
    for(int i = 1; i <= 10; i++)
    {
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = i;
        printf("P: %d\n", i);
        in = (in + 1) % N;

        sem_post(&mutex);
        sem_post(&full);
    }
}

void *consumer()
{
    for(int i = 1; i <= 10; i++)
    {
        sem_wait(&full);
        sem_wait(&mutex);

        printf("C: %d\n", buffer[out]);
        out = (out + 1) % N;

        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main()
{
    pthread_t p, c;

    sem_init(&empty, 0, N);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);
}