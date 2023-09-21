#include <stdio.h>
#include <limits.h>
void Mostracontenuto(int dimensione, int numeri[])
{
    for (int i = 0; i < dimensione; i++)
    {
        printf("%d \n", numeri[i]);
    }
}
void InserisciInCoda(int *n, int numeri[])
{
    *n = *n + 2;
    scanf("%d", &numeri[*n]);
    *n = *n + 1;
}
int ModificaElemento(int n, int numeri[], int num)
{
    // for(int i=0;i<num;i++)
    // {
    //     if(numeri[i]==num)
    //     {
    //         scanf("%d",numeri[i]);
    //     }
    // }
    // return numeri;
}
void EliminaElemento(int n, int numeri[])
{
}
void Ricerca(int numeri[])
{
}
void InserisciInNPosizione(int num, int numeri[])
{
}
void ContenutoInverso(int numeri[])
{
}
int MAxValue(int numeri)
{
}
int main(int argc, char *argv[])
{
    int scelta, n = 0, num = 0, num2;
    int numeri[SHRT_MAX];
    do
    {
        printf("inserisci un numero \n");
        scanf("%d", &num);
        if (num == -1)
        {
            break;
        }
        numeri[n] = num;
        n++;
    } while (num != -1);
    do
    {
        printf("Inserisci \n [1] per mostrare l'array \n [2] per inserire un numero \n [3] modifcare elemento \n [4] eliminare elemento \n [5] ricerca \n [6] inserire elemento in n posizione \n [7] mostra contenuto ma inverso \n [8] max value array \n [0] esci \n");
        scanf("%d", &scelta);
        if (scelta == 1)
        {
            Mostracontenuto(n, numeri);
        }
        else if (scelta == 2)
        {
            printf("inserisci numero da inserire \n");
            InserisciInCoda(&n, numeri);
        }
        else if (scelta == 3)
        {
            printf("inserisci numero da modificare \n");
            scanf("%d", &num);
            ModificaElemento(num, numeri, n);
        }
        else if (scelta == 4)
        {
        }
        if (scelta == 5)
        {
        }
        if (scelta == 6)
        {
        }
        else if (scelta == 7)
        {
        }
        if (scelta == 8)
        {
        }
    } while (scelta != 0);
    return 0;
}

// una funzione per ogni punt, no printf nelle funzioni,nella funzione 6 il numero deve essere tra 0 e n;