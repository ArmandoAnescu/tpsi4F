/*
L'obiettivo è quello di creare una rappresentazione per i e le a cui appartengono. Ogni libro avrà diverse informazioni e sarà assegnato a una categoria specifica.

Implementa un programma in linguaggio C che gestisce i libri di una libreria. Ogni libro è identificato da titolo, autore, anno di pubblicazione e prezzo. I libri sono organizzati per categoria (ad esempio, narrativa, saggistica, scienze, arte), e ogni categoria può avere più libri.
Immaginate di dover gestire questi raccolta di libri, suddivisi per categorie, e di dover trovare un modo per tenere traccia delle informazioni di ciascun libro. Ogni libro dovrà avere un titolo, che lo identificherà, un autore, che ci dirà chi ha scritto il libro, l'anno di pubblicazione, che ci permetterà di sapere quando è stato pubblicato, e infine un prezzo, per indicare quanto costa.
Dovrete anche pensare a come suddividere questi libri in categorie. Ogni categoria avrà un nome, che indicherà di che tipo di libri stiamo parlando, come "Narrativa" o "Scienze", e conterrà una lista di libri che appartengono a quella specifica categoria.
Il vostro compito sarà trovare il modo migliore per organizzare e gestire tutte queste informazioni. Inoltre, dovrete scrivere delle funzioni che vi permettano di stampare tutti i libri che appartengono a una determinata categoria, cercare un libro specifico in base al titolo e trovare tutti i libri che rientrano in una certa categoria.
Sarà vostro compito decidere come rappresentare questi dati e implementare le funzioni necessarie per far funzionare il programma.

Buon lavoro!La consegna dovrà contenere il codice (su git) e una relazione dettagliata sulla PROGETTAZIONE e sulle firme delle funzioni da realizzare

In allegato, qui, trovate il file da cui pescare i libri per popolare correttamente la libreria.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CATEGORIE 20
typedef struct Libro
{
    char Autore[30];
    char Titolo[30];
    char Categoria[30];
    int anno;
    float prezzo;
} Libro;
typedef struct Categoria
{
    char nomeCategoria[40];
    Libro libri[40];
    int contatore;
} Categoria;
Categoria libreria[30];
void Visualizza()
{
    printf("========LIBRERIA======== \n");
    for (int i = 0; i < MAX_CATEGORIE; i++)
    {
        printf("\n Categoria: %s \n \n", libreria[i].nomeCategoria);
        for (int j = 0; j < libreria[i].contatore; j++)
        {
            printf("\n Nome:%s   Autore:%s    Anno:%d    Categoria:%s    Prezzo:%d \n", libreria[i].libri[j].Titolo, libreria[i].libri[j].Autore, libreria[i].libri[j].anno, libreria[i].libri[j].Categoria, libreria[i].libri[j].prezzo);
        }
    }
}
int CercaCategoria(char incognita[], int nCategorie)
{
    if (nCategorie == 0)
    {
        return 0;
    }

    for (int i = 0; i < nCategorie; i++)
    {
        if (strcmp(libreria[i].nomeCategoria, incognita))
        {
            return i;
        }
    }
    return -1;
}
void LetturaLibri(Libro librilettura[], const char *nomeFile)
{
    int n = 0;
    FILE *fLibri = fopen(nomeFile, "r");
    if (fLibri == NULL)
    {
        printf("Errore apertura file!\n");
        exit(1);
    }
    while (!feof(fLibri))
    {
        Libro libro;
        fscanf(fLibri, "%29[^,],%29[^,],%d,%f,%39[^\n]", libro.Titolo, libro.Autore, &libro.anno, &libro.prezzo, libro.Categoria);
        librilettura[n] = libro;
        n++;
    }
    fclose(fLibri);
    for (int i = 0; i < n; i++)
    {
        printf("Nome:%s Autore:%s Anno:%d Categoria:%s Prezzo:%f \n", librilettura[i].Titolo, librilettura[i].Autore, librilettura[i].anno, librilettura[i].Categoria, librilettura[i].prezzo);
    }
    printf("\n \n");
    int controlloCat = 0;
    int categorieEsitenti = 0;
    for (int i = 0; i < n; i++)
    {
        controlloCat = CercaCategoria(librilettura[i].Categoria, categorieEsitenti);
        if (controlloCat > -1)
        {
            libreria[controlloCat].libri[libreria[categorieEsitenti].contatore] = librilettura[i];
            libreria[controlloCat].contatore++;
            categorieEsitenti++;
        }
        else
        {
            strcpy(libreria[categorieEsitenti].nomeCategoria, librilettura[i].Categoria);
            libreria[categorieEsitenti].libri[libreria[categorieEsitenti].contatore] = librilettura[i];
            libreria[categorieEsitenti].contatore++;
            categorieEsitenti++;
        }
    }
    Visualizza();
}

int main(char *argv[], int argc)
{
    const char *filename = "libri.csv";
    // if (argc != 2)
    // {
    //     printf("Nome file non inserito!!\n");
    //     exit(-1);
    // }
    Libro librilettura[50];
    LetturaLibri(librilettura, filename);
    return 0;
}