#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
// thread POSIX, POSIX è uno standard, tutti i system unix like si basano su POSIX, Windows non lo è
void *stampaGiorno(void *par) // devo creare la "funzione" dove scrivo le istruzioni che deve eseguire il thread
{
    printf("buon giorno \n");
}
void *stampaSera(void *par)
{
    printf("buonasera \n");
}
void *stampaNotte(void *par)
{
    printf("buonanotte \n");
}
int main(int argc, char *argv[])
{
    pthread_t threadGiorno, threadSera, threadNotte;
    printf("Ciao \n");
    pthread_create(&threadGiorno, NULL, &stampaGiorno, NULL); // indirizzo,Null,indirizzo della minima U di es che viene svolta
    pthread_create(&threadSera, NULL, &stampaSera, NULL);
    pthread_create(&threadNotte, NULL, &stampaNotte, NULL);
    pthread_join(threadGiorno, NULL); //"Wait" per i thread, devi aspettare i thread perchè sono parte del processo
    pthread_join(threadSera, NULL);
    pthread_join(threadNotte, NULL);
    // printf("buon giorno \n");
    // printf("buonasera \n");
    // printf("buonanotte \n");
    return 0;
    // gcc exercise.c -o name.exe -lpthread
}