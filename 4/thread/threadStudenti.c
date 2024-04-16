#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
/*
Creare un programma che :
1- chiede i dati di uno studente (nome,cognomome, classe,media);
2- crea un thread per stampare a video i dati inseriti;
3- crea un secondo thread per stampare su un file di testo i dati inseriti.
*/
typedef struct
{
    char nome[30];
    char cognome[30];
    int classe;
    double media;
} Studente;

void *stampaStudente(void *par)
{
    Studente *stud = (Studente *)par;
    printf("Nome: %s \n", stud->nome);
    printf("Cognome: %s \n", stud->cognome);
    printf("media:%2.f \n", stud->media);
    printf("Classe:%d \n", stud->classe);
    return (void *)0;
}
void *fileStudente(void *par)
{
    Studente *stud = (Studente *)par;
    FILE *file;
    file = fopen("Studente.txt", "w");
    fprintf(file, "%s %s media:%2.f classe:%d", stud->cognome, stud->cognome, stud->media, stud->classe);
    fclose(file);
    return (void *)0;
}
int main()
{
    Studente *stud = malloc(sizeof(Studente));
    pthread_t threadStampa, threadFile;
    char nome[20];
    char cognome[20];
    printf("Inserisci il nome \n");
    scanf("%s", nome);
    printf("Inserisci il cognome \n");
    scanf("%s", cognome);
    strcpy((*stud).nome, nome);
    strcpy((*stud).cognome, cognome);
    printf("inserisci la media \n");
    scanf("%lf", &stud->media);
    printf("inserisci la classe \n");
    scanf("%d", &stud->classe);
    pthread_create(&threadStampa, NULL, &stampaStudente, stud);
    pthread_create(&threadFile, NULL, &fileStudente, stud);
    pthread_join(threadStampa, NULL);
    pthread_join(threadFile, NULL);
    free(stud);
    return 0;
}