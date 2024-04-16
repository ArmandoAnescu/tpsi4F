#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    printf("%s \n",argv[0]);
    printf("Il mio pid 2.0 è %d\n", getpid());
    return 0;
}