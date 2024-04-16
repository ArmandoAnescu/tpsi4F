#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_DIM 1024

int main(int argc, char *argv[])
{

    typedef struct
    {                          // definisco una struct
        char name[20];         // campo nome
        char lastname[20];     // campo cognome
        int gradePointAverage; // media

    } student; // Tramite typedef chiamo la structy studenmte

    student class[3]; // definisco un array di struct chiamato class

    strcpy(class[0].name, "name1");         // assegno alla posizione 0 il nome name 1
    strcpy(class[0].lastname, "lastname1"); // assegno il cognome
    class[0].gradePointAverage = 8;         // assegno la maedia

    strcpy(class[1].name, "name2");
    strcpy(class[1].lastname, "lastname2");
    class[1].gradePointAverage = 9;

    strcpy(class[2].name, "name3");
    strcpy(class[2].lastname, "lastname3");
    class[2].gradePointAverage = 10;

    FILE *contieneStudenti;                  // dichiarò la var puntatore a file contine studenti
    contieneStudenti = fopen("log.txt", "w+"); // apro il file in scrittura e lettura 
    if (contieneStudenti == NULL)
    {                                                            // controllo che l'apertura del file non sia fallita
        printf("errore apertura file destinazione %s", argv[1]); // se fallita avverto l'utente e termino il programma
        return 0;
    }

    fwrite(class, sizeof(student), 3, contieneStudenti); // uso fwrite per scrivere nel file i dati che hanno la dim max di student escrivo fino a class.lenght e metto il puntaotre a file dove scrivere la roba
    /*Punt rappresenta l’indirizzo della locazione di partenza su cui scrivere i dati, dim rappresenta la dimensione in byte del singolo dato e num rappresenta il numero degli elementi da scrivere nello stream. FILE *fp è il puntatore al file
    student secondClass[3];//dchiaro un altro array a struct
    */

    student secondClass[3];
    fseek(contieneStudenti, sizeof(student)*0 , SEEK_SET);
    fread(secondClass, sizeof(student), 3, contieneStudenti); // e gli assegno i valori salvati salvandoli nell'array
    for (int i = 0; i < 3; i++)
    {                                        // for che stampa i valori
        printf("%s\n", secondClass[i].name); // stampo i vari campi nome,cognome,media
        printf("%s\n", secondClass[i].lastname);
        printf("%d\n", secondClass[i].gradePointAverage);
    }

    printf("------------------------\n");                   // printf perdivisione
    fseek(contieneStudenti, sizeof(student) * 2, SEEK_SET); // con fseek scelgo da dove iniziare a leggere i valori nel file
    /*cerando nel file dati 2 volte più grandi di quella della struct e uso seek set per partire dall'inizio
     */
    student stud;                                       // dichiaro la var stud di struct
    fread(&stud, sizeof(student), 3, contieneStudenti); // leggo dal file i valori
    printf("%s\n", stud.name);                          // scrivo i valori salvati in studf
    printf("%s\n", stud.lastname);
    printf("%d\n", stud.gradePointAverage);

    fclose(contieneStudenti); // chiudo il file
}
//il programma salva dei valori in un array, questi valori saranno poi scritti sul file per poi essere letti e salvati in un secondo array,
//stampato il secondo array si usa una fseek per partire a inizio file e leggere di nuovo dei valori dopo i primi 2 valori e stampo gli ultimi valori