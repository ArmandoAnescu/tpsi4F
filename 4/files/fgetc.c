#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fileOrigine;//dichiaro il puntatore per aprire il file
	char c;//dichiaro un char
	fileOrigine=fopen("nomi.txt", "r"); //assegno a file d'origine nomi.txt  in sola lettura
	if(fileOrigine==NULL) //controllo che il file sia vuoto
	{
		printf("Impossibile aprire il file");//se vuoto avverto l'utente e chiudo il programma
		exit (1);
	}
	else 
	{
		c=fgetc(fileOrigine); //altrimenti assegno al mio carattere il primo char del file
		while (c!=EOF)//con il ciclo while socrro tutti i caratteri del file fino alla EOF(end of file)
		{
			putchar(c);//scrivo il char
			c=fgetc(fileOrigine);//e poi prendo il char succesivo		
	    }
	
	if(fclose(fileOrigine)==0) //se l'operazone di chiusura del file va bene ritorna 0
		printf("\n\nChiusura del file avvenuta con successo");//dico se il file è stato chiuso con successo
	else printf("\n\nChiusura del file fallita");//dico che il file non è stato chiuso per qualche problema
    }
    return 0;
}
