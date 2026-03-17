#include <stdio.h>
#include <stdlib.h>
char *nome;
char *cognome;


/** \brief la funzione conta i carattedi di cui è composta la stringa senza includere il segnale '\0'
 *
 * \param puntatore alla stringa
 * \return lunghezza della stringa
 *
 */

int length(char *stringa)
{
    int i = 0;
    while(stringa[i])
    {
        i++;
    }
    return i;
}
/** \brief la funzione permette di inserire una stringa da tastiera
 *
 * \param massima dimensione della stringa accettabile
 * \param massima posizione
 * \return l'indirizzo di memoria di un vettore della minima dimensione accettabile
 *
 */

char *stringaUtente(char *descrizione){
    char input[100];
    printf("Inserisci %s: ",descrizione);
    scanf("%99[^\n]", input);
    while (getchar() != '\n');
    char stringa[length(input)+1];
    int i = 0;
    for (;i<=length(input);i++){
        stringa[i]=input[i];
    }
    stringa[i] = 0;
    printf("Il calcolatore sta eseguendo la funzione stringaUtente\n");
    printf("La stringa inserita e' %s di lunghezza %d e il suo indirizzo e' %p\n",stringa,length(stringa), stringa);
    return stringa;
}

int main()
{
    nome = stringaUtente("nome");
    printf("siamo nel main dopo aver inserito il nome\n");
    cognome = stringaUtente("cognome");
    printf("siamo nel main dopo aver inserito il nome\n");
    printf("Ora stampiamo nome e cognome\n");
    printf("%s %s\n",nome,cognome);
    printf("Perche' non ci siamo riusciti?\n");
    return 0;
}

