#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
/*
Creare un programma che:
1 - crea un array di 10 numeri (tra questi inserire il numero otto in una posizione qualsiasi);
2 - crea un thread per ricercare il numero otto nella prima metà dell'array;
3 - crea un altro thread per ricercare il numero otto nella seconda metà dell'array.
Il thread che trova il numero otto deve stampare la posizione che occupa nell'array.
*/
#define LEN 10
int array[] = {1, 2, 3, 5, 6, 9, 12, 34, 65, 234, 1, 2, 3, 5, 6, 9, 12, 8, 65, 234, 1, 2, 3, 5, 6, 9, 12, 34, 65, 234, 1, 2, 3, 5, 6, 9, 12, 34, 65, 234};

void *ricerca(void *par)
{
    int *indice = (int *)par;
    for (int i =indice[0] ; i < indice[1]; i++)
    {
        if (array[i] == 8)
        {
            printf("Il numero si trova alla posizione %d \n", i + 1);
        }
    }
    pthread_exit(NULL);
    return (void *)0;
}

int main()
{
    int primaParte[] = {0, LEN / 2};
    int secondaParte[] = {LEN/2,LEN};
    pthread_t threadPrima, threadSeconda;
    pthread_create(&threadPrima, NULL, &ricerca, (int *)primaParte);
    pthread_create(&threadSeconda, NULL, &ricerca, (int *) secondaParte);
    pthread_join(threadPrima, NULL);
    pthread_join(threadSeconda, NULL);
    
    return 0;
}