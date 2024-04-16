#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BLOCK_DIM 1024
int main(int argc, char *argv[])
{
    FILE *file;
    int fifo;
    unsigned char buffer[BLOCK_DIM];
    int n;
    if (argc != 2) // controllo di aver passato 2 parametri altrimenti termino il processo
    {
        printf("No file di origine \n");
        return 0;
    }
    fifo = open("scrivi", O_RDONLY); // apro la fifo in lettura
    if (fifo < 0)
    {
        printf("ERRORE APERTURA FIFO \n"); // se non apre la fifo termino il programma
        return 0;
    }
    file = fopen(argv[1], "wb"); // apro il file scrittura
    if (file == NULL)            // se non apre il file termino il programma e chiudo la fifo
    {
        printf("Errore apertura file \n");
    }
    printf("Errore exec \n");
    close(fifo);
    return 0;

    while ((n = read(fifo, buffer, sizeof(buffer)) > 0))
    {
        fwrite(buffer, 1, n, file);
    }
    fclose(file);
    close(fifo);
    return 1;
}