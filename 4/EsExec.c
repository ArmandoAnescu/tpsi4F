#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    printf("IL MIO PID =%d \n",getpid());
    execl("./Ciao","Ciao",NULL);
    return 0;
}