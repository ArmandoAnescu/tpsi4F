#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
    typedef struct
    {
        char nome[20];
        char cognome[20];
        int eta;
    } Studente;
    Studente stud;
    printf("Sono il figlio. Il mio pid %d \n", getpid());
    strcpy(stud.nome, argv[0]);
    strcpy(stud.cognome, argv[1]);
    stud.eta=atoi(argv[2]);
    printf("Studente Nome: %s Cognome: %s eta:%d \n",stud.nome,stud.cognome,stud.eta);
    return 0;
}