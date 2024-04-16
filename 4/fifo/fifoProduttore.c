#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
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
    fd = open("sum", O_WRONLY); // fd=1 perchè abbiamo aperto la fifo in scrittura
    printf("Ho aperto la fifo \n");
    int num[5];
    srand(0);
    for (int i = 0; i < 5; i++)
    {
        num[i] = rand() % 6;
        printf("%d \n", num[i]);
    }
    for (int i = 0; i < 5; i++)
    {

        if (write(fd, num, sizeof(num)) == -1)
        {
            printf("write fifo fallita \n");
            return -1;
        }
    }
    printf("Ho scritto nella fifo \n");
    close(fd);
    return 0;
}