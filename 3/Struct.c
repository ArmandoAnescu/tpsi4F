#include <stdio.h>
#include <stdlib.h>
struct Punti
{
    int x;
    int y;///definisco la struct punti con x,y,z le coordinate intere
    int z;
};
void stampa_punto(struct Punti coordinate)
{

    printf("\n x:%d \n y:%d \n z:%d", coordinate.x, coordinate.y, coordinate.z);//printf che scrive le coordinate
}
struct Punti punto_modificato(struct Punti coordinate)
{
    struct Punti newCordinata;
    newCordinata.x = coordinate.x + 1;//assegno a new coordinata il valore di coordinata +1 e poi ritorno il risultato
    newCordinata.y = coordinate.y + 1;
    newCordinata.z = coordinate.z + 1;
    return newCordinata;
}
int main(int argc, char *argv[])
{
    struct Punti coordinata;//dichiaro le 2 variabili struct
    struct Punti coordinata2;
    printf("Inserisci la coordinata x \n");//chiedo le variabili
    scanf("%d", &coordinata.x);//leggo le coordinate
    printf("Inserisci la coordinata y \n");
    scanf("%d", &coordinata.y);
    printf("Inserisci la coordinata z \n");
    scanf("%d", &coordinata.z);
    stampa_punto(coordinata);//passo per valore cooordinata e la stampo nella funzione
    coordinata2 = punto_modificato(coordinata);//passo per valore e ritorno un valore che assegnerò a coordinata 2
    stampa_punto(coordinata2);//stampo coordinata 2
    return 0;
}
