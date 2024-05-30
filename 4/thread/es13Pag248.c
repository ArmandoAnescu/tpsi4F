#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
int n;
#define BUFFER_DIM 1024
#define NUM_SLICES 16
typedef struct
{
    unsigned char buffer[BUFFER_DIM];
    int n;
} BUFFER;
BUFFER ring_buffer[NUM_SLICES];
int write_index = 0;
int read_index = 0;
int N_inseriti = 0;
int fineGenerazione = 0;
pthread_mutex_t mutex;
pthread_cond_t not_full, not_empty;
void *generazione(void *par)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        pthread_mutex_lock(&mutex);
        if (N_inseriti >= NUM_SLICES)
        {
            pthread_cond_wait(&not_empty, &mutex);
        }
        else
        {
            ring_buffer[write_index].buffer = rand() % 501;
            write_index = (write_index + 1) % NUM_SLICES;
            N_inseriti++;
        }
        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&mutex);
    }
    fineGenerazione = 1;
    pthread_exit(NULL);
}
void *scrittura(void *par)
{
    while (fineGenerazione == 0)
    {
        pthread_mutex_lock(&mutex);
        if (N_inseriti > 0)
        {
            printf("%d \n", ring_buffer[read_index].buffer);
            write_index = (write_index + 1) % NUM_SLICES;
            N_inseriti--;
        }
        else
        {
            pthread_cond_wait(&not_full, &mutex);
        }
        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
    pthread_t generaT, scriviT;
    if (argc != 2)
    {
        printf("Non hai inserito il numero di numeri \n");
        exit(-1);
    }
    n = atoi(argv[1]);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&generaT, NULL, &generazione, NULL);
    pthread_create(&scriviT, NULL, scrittura, NULL);

    pthread_cond_init(&not_empty, NULL);
    pthread_cond_init(&not_full, NULL);
    
    pthread_join(generaT, NULL);
    pthread_join(scriviT, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_empty);
    pthread_cond_destroy(&not_full);
    return 0;
}