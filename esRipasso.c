#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Menu()
{
    int scelta;
    printf("\n-----------------------------------\n");
    printf("1) Stampa Vettore\n");
    printf("2) Vettore invertito\n");
    printf("3) Somma e media\n");
    printf("4) Stampa numeri pari\n");
    printf("5) Stampa numeri dispari\n");
    printf("6) Cerca numero\n");
    printf("7) Elimina un numero\n");
    printf("8) Alterna Vettore \n");
    printf("9) Ordina Vettore\n");
    printf("10) Esci dal programma\n");
    printf("-----------------------------------\n");
    printf("Inserisci una scelta:\n");
    scanf("%d", &scelta);
    if (scelta == 10)
    {
        return 0;
    }
    else
    {
        return scelta;
    }
}

void GeneraNumeri(int array[], int n) // genero i numeri casuali in base all'input dell'utente
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 501;
    }
}
void Scelta(int scelta, int array[], int n)
{
    switch (scelta)
    {
    case 1:
        StampaNumeri(array, n);
        break;
    case 2:
        StampaInverti(array,n);
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    default:
        break;
    }
}
void StampaNumeri(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Il %d numero è %d \n", i + 1, array[i]);
    }
}
void StampaInverti(int array[], int n){
    for (int i = n-1; i <= 0; i--)
    {
        printf("Il %d numero è %d \n", n-n + 1, array[i]);
    }
}
int main()
{
    int n;
    printf("Inserisci il numero di numeri da generare \n");
    scanf("%d", &n);
    int array[n];
    GeneraNumeri(array, n);
    int risultato = 1;
    do
    {
        risultato = Menu();
        if (risultato != 0)
        {
            Scelta(risultato, array, n);
        }
        else
        {
            break;
        }

    } while (1);
}
/*
Esercizio 1
Scrivere un programma in C che effettui, attraverso un menù, le seguenti operazione sugli array:
1) Visualizzi a video gli elementi dell’array inseriti o generati casualmente;
2) Visualizzi a video l’array invertito cioè sostituendo il primo elemento con l'ultimo , il secondo con il
penultimo e cosi via;
3) Visualizzi a video la somma e media degli elementi del vettore;
4) Visualizzi a video tutti i numeri pari;
5) Visualizzi a video tutti i numeri dispari;
6) Ricerchi un numero (letto in input) nell’array;
7) Elimini un elemento (letto in input) dell’array (se esistente);
8) Alterni (o scambi ) a due a due le posizioni del vettore: esempio
vettore: 1,2,3,4 vettore alternato: 2,1,4,3 (attenzione se lungo dispari);
9) Ordini il vettore (ordinamento a scelta).
*/