#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int fd[2];
    int p;
    int numeri[5];
    pipe(fd);
    p = fork();
    if (p != 0) // padre
    {
        int moltiplicatore;
        printf("Ciao sono il padre, mio PID=%d, PID mio figlio= %d \n", getpid(), p);
        close(fd[1]);
        read(fd[0], numeri, 20);
        printf("Inserisci il numero che deve moltiplicare \n");
        scanf("%d", &moltiplicatore);
        for (int i = 0; i < 5; i++)
        {
            printf("%d \n", numeri[i] * moltiplicatore);
        }
        close(fd[0]);
    }
    else // figlio
    {
        printf("Ciao sono il figlio, mio PID=%d, PID mio padre= %d \n", getpid(), getppid());
        close(fd[0]);
        for (int i = 0; i < 5; i++)
        {
            printf("Inserisci il %d numero", i + 1);
            scanf("%d", &numeri[i]);
        }
        write(fd[1], numeri, 20);
        close(fd[1]);
    }
    return 8;
}