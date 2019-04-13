#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 3

void *busy_work(void *data)
{
    int i;
    size_t thread_num = (size_t)data;
    size_t result = 0;

    printf("Hello world! It's me - thread %zd\n", thread_num);

    for (i = 0; i < (10000*(thread_num+1)); i++)
    {
        result = result + random();
        usleep(1);
    }
    printf("result = %zd from thread %d\n", result, thread_num);
    
    pthread_exit((void*)0);
}

int main()
{
    size_t i;
    pthread_t threads[NUM_THREADS];

    for (i = 0; i < NUM_THREADS; i++) {
        printf("Creating thread %zd..\n", i);
        int error = pthread_create(&threads[i], NULL, busy_work, (void*)i);
        if (error != 0) {
            fprintf(stderr, "Error creating thread %zd: error: %d\n", i, error);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        size_t status = 0;
        if (1 == i)
        {
            pthread_cancel(threads[i]);
        }
        printf("Waiting for thread %d to finish..\n", i);
        int error = pthread_join(threads[i], (void**)&status);
        if (error != 0) {
            fprintf(stderr, "Error joining thread %zd: error: %d\n", i, error);
        }
        
        printf("Thread %zd status: %zd\n", i, status);
    }

    //pthread_exit(NULL);
    return 0;
}
