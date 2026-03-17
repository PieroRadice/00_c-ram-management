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
    printf("%s %s\n",nome,cognome);
    return 0;
}

