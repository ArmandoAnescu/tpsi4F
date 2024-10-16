#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 40
#define SERVERPORT 1313
int main(int argc, char **argv)
{
    struct sockaddr_in servizio, addr_remoto; // record con i dati del server e del client
    int socketfd, soa, fromlen = sizeof(servizio);
    char str[DIM], newstr[DIM];
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(socketfd,(struct sockaddr*)&servizio,sizeof(servizio));
    // poniamo il server in ascolto delle richieste dei client 
    listen(socketfd,10);
    for (; ;)
    {
        printf("\n\nServer in ascolto...");

        fflush(stdout);

        soa=accept(socketfd,(struct sockaddr*)&addr_remoto,&fromlen);
        //legge dal client
        read(soa,str,sizeof(str));
        
        printf("Stringa ricevuta: %s\n",str);
        strcpy(newstr,toupper(str));
        printf("Stringa inviata : %s\n",newstr);
        write(soa, newstr, strlen(newstr));
        close(soa);
    }
    return 0;
}