#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* padre conta da 0 a 19
   figlio conta da 0 a 9 */

int p;
int conta_padre, conta_figlio;

int main()
{
    p = fork();

    if (p < 0) // errore
    {
        printf("\nErrore: il figlio non è stato generato\n");
        exit(1);
    }
    else if (p > 0) // padre
    {
        printf("\nSono il padre. Il mio PID=%d. Mio figlio ha PID=%d \n", getpid(), p);
        for (conta_padre = 0; conta_padre <= 50; conta_padre++)
        {
            printf("conta padre \n%d\n", conta_padre);
        }
    }
    else // figlio
    {
        printf("\nSono il figlio. Mio padre ha PID=%d. Il mio PID=%d \n", getppid(), getpid());
        for (conta_figlio = 0; conta_figlio <= 20; conta_figlio++)
        {
            printf("conta figlio \n%d\n", conta_figlio);
        }
    }
    return 0;
}