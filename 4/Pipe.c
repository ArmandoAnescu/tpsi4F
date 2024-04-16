#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h> //int fd[2] + pipe(fd)
// parent fd [0]<---------<fd[1] child
// parent fd[1]>-------->fd[0] per far comunicare padre al figlio
#define BUFFER_SIZE 1024
int main(int argc, char *argv[])
{
    int fd[2]; // array descrittore che descrive in lettura o scrittura
    char Buffer[BUFFER_SIZE];
    if (pipe(fd) == -1) // funhzione che crea la pipe+creazione pipe
    {
        printf("errore generazione pipe");
        exit(1);
    }
    int p = fork();
    if (p < 0)
    {
        printf("Errore generazione file");
        exit(1);
    }
    if (p > 0) // padre
    {
        printf("sono il padre pid:%d pid mio figliop=%d \n", getpid(), p);
        close(fd[0]); // padre deve scrivere nella pipe
        const char *messaggio = "Buona fortuna";
        // write ritorna un valore pos se tutto ok altrimenti negativi
        if (write(fd[1], messaggio, strlen(messaggio)) < 0)
        {
            printf("Errore scrittura pipe \n");
            exit(1);
        }
        close(fd[1]);
        wait(p);
    }
    else // figlio
    {
        printf("Sono il figlio pid:%d, mio padre ha pid:%d \n", getpid(), getppid());
        close(fd[1]); // figlio deve leggee nella pipe
        // legge il messaggio e lo salva dove vuoi
        if (read(fd[0], Buffer, BUFFER_SIZE) < 0)//la pipe è sincrona cioè il figlio aspetta finche ilpadre o qualcuno non invia un messaggio(sincrona la domanda)
        {
            printf("Errore lettura pipe");
            exit(1);
        }
        Buffer[14]='\0';
        printf("Messaggio: %s \n", Buffer);
        close(fd[0]);
    }
    return 0;
}