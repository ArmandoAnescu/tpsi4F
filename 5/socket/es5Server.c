/*
Esercizio 5
Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 1 stringa,
e dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client la stringa
ordinata alfabeticamente (eliminando i caratteri speciali).
*/
#include <stdio.h>      //std in-out
#include <stdlib.h>     //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h> //funz. accept+bind+listen
#include <sys/types.h>  //funz. accept
#include <netinet/in.h> //definiscono la struttura degli indirizzi
#include <string.h>     //funz. stringhe
#include <errno.h>      //gestioni errori connessione
#include <ctype.h>      //bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX

#define DIM 40
#define SERVERPORT 1313
void RiordinaStringa(char str[])
{
    int n=strlen(str);
    char swap;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                // Scambia i caratteri
                swap = str[j];
                str[j] = str[j + 1];
                str[j + 1] = swap;
            }
        }
    }
}
int main(int argc, char **argv)
{
    struct sockaddr_in servizio, addr_remoto; // record con i dati del server e del client
    int socketfd, soa, fromlen = sizeof(servizio);
    char str[DIM];
    char c;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    // poniamo il server in ascolto delle richieste dei client
    listen(socketfd, 10);
    for (;;)
    {
        printf("\n\nServer in ascolto... \n");
        fflush(stdout);
        soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
        // legge dal client
        read(soa, str, sizeof(str));
        RiordinaStringa(str);
        write(soa, &str, strlen(str));
        close(soa);
    }
    return 0;
}