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
    FILE *origine = fopen("memoryProcesses.txt", "rb");
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
        int n;
        char carattere[BUFFER_SIZE];
        printf("sono il padre pid:%d pid mio figliop=%d \n", getpid(), p);
        close(fd[0]);
        while ((n = fread(carattere, 1, sizeof(carattere), origine)) > 0)
        {
            write(fd[1], carattere, n);
        }
        fclose(origine);
        close(fd[1]);
        wait(p);
    }
    else // figlio
    {
        int n;
        char buffer[BUFFER_SIZE];
        FILE *destinazione = fopen("destinazione.txt", "wb");
        printf("Sono il figlio pid:%d, mio padre ha pid:%d \n", getpid(), getppid());
        close(fd[1]);
        while ((n = read(fd[0], buffer, sizeof(buffer))) > 0)
        {
            fwrite(buffer, 1, n, destinazione);
        }
        fclose(destinazione);
        close(fd[0]);
    }
    return 0;
}