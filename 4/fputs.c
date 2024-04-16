#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 20 // definisco la macro che definisce il n massimo di char in una stringa
#define qtaNomi 4  // definisco la macro che indica la quantità di nomi
int i;             // dichiaro la costante i
int main()
{
    FILE *fileDestinazione; // definisco il puntatore file destinazione per aprire il file
    char vett[MAX_STR];     // definisco una stringa di lunghezza MAX_STR

    fileDestinazione = fopen("nomi.txt", "w"); // apro il file nomi.txt in scrittura
    if (fileDestinazione == NULL)              // controllo che il file non sia vouto o esista
    {
        printf("Impossibile aprire il file"); // in caso non sia posibile aprire il file avverto lo user
        exit(1);
    }
    else
    {
        for (i = 0; i < qtaNomi; i++) // altrimenti inizio un ciclo for dove chiedo max 4 nomi
        {
            printf("Inserisci il %d^ nome   >>   ", i + 1); // chiedo di inserire il nome
            scanf("%s", vett);                              // leggo il nome

            fputs(vett, fileDestinazione);//inserisco la stringa dentro il file

            fputc('\n', fileDestinazione);//inserisoc il carattere \n per andare a capo
        }
    }
    fclose(fileDestinazione);//chiudo il file

    fileDestinazione = fopen("nomi.txt", "r");//riapro il file in sola lettura
    while (fgets(vett, MAX_STR, fileDestinazione))//prendo le stringhe dal file e le metto dentro vett fino a che non arrivo a fine del file-
        printf("%s", vett);//scrivo i nomi a video

    if (fclose(fileDestinazione) == 0)//chiudo il file e vedo se il valore ritornato è 0
        printf("\n\nChiusura del file avvenuta con successo");//se 0 file chiuso con successo
    else
        printf("\n\nChiusura del file fallita");//altrimenti file non cvhiuso

    return 0;
}