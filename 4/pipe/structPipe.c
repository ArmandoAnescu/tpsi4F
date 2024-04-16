#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h> //int fd[2] + pipe(fd)
// parent fd [0]<---------<fd[1] child
// parent fd[1]>-------->fd[0] per far comunicare padre al figlio
#define BUFFER_SIZE 1024
typedef struct
{
    char nomeLibro[20];
    char nomeAutore[20];
    double prezzo;
} Libro;

int main(int argc, char *argv[])
{

    Libro libr[2];
    int p;
    int fd[2];
    if (pipe(fd) == -1) // funzione che crea la pipe+creazione pipe
    {
        printf("errore generazione pipe");
        exit(1);
    }
    p = fork();

    if (p != 0) // padre
    {
        for (int i = 0; i < 2; i++)
        {
            printf("Inserisci il nome del libro \n");
            scanf("%s", (libr[i]).nomeLibro);
            printf("Inserisci il nome dell'autore \n");
            scanf("%s", (libr[i]).nomeAutore);
            printf("Inserisci il prezzo del libro \n");
            scanf("%f", &(libr[i]).prezzo);
        }
        close(fd[0]);
        for (int i = 0; i < 2; i++)
        {
            write(fd[1], &libr[i], sizeof(libr[i]));
        }
        close(fd[1]);
        wait(p);
    }
    else // figlio
    {
        Libro libri[2];
        int n,k;
        printf("Sono il figlio pid:%d, mio padre ha pid:%d \n", getpid(), getppid());
        close(fd[1]);
        k=0;
        while ((n = read(fd[0], &libri[k], sizeof(Libro))) > 0)
        {
            printf("Libro numero %d, titolo:%s autore:%s prezo:%f \n",k+1,libri[k].nomeLibro,libri[k].nomeAutore,libr[k].prezzo);
            k++;
        }
        close(fd[0]);
    }
    return 0;
}