#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 512
#define SERVERPORT 1313

int main(int argc, char **argv)
{
    struct sockaddr_in servizio;
    int socketfd, cond;
    char stringa[DIM],strAlfabetica[DIM];
    char c;
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    printf("Inserisci la stringa\n");
    scanf("%s", stringa);
    write(socketfd, stringa, strlen(stringa)+1);
    
    read(socketfd, strAlfabetica, sizeof(strAlfabetica));
    printf("La stringa in ordine alfabetica %s\n",strAlfabetica);
    close(socketfd);
    return 0;
}