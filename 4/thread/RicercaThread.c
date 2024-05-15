#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
/*
Creare un programma che:
1 - crea un array di 10 numeri (tra questi inserire il numero otto in una posizione qualsiasi);
2 - crea un thread per ricercare il numero otto nella prima metà dell'array;
3 - crea un altro thread per ricercare il numero otto nella seconda metà dell'array.
Il thread che trova il numero otto deve stampare la posizione che occupa nell'array.
*/
#define LEN 1000
int array;

void *ricerca(void *par)
{
    int *indice = (int *)par;
    for (int i = indice - 250; i < indice; i++)
    {
        if (array[i] == 8)
        {
            printf("Il numero si trova alla posizione %d \n", i + 1);
        }
    }
    pthread_exit(NULL);
    return (void *)0;
}
void *generazione(void *par)
{
    srand(time(0));
    for (int i = 0; i < LEN; i++)
    {
        array[i] = rand() % 501;
    }
    return (void *)0;
}
int main()
{
    int i = {250, 500, 750, 1000};
    pthread_t threadPrima, threadSeconda, threadTerza, threadQuarta, threadGenerazione;
    pthread_create(&threadGenerazione, NULL, &ricerca, NULL);
    pthread_create(&threadPrima, NULL, &ricerca, (int *)i[0]);
    pthread_create(&threadSeconda, NULL, &ricerca, (int *)i[1]);
    pthread_create(&threadTerza, NULL, &ricerca, (int *)i[2];
    pthread_create(&threadQuarta, NULL, &ricerca, (int *)i[3 ]);
    pthread_join(threadPrima, NULL);
    pthread_join(threadSeconda, NULL);
    pthread_join(&threadTerza, NULL);
    pthread_join(&threadQuarta, NULL);
    pthread_join(&threadGenerazione, NULL);
    return 0;
}