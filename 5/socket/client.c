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
    int socketfd, nVocali, nConsonanti;
    char stringa[DIM];
    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));
    printf("Inserisci la stringa\n");
    scanf("%s", stringa);
    // scrivo sulla socket
    write(socketfd, stringa, sizeof(stringa));
    // leggo dal server
    read(socketfd, &nVocali, sizeof(nVocali));
    printf("\nNumero vocali: %d", nVocali);
    read(socketfd, &nConsonanti, sizeof(nConsonanti));
    printf("\nNumero vocali: %d", nConsonanti);
    // chiudo il client
    close(socketfd);
    
    return 0;
}