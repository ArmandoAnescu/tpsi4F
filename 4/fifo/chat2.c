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
    int fd1;
    int fd2, p;
    char lettura[BUFFER_SIZE];
    char scrittura[BUFFER_SIZE];

    printf("Scrivi HALT per terminare la chat");
    p = fork();
    if (p != 0)
    {
        fd2 = open("lettura", O_WRONLY);

        while (1)
        {
            if (strcmp(scrittura, "HALT") == 0)
            {
                break;
            }
            printf("Chatter 2: ");
            scanf("%s", scrittura);
            write(fd2, scrittura, sizeof(scrittura));
        }
    }
    else
    {
        fd1 = open("scrittura", O_RDONLY);
        while (1)
        {
            read(fd1, lettura, sizeof(BUFFER_SIZE));
            printf("Chatter 1: %s \n", lettura);
            if (strcmp(lettura, "HALT") == 0)
            {
                break;
            }
        }
    }

    close(fd1);
    close(fd2);
    return 0;
}