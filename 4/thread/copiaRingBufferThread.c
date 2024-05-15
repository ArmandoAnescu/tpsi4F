#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <stdbool.h>
#define BUFFER_SIZE 1024
#define BUFFER_DIM 64
#define nomeLettura "lettura.txt"
#define nomeScrittura "scrittura.txt"
typedef struct
{
    unsigned char buffer[BUFFER_SIZE];
    int n;
} BUFFER;
bool eof = false;
BUFFER ring_buffer[BUFFER_DIM];
int nBlock = 0;
int write_index = 0;
int read_index = 0;
pthread_mutex_t critical, mutex;
pthread_cond_t not_full, not_empty;
void *lettura(void *par)
{
    FILE *lettura = fopen(nomeLettura, "r");
    int i;
    int n;
    while (!feof(lettura))
    {
        pthread_mutex_lock(&critical);
        if (nBlock == BUFFER_DIM)
        {
            pthread_cond_wait(&not_full, &critical);
            pthread_cond_signal(&not_empty);
        }
        n = fread(ring_buffer[write_index].buffer, 1, BUFFER_SIZE, lettura);
        if (n > 0)
        {
            ring_buffer[write_index].n = n;
            write_index = (write_index + 1) % BUFFER_DIM;
            pthread_mutex_lock(&mutex);
            nBlock++;
            pthread_mutex_unlock(&mutex);
        }
        pthread_mutex_unlock(&critical);
    }
    eof = true;
    pthread_cond_signal(&not_empty);
    fclose(lettura);
    return (void *)0;
}
void *scrittura(void *par)
{
    FILE *scrittura = fopen(nomeScrittura, "w");
    int i = 0;
    while (!eof || nBlock > 0)
    {
        pthread_mutex_lock(&critical);
        if (nBlock > 0)
        {
            fwrite(ring_buffer[read_index].buffer, 1, ring_buffer[read_index].n, scrittura);
            read_index = (read_index + 1) % BUFFER_SIZE;
            pthread_mutex_lock(&mutex);
            nBlock--;
            pthread_mutex_unlock(&mutex);
        }
        else
        {
            pthread_cond_signal(&not_full);
            pthread_cond_wait(&not_empty, &critical);
        }
        pthread_mutex_unlock(&critical);
    }
    fclose(scrittura);
    return (void *)0;
}
int main(int argc, char *argv[])
{
    pthread_t threadLettura, threadScrittura;
    pthread_mutex_init(&critical, NULL);
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&not_empty, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_create(&threadLettura, NULL, &lettura, nomeLettura);
    pthread_create(&threadScrittura, NULL, &scrittura, nomeScrittura);
    pthread_join(threadLettura, NULL);
    pthread_join(threadScrittura, NULL);
    pthread_mutex_destroy(&critical);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_empty);
    pthread_cond_destroy(&not_full);
    return 0;
}