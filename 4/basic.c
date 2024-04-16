#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fileOrigine;//dichiaro il puntatore al file
	fileOrigine=fopen("nomeFile.txt", "r"); //apro il file nomi in sola lettura
	if(fileOrigine==NULL)  //controllo che il file non sia impossibile d'aprire/esista/non sia vuoto
	{
		printf("Impossibile aprire il file");//avverto l'utente ch enon è possibile aprire il file
		exit (1);//esco dal programma
	}
	else 
	{
		 printf("File aperto");//altrimenti dico dle successo
    }
    fclose(fileOrigine);//chiudo il file           
    if(fclose(fileOrigine)==0) //controllo che il file sia chiuso con successo
		printf("\nChiusura del file avvenuta con successo");//se chiuso mostro un messaggio di successo
	else printf("\nChiusura del file fallita");//altrimenti avverto l'utente del fallimento
	return 0;
}
