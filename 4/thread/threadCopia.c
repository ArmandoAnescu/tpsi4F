#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define BUFFER_SIZE 1024
#define nomeLettura "sium.txt"
#define nomeScrittura "banana.txt"
int scrivi = 0;
int fine = 1;
char buffer[BUFFER_SIZE];
void *lettura(void *par)
{
    char *nomeFile = (char *)par;
    FILE *lettura = fopen(nomeFile, "r");
    if (lettura == NULL)
    {
        return (void *)0;
    }
    while (fgets(buffer, BUFFER_SIZE, lettura) != NULL)
    {
    }
    if (fclose(lettura) != 0)
    {
        printf("Errore nella chiusura del file\n");
        exit(1);
    }
    fine = 0;
    return (void *)0;
}
void *scrittura(void *par)
{
    char *nomeFile = (char *)par;
    FILE *scrittura = fopen(nomeFile, "w");
    if (scrittura == NULL)
    {
        return (void *)0;
    }
    while (fine != 0)
    {

        fprintf(scrittura, "%s", buffer);
    }
    if (fclose(scrittura) != 0)
    {
        printf("Errore nella chiusura del file\n");
        exit(1);
    }
    return (void *)0;
}
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("non hai inserito tutti i parametri \n");
        exit(-1);
    }
    pthread_t threadLettura, threadScrittura;
    pthread_create(&threadLettura, NULL, &lettura, nomeLettura);
    pthread_create(&threadScrittura, NULL, &scrittura, nomeScrittura);
    pthread_join(threadLettura, NULL);
    pthread_join(threadScrittura, NULL);
}