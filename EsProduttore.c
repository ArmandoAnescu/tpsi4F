#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#define BLOCK_DIM 1024
#define PROGRAM "./consumatore.exe"
int spawn(char program[], char *argument[]) // argument array di stringhe
{
    int p;
    p = fork();
    if (p < 0)
    {
        return -1;
    }
    else if (p != 0)
    {
        printf("Sono il padre spawn \n");
        printf("pid %d \n", getpid());
        return 0;
    }
    printf("Sono il figlio, pid %d \n", getpid());
    execv(program, argument);
    printf("ERRORE EXEC");
    abort();
}
int main(int argc, char *argv[])
{
    FILE *file;
    int fifo;
    unsigned char buffer[BLOCK_DIM];
    int n;
    char *argv[3];
    int a;
    printf("Sono padre main ossia il processo produttore, il mio PID=%d \n", getpid());
    if (argc != 3)
    {
        printf("Per mandare in esecuzione prod.exe devi inserire dal terminale \n");
        printf(" nome file origine.txt nome file destinazione.txt\n");
    }
    char *arg[3];
    arg[0] = (char *)malloc(strlen(PROGRAM) + 1);
    strcpy(arg[0], PROGRAM);
    arg[1] = (char *)malloc(strlen(argv[2]) + 1);
    strcpy(arg[0], argv[2]);
    arg[2] = NULL;
    if (spawn(PROGRAM, arg) < 0)
    {
        free(arg[0]);
        free(arg[1]);
        return 0;
    }
    printf("\n arg[0]=%s \n", arg[0]);
    if (mkfifo("myfifo", 0777) == -1)
    {
        if (errno != EEXIST)
        {
            printf("\nErrore apertura fifo\n");
        }
    }
    fifo = open("myfifo", O_WRONLY);
    if (fifo < 0)
    {
        printf("Errore creazione fifo \n");
        free(arg[0]);
        free(arg[1]);
        return 0;
    }
    file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        printf("Errore apertura file \n");
        free(arg[0]);
        free(arg[1]);
        close(fifo);
    }
    free(arg[0]);
    free(arg[1]);
    close(fifo);
    fclose(file);
    return 0;
}