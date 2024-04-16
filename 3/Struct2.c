#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int const lunghezza = 3;
typedef struct
{
    char nomeLibro[20];
    char autore[30];
    float prezzo;

} Libri;
void Inserisci(Libri *libreria[])
{
    for (int i = 0; i < lunghezza; i++)
    {
        printf("Inserisci il nome del libro \n");
        scanf("%s", libreria[i]->nomeLibro);
        printf("Inserisci il nome dell'autore \n");
        scanf("%s", libreria[i]->autore);
        printf("Inserisci il prezzo del libro \n");
        scanf("%f",&libreria[i]->prezzo);
    }
}
void Visualizza(Libri *libreria[])
{
    for (int i = 0; i < lunghezza; i++)
    {
        printf("Il %d° libro è: %s \n", i + 1, libreria[i]->nomeLibro);
        printf("l'autore del %d° libro è: %s \n", i + 1, libreria[i]->autore);
        printf("Il prezzo del %d° libro è: %f \n", i + 1, libreria[i]->prezzo);
    }
}
void ApplicaSconto(Libri *libreria[])
{
    int sconto;
    printf("Di quanto vuoi lo sconto? Scrivilo senza il simbolo percentuale");
    scanf("%d", &sconto);
    for (int i = 0; i < lunghezza; i++)
    {
        libreria[i]->prezzo = (libreria[i]->prezzo * sconto) / 100;
    }
}
int main(int argc, char argv [])
{
    Libri *libreria[lunghezza];
    for (int i = 0; i < lunghezza; i++)
    {
        libreria[i] = malloc(sizeof(Libri)); // Memory ALLOCation
    }
    Inserisci(libreria);
    printf("\n");
    Visualizza(libreria);
    printf("\n");
    ApplicaSconto(libreria);
    printf("\n");
    Visualizza(libreria);
    for (int i = 0; i < lunghezza; i++)
    {
        free(libreria[i]);
    }
    return 0;
}