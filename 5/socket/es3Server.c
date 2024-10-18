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
int Palindroma(char str[])
{
    int len=strlen(str);
    char newStr[len+1];
    newStr[len]='\0';
    for (int i = 0; i <len; i++)
    {
        newStr[i] = str[len-1-i];
    }
    printf("%s \n",newStr);
    if (strcmp(str, newStr) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main(int argc, char **argv)
{
    struct sockaddr_in servizio, addr_remoto; // record con i dati del server e del client
    int socketfd, soa, fromlen = sizeof(servizio);
    char str[DIM];
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    // poniamo il server in ascolto delle richieste dei client
    listen(socketfd, 10);
    for (;;)
    {
        printf("\n\nServer in ascolto...");

        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&addr_remoto, &fromlen);
        // legge dal client
        read(soa, str, sizeof(str));
        printf("Stringa ricevuta: %s\n", str);
        int cond=Palindroma(str);
        write(soa, &cond, sizeof(cond));
        close(soa);
    }
    return 0;
    return 0;
}