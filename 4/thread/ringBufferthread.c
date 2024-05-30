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
int read_index=0;
int write_index=0;

void *lettura(void *par)
{
    char *nomeFile = (char *)par;
    FILE *lettura = fopen(nomeFile, "r");
    if(lettura==NULL)
    {
        printf("Errore creazione file");
    }
    int n;
    while (!feof(lettura))
    {
        while (nBlock >= BUFFER_DIM);
        n = fread(ring_buffer[write_index].buffer, 1, BUFFER_SIZE, lettura);
        if (n > 0)
        {
            ring_buffer->n=n;
            write_index=(write_index+1)%BUFFER_DIM;
            nBlock++;
        }
    }
    eof = true;
    return (void *)0;
}
void *scrittura(void *par)
{
    char *nomeFile = (char *)par;
    FILE *scrittura = fopen(nomeFile, "w");
    while (!eof || nBlock > 0)
    {
        if (nBlock > 0)
        {
            fwrite(ring_buffer[read_index].buffer, 1, ring_buffer[read_index].n, scrittura);
            read_index=(read_index+1)%BUFFER_DIM;
            nBlock--;
        }
    }
    return (void *)0;
}
int main(int argc, char *argv[])
{
    pthread_t threadLettura, threadScrittura;
    pthread_create(&threadLettura, NULL, &lettura, nomeLettura);
    pthread_create(&threadScrittura, NULL, &scrittura, nomeScrittura);
    pthread_join(threadLettura, NULL);
    pthread_join(threadScrittura, NULL);
    // free(ring_buffer);
    return 0;
}