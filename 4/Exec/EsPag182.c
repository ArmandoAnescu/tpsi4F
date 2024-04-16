#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BLOCK_DIM 1024
#define PROGRAM "./EsPag183"
int spawn(char program[], char *argument[])//funzione che tramite la fork usa il figlio per genrare un altro processo
{
    int pid;
    pid = fork();
    if (pid < 0)
    {
        return -1;
    }
    if (pid > 0)
    {
        return 0;
    }
    execv(program, argument);
    abort();
}
int main(int argc, char *argv[])
{
    FILE *file;
    int fifo;//dichiaro le varie variabili
    unsigned char buffer[BLOCK_DIM];
    int n;
    char *arg[3];
    if (argc != 3)
    {
        printf("No file di origine \n");//controllo che l'utente abbia inserito tutti i parametri
        return 0;
    }
    arg[0] = (char *)malloc(strlen(PROGRAM) + 1);//do ad arg[0] il nome del programma
    strcpy(arg[0], PROGRAM);
    arg[1] = (char *)malloc(strlen(argv[2]) + 1);//passi il nome del file
    strcpy(arg[1], argv[2]);
    arg[2] = NULL;//parametro NULL che delimina la fine della riga di comando
    if (spawn(PROGRAM, arg) < 0)//evoco la funziona per generare l'altro processo
    {
        printf("Errore exec \n");
        free(arg[0]);//controllo che non ci siano errori altrimenti liberò la mem allocata e termino il processo
        free(arg[1]);
        return 0;
    }
    fifo = open("scrivi", O_WRONLY);//apro la fifo in lettura
    if (fifo < 0)//controllo che apra la fifo alrimenti ripeto gli stessi step di prima
    {
        printf("ERRORE APERTURA FIFO \n");
        free(arg[0]);
        free(arg[1]);
        return 0;
    }
    file = fopen(argv[1], "rb");//apro il file in lettura
    if (file == NULL)//controllo l'apertura del file, se non riesco ad aprirlo libero la mem allocata e chiudo la fifo
    {
        printf("Errore apertura file \n");
        printf("Errore exec \n");
        close(fifo);
        free(arg[0]);
        free(arg[1]);
        return 0;
    }
    while ((n = fread(buffer, 1, sizeof(buffer), file)) > 0)//leggo dal file e scrivo nella fifo ciò che ho letto
    {
        write(fifo, buffer, n);
    }
    fclose(file);//chiudo il fle e la fifo e libero la mem del file
    close(fifo);
    free(arg[0]);
    free(arg[1]);
    return 0;
}