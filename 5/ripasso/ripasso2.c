#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void ControlloStringa(char stringa[])
{
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] < 'a' || stringa[i] > 'z')
        {
            if (stringa[i] < 'A' || stringa[i] > 'Z')
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
void ComparaLunghezza(char str1[], char str2[])
{
    if (strlen(str1) > strlen(str2))
    {
        printf("la prima stringa è più lunga della seconda \n");
    }
    else
    {
        printf("la prima stringa è più corta della seconda \n");
    }
}
void ContaVocali(char str1[], char str2[])
{
    int nVocali1 = 0, nVocali2 = 0;
    for (int i = 0; i < strlen(str1); i++)
    {
        if (str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i' || str1[i] == 'o' || str1[i] == 'u')
        {
            nVocali1++;
        }
    }
    for (int i = 0; i < strlen(str2); i++)
    {
        if (str2[i] == 'a' || str2[i] == 'e' || str2[i] == 'i' || str2[i] == 'o' || str2[i] == 'u')
        {
            nVocali2++;
        }
    }
    if (nVocali1 > nVocali2)
    {
        printf("La stringa 1 ha più vocali della stringa 2 \n");
    }else{
        printf("La stringa 2 ha più vocali della stringa 1 \n");
    }
}
void ContaConsonanti(char str1[], char str2[])
{
    int nVocali1 = 0, nVocali2 = 0;
    for (int i = 0; i < strlen(str1); i++)
    {
        if (str1[i] != 'a' || str1[i] != 'e' || str1[i] != 'i' || str1[i] != 'o' || str1[i] != 'u')
        {
            nVocali1++;
        }
    }
    for (int i = 0; i < strlen(str2); i++)
    {
        if (str2[i] != 'a' || str2[i] != 'e' || str2[i] != 'i' || str2[i] != 'o' || str2[i] != 'u')
        {
            nVocali2++;
        }
    }
    if (nVocali1 > nVocali2)
    {
        printf("La stringa 1 ha più consonanti della stringa 2 \n");
    }else{
        printf("La stringa 2 ha più consonanti della stringa 1 \n");
    }
}
void LetterePresenti(char str1[],char str2[]){
    char presenti[10];
    int n=0;
    for (int i = 0; i < strlen(str1); i++)
    {
        for (int j = 0; j < strlen(str2); j++)
        {
            if(str1[i]==str2[j]){
                presenti[n]=str1[i];
                n++;
            }
        }
        
    }
    printf("le lettere presenti sono:\n");
    for (int i = 0; i < strlen(presenti); i++)
    {
        printf("%c\n",presenti[i]);
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
    char stringa2[30];
    printf("Inserisci la prima stringa \n");
    scanf("%s", stringa2);
    ComparaLunghezza(stringa1, stringa2);
    ContaVocali(stringa1, stringa2);
    ContaConsonanti(stringa1,stringa2);
    return 0;
}