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
    int p;
    printf("Inserisci il nome \n");
    scanf("%s", stud.nome);
    printf("Inserisci il cognome \n");
    scanf("%s", stud.cognome);
    printf("Inserisci l'eta \n");
    scanf("%d", &stud.eta);
    printf("Studente Nome: %s Cognome: %s eta:%d \n", stud.nome, stud.cognome, stud.eta);
    p = fork();
    if (p != 0) // padre
    {
        int status;
        // int fd = open("passaStud", O_WRONLY);
        // write(fd, &stud, sizeof(stud));
        printf("IL MIO PID =%d \n", getpid());
        wait(status);
    }
    else if (p == 0)
    {
        printf("Hey \n");
        char str[20];
        sprintf(str,"%d",stud.eta);
        execl("./LeggiStud", stud.nome, stud.cognome,str,NULL);
    }
    else
    {
        printf("Errore fork \n");
        exit(-1);
    }

    return 0;
}