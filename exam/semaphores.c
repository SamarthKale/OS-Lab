#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define N 10

int buffer[N], in = 0, out = 0, count = 0;
pthread_mutex_t mutex;

// Producer
void* producer(void* arg)
{
    for(int i = 0; i < N; i++)
    {
        int item = rand() % 100;

        pthread_mutex_lock(&mutex);

        while(count == N);  // wait if full

        buffer[in] = item;
        printf("Produced: %d\n", item);

        in = (in + 1) % N;
        count++;

        pthread_mutex_unlock(&mutex);

        sleep(1);
    }
    return NULL;
}

// Consumer
void* consumer(void* arg)
{
    for(int i = 0; i < N; i++)
    {
        pthread_mutex_lock(&mutex);

        while(count == 0);  // wait if empty

        int item = buffer[out];
        printf("Consumed: %d\n", item);

        out = (out + 1) % N;
        count--;

        pthread_mutex_unlock(&mutex);

        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t p, c;
    srand(time(0));

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}