#include <stdio.h>

char nome[] = "Piero";
char cognome[] = "Radice";

//La funzione cambia_nome_errata non può funzionare perche' nome memorizza un indirizzo di memoria e noi vorremmo invece memorizzare una stringa
//void cambia_nome_errata(){
//    nome = "Pi";
//}
//Nome e nuovo nome sono due variabili dello stesso tipo eppure non possiamo scrivere l'assegnazione nome = nuovoNome. Perche'?
//Nome rappresenta una posizione di memoria della ram, in particolare la prima lettera di una stringa.
//posso cambiare il contenuto di ma non posso cambiare l'indirizzo di memoria!
//Non ha senso scrivere che nome = cognome perchè sarebbe come pretendere si spostare l'indirizzo di nome sopra l'indirizzo di cognome.
//void cambia_nome(){
//    char nuovoNome[] = "Piero Luigi";
//    nome = nuovoNome;
//}

void cambia_nome_1()
{
    char nuovoNome[] = "Piero Luigi";
    int i = 0;
    while(nuovoNome[i++])nome[i] = nuovoNome[i];
}

int main()
{
    printf("%s %s\n",nome,cognome);
    printf("%p %p\n",&nome,&cognome);
    cambia_nome_1();
    printf("%s %s\n",nome,cognome);
    printf("%p %p\n",&nome,&cognome);
    //La funzione compie il suo lavoro ma il risultato che ottengo è sbagliato perchè la funzione 1 spazza la memoria al di fuori dell'array definito da nome andando fino a coprire l'array del cognome
    return 0;
}
