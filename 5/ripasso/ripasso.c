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

void StampaNumeri(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Il %d numero è %d \n", i + 1, array[i]);
    }
}
void StampaInverti(int array[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        printf("Il %d numero è %d \n", n - n + 1, array[i]);
    }
}
void StampaMediaESomma(int array[], int n)
{
    int somma = 0;
    float media;
    for (int i = 0; i < n; i++)
    {
        somma = somma + array[i];
    }
    media = somma / n;
    printf("La somma è:%d, la media è:%1.f \n", somma, media);
}
void StampaPari(int array[], int n)
{
    printf("numeri pari \n");
    for (int i = 0; i < n; i++)
    {
        if (array[i] % 2 == 0)
        {
            printf(" %d \n", array[i]);
        }
    }
}
void StampaDispari(int array[], int n)
{
    printf("numeri dispari \n");
    for (int i = 0; i < n; i++)
    {
        if (array[i] % 2 != 0)
        {
            printf(" %d \n", array[i]);
        }
    }
}
int CercaNumero(int array[], int n)
{
    int cerca;
    printf("Che numero vuoi cercare? \n");
    scanf("%d", &cerca);
    for (int i = 0; i < n; i++)
    {
        if (array[i] == cerca)
        {
            printf("Numero trovato \n");
            return 0;
        }
    }
    printf("Numero non trovato \n");
    return -1;
}
int EliminaNumero(int array[], int n)
{
    int cerca;
    printf("Che numero vuoi eliminare? \n");
    scanf("%d", &cerca);
    for (int i = 0; i < n; i++)
    {
        if (array[i] == cerca)
        {
            for (int j = i; j < n; j++)
            {
                array[j] = array[j + 1];
            }
            n--;
            printf("Numero eliminato \n");
            return 0;
        }
    }
    printf("Numero non trovato \n");
    return -1;
}
void Scambio(int array[], int n)
{
    int support;
    for (int i = 0; i < n; i += 2)
    {
        support = array[i];
        array[i] = array[i + 1];
        array[i + 1] = support;
    }
}
void Ordinamento(int array[], int n)
{
    int support;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j]>array[j+1])
            {
                support = array[j];
                array[j] = j + 1;
                array[j + 1] = support;
            }
        }
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
        StampaInverti(array, n);
        break;
    case 3:
        StampaMediaESomma(array, n);
        break;
    case 4:
        StampaPari(array, n);
        break;
    case 5:
        StampaDispari(array, n);
        break;
    case 6:
        CercaNumero(array, n);
        break;
    case 7:
        EliminaNumero(array, n);
        break;
    case 8:
        Scambio(array, n);
        break;
    case 9:
        break;
    default:
        break;
    }
}
int main()
{
    int n;
    printf("Inserisci il numero di numeri da generare \n");
    scanf("%d", &n);
    int array[n];
    GeneraNumeri(array, n);
    int risultato ;
    do
    {
        
        if (Menu() != 0)
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