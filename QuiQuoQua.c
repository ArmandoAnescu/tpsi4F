#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// il valoe della fork è intero
int p, p1, p2; // si tratta di una variabile intera che permette di gestire i processi padre e figlio
// p nel padre=PID del figlio mentre p del figlio = 0
int main()
{
    p = fork(); //(restituisce un valore intero) processo Padre genera il processo Figlio
    p1 = fork();
    p2 = fork();
    // se p<0 proccesso sus
    if (p > 0) // padre
    {
        printf("\n Sono il padre. p=%d PID=%d\n", p, getpid());
    }
    else if (p != 0) // figlio
    {
        printf("\n Sono il figlio QUI, il mio PID = %d", getpid());
    }
    else if (p1 != 0)
    {
        printf("\n Sono il figlio QUo, il mio PID = %d", getpid());
    }
    else if (p2 != 0)
    {
        printf("\n Sono il figlio QUa, il mio PID = %d", getpid());
    }
    return 0;
}