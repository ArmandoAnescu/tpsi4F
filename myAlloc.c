#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char * nome[20];
    char *cognome[20];
    int *media;
} student_t;
void InserisciStud(student_t *stud[], int l)
{
    char nome[20];
    char cognome[20];
    int a;
    for (int i = 0; i < l; i++)
    {
        printf("Inserisci il nome dello studente \n");
        scanf("%s", nome);
        strcpy((*stud)->nome, nome);
        printf("Inserisci il cognome dello studente \n");
        scanf("%s", cognome);
        strcpy((*stud)->cognome, cognome);
        printf("Inserisci la media dello studente \n");
        scanf("%d",(*stud)->media);
    }
}
void VisualizzaStud(student_t *stud[], int l)
{
    for (int i = 0; i < l; i++)
    {
        printf("Nome: %s \n",(*stud)->nome);        
        printf("Cognome: %s \n",(*stud)->cognome);
        printf("media: %d \n",(*stud)->media);
    }
}
int main(int argc, char *argv[])
{
    int l = 3;
    student_t *stud[l];
    *stud = malloc(sizeof(student_t));
    InserisciStud(stud,l);
    VisualizzaStud(stud,l);
    free(stud); // memory de-allocation
    return 0;
}