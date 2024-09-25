#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void ControlloStringa(char stringa[])
{
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] < 97 || stringa[i] > 122)
        {
            if (stringa[i] < 65 || stringa[i] > 90)
            {
                printf("Numero presente\n");
                exit(1);
            }
        }
    }
}
void ContaLettera(char stringa[], char carattere)
{

    int nChar = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == carattere)
        {
            nChar++;
        }
    }
    if (nChar > 0)
    {
        printf("La lettera compare %d volte \n", nChar);
    }
    else
    {
        printf("La lettera non è presente \n");
    }
}
void CreaStringhePariDispari(char stringa[])
{
    char stringaPari[30];
    char stringaDispari[30];
    int nPari = 0, nDispari = 0;
    for (int i = 1; i <= strlen(stringa); i++)
    {
        if (i % 2 == 0)
        {
            stringaPari[nPari] = stringa[i - 1];
            nPari++;
        }
        else
        {
            stringaDispari[nDispari] = stringa[i - 1];
            nDispari++;
        }
    }
    stringaPari[nPari] = '\0';  
    stringaDispari[nDispari] = '\0';
    printf("Stringa pari %s \n", stringaPari);
    printf("Stringa dispari %s \n", stringaDispari);
}
void ControlloDoppie(char stringa[])
{
    int nDoppie = 0;
    for (int i = 0; i < strlen(stringa) - 1; i++)
    {
        if (stringa[i] == stringa[i + 1])
        {
            nDoppie++;
        }
    }
    if (nDoppie > 0)
    {
        printf("Ci sono %d doppie \n", nDoppie);
    }
    else
    {
        printf("Non ci sono doppie \n");
    }
}
int main()
{
    char stringa1[30];
    printf("Inserisci la prima stringa \n");
    scanf("%s", stringa1);
    ControlloStringa(stringa1);
    char carattere;
    printf("Che lettera vuoi cercare? \n");
    getchar();
    scanf("%c", &carattere);
    ContaLettera(stringa1, carattere);
    CreaStringhePariDispari(stringa1);
    ControlloDoppie(stringa1);
    return 0;
}