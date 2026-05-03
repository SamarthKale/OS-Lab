#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 5

int buffer[MAX];
int in = 0, out = 0;

sem_t empty, full, mutex;

// Producer
void* producer(void* arg)
{
    for (int i = 0; i < 10; i++)
    {
        int item = i + 1;

        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = item;
        printf("Produced: %d at %d\n", item, in);

        in = (in + 1) % MAX;

        sem_post(&mutex);
        sem_post(&full);
    }
    return NULL;
}

// Consumer
void* consumer(void* arg)
{
    for (int i = 0; i < 10; i++)
    {
        sem_wait(&full);
        sem_wait(&mutex);

        int item = buffer[out];
        printf("Consumed: %d from %d\n", item, out);

        out = (out + 1) % MAX;

        sem_post(&mutex);
        sem_post(&empty);
    }
    return NULL;
}

int main()
{
    pthread_t p, c;

    sem_init(&empty, 0, MAX);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}