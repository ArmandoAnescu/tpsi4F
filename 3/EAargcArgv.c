#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int limite1, limite2, n, somma = 0, swap; // dichiaro le varibili limite 1 e 2 che serviranno nel scegliere i 5 numeri su cui fare la somma
    if (argc != 3)
    {
        printf("Non hai inserito i valori \n");
    }
    else
    {
        limite1 = atoi(argv[1]);
        limite2 = atoi(argv[2]);
        printf("Il limite 1 è %d \n", limite1); // se limite 1 e 2 saranno validi li mostro a schermo per far capire che sono validi
        printf("Il limite 2 è %d \n", limite2);
        if (limite1 > limite2) // qui controllo se limie 1 e maggiore di 2 per fare limite 1 il minore e limite 2 il maggiore per semplicità senza fare tutto un controllo nel secondo do while
        {
            swap = limite2;
            limite2 = limite1;
            limite1 = swap;
        }
        int conta = 0; // var conta serve a tener traccia dei numeri e far finrie il ciclo
        printf("Inserisci 5 numeri\n");
        do
        {
            printf("Inserisci il %d° numero \n", conta + 1); // chiedo di inserire i numeri
            scanf("%d", &n);
            if (n >= limite1 && n <= limite2)
            {
                somma = somma + n;
                conta++; // aumento conta nell'if altrimenti se un numero non si trova tra i 2 limite viene contato comunque e si riscvhia di non fare la somma dei 5 numeri
            }
        } while (conta < 5);
        printf("La somma è:\n %d", somma);
        return 0;
    }
}