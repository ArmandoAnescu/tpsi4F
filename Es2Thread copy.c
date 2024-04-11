#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
// thread POSIX, POSIX è uno standard, tutti i system unix like si basano su POSIX, Windows non lo è
void *stampaGiorno(void *par) // devo creare la "funzione" dove scrivo le istruzioni che deve eseguire il thread
{
    printf("%s \n", (char *)par);
    return (void *)0;
}
void *stampaSera(void *par)
{
    printf("%s \n", (char *)par);
    return (void *)0;
}
void *stampaNotte(void *par)
{
    printf("%s \n", (char *)par);
    return (void *)0;
}
int main(int argc, char *argv[])
{
    pthread_t threadGiorno, threadSera, threadNotte;
    char *msg1 = "buongiorno";
    char *msg2 = "buonasera";
    char *msg3 = "buonanotte";
    printf("Ciao \n");
    pthread_create(&threadGiorno, NULL, &stampaGiorno, msg1); // indirizzo,Null,indirizzo della minima U di es che viene svolta
    pthread_create(&threadSera, NULL, &stampaSera, msg2);
    pthread_create(&threadNotte, NULL, &stampaNotte, msg3);
    pthread_join(threadGiorno, NULL); //"Wait" per i thread, devi aspettare i thread perchè sono parte del processo
    pthread_join(threadSera, NULL);
    pthread_join(threadNotte, NULL);
    // printf("buon giorno \n");
    // printf("buonasera \n");
    // printf("buonanotte \n");
    return 0;
    // gcc exercise.c -o name.exe -lpthread
}