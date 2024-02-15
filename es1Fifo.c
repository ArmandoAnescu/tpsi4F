#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>//header file
int main(int argc, char *argv[])
{
    // Dichiarazioni Var
    int fd;
    // int x=90 va dopo l'apertura della fifo
    // creazioni fifo
    if (mkfifo("myfifo1", 0777) == -1)
    {
        if (errno != EEXIST)
        {
            printf("errore nella creazione della fifo \n");
            exit(1);
        }
    }
    // apertura fifo in sola scrittura
    fd = open("myfifo1", O_WRONLY); // fd=1 perchè abbiamo aperto la fifo in scrittura
    printf("Ho aperto la fifo \n");
    int x = 90;
    if (write(fd, &x, sizeof(x)) == -1)
    {
        printf("write fifo fallita \n");
        return -1;
    }
    printf("Ho scritto nella fifo \n");
    close(fd);
    return 0;
}