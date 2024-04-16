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
int len = 10;

void *ricercaPrimaParte(void *par)
{
    int *array = (int *)par;
    for (int i = 0; i < (len / 2); i++)
    {
        if (array[i] == 8)
        {
            printf("Il numero si trova alla psozione %d \n", i + 1);
        }
    }
    return (void *)0;
}
void *ricercaSecondaParte(void *par)
{
    int *array = (int *)par;
    for (int i = len / 2; i < len; i++)
    {
        if (array[i] == 8)
        {
            printf("Il numero si trova alla psozione %d \n", i + 1);
        }
    }
    return (void *)0;
}
int main()
{
    int array[10] = {1, 2, 3, 5, 8, 9, 12, 34, 65, 234};
    pthread_t threadPrima, threadSeconda;
    pthread_create(&threadPrima, NULL, &ricercaPrimaParte, (int *)array);
    pthread_create(&threadSeconda, NULL, &ricercaSecondaParte, (int *)array);
    pthread_join(threadPrima, NULL);
    pthread_join(threadSeconda, NULL);
    return 0;
}