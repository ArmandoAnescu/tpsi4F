#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#define BUFFER_SIZE 2048
int main(int argc, char *argv[])
{
    // Dichiarazioni Var
    int fd1;
    int fd2;
    char lettura[BUFFER_SIZE];
    char scrittura[BUFFER_SIZE];
    fd1 = open("scrittura", O_RDONLY);
    fd2 = open("lettura", O_WRONLY);
    printf("Scrivi HALT se vuoi finire la chat \n");
    do
    {
        read(fd1, lettura, sizeof(BUFFER_SIZE));
        printf("Chatter 1: %s \n",lettura);
        printf("chatter 2: ");
        scanf("%s", scrittura);
        write(fd2,scrittura,sizeof(scrittura));
    } while (strcmp(lettura, "HALT")!=0);
    close(fd1);
    close(fd2);
    return 0;
}