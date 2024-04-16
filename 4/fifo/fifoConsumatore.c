#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h> //header file
int main(int argc, char *argv[])
{
    // Dichiarazioni Var
    int fd;
    // int x=90 va dopo l'apertura della fifo
    // creazioni fifo
    // apertura fifo in sola scrittura
    fd = open("sum", O_RDONLY); // fd=1 perchè abbiamo aperto la fifo in scrittura
    printf("Ho aperto la fifo \n");
    int somma = 0;
    int num[5];
    for (int i = 0; i < 5; i++)
    {
        read(fd, &num[i], sizeof(num[i]));
    }
    for (int i = 0; i < 5; i++)
    {

        somma = num[i] + somma;
    }
    printf("La somma dei 5 numeri casuali è %d \n", somma);
    close(fd);
    return 0;
}