#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 40
#define SERVERPORT 1313
int main(int argc, char **argv)
{

    struct sockaddr_in servizio;
    int socketfd;
    char stringa[DIM],stringaMaiusc[DIM];
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    printf("Inserisci la stringa\n");
    scanf("%s", stringa);
     //scrivo sulla socket
    write(socketfd,stringa,sizeof(stringa));
    //leggo dal server
    read(socketfd,stringa,sizeof(stringa));
    printf("\nStringhe ricevute: %s",stringa);
    //chiudo il client
    close(socketfd);
    return 0;

}