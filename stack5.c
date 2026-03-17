#include <stdio.h>

char *nome;
char *cognome;

int main()
{
    char _nome[] = "Piero";
    char _cognome[] = "Radice";
    nome = _nome;
    cognome = _cognome;
    char nuovoNome[] = "Piero Luigi";
    nome = nuovoNome;
    //facciamo vari tentativi per capire che cosa sono gli array
    printf("%s %s\n",nome,cognome);
    return 0;
}

/**
questa soluzione gestisce in maniera corretta gli array ma non è una ottimale perché spreca la memoria occupata da _nome che
non verrà mai più utilizzato durante il programma.
Prova a trovare una soluzione per risolvere questo problema.
*/

