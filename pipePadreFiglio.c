#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX  5
int main(int argc, char *argv[])
{
    int fd[2];
    int p;
    pipe(fd);
    p = fork();
    if (p != 0) // padre
    {

        int moltiplicatore;
        int numeri[MAX];
        close(fd[1]);
        printf("Ciao sono il padre, mio PID=%d, PID mio figlio= %d \n", getpid(), p);
        read(fd[0], numeri, sizeof(numeri));
        printf("Inserisci il numero che deve moltiplicare \n");
        scanf("%d", &moltiplicatore);
        for (int i = 0; i < MAX; i++)
        {
            printf("numero %d \n", numeri[i] * moltiplicatore);
        }
        close(fd[0]);
    }
    else // figlio
    {
        int numeri[MAX];
        close(fd[0]);
        printf("Ciao sono il figlio, mio PID=%d, PID mio padre= %d \n", getpid(), getppid());
        for (int i = 0; i < MAX; i++)
        {
            printf("Inserisci il %d numero \n", i + 1);
            scanf("%d", &numeri[i]);
        }
        write(fd[1], numeri, sizeof(numeri));
        close(fd[1]);
    }
    return 0;
}