#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int global1 = 130;

int main(int argc, char *argv[])
{
    printf("lezione memoria processo linux \n");
    printf("ciao \n");
    int a;
    while (1)
    {
        printf("%d\n",getpid());
        printf("%p\n",&a);
        sleep(10);
    }

    return 0;
}