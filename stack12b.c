/**
    ESERCIZIO: Array di puntatori a funzione con parametro da linea di comando
    
    Questo programma dimostra come usare un array di puntatori a funzione
    per eseguire diverse operazioni in un ciclo, prendendo il valore da argv.
*/

#include <stdio.h>
#include <stdlib.h>

double quadrato(double x)
{
    return x * x;
}

double cubo(double x)
{
    return x * x * x;
}

double doppio(double x)
{
    return x * 2;
}

double meta(double x)
{
    return x / 2;
}

    double (*operazioni[])(double) = {quadrato, cubo, doppio, meta};
    
    char *nomi[] = {"quadrato", "cubo", "doppio", "meta"};
int main(int argc, char *argv[])
{
    // argc = numero di argomenti passati da linea di comando (include il nome del programma)
    // argv = array di stringhe contenente gli argomenti
    // argv[0] = nome del programma
    // argv[1] = primo argomento fornito dall'utente
    
    // Controllo se e' stato fornito almeno un argomento (oltre al nome del programma)
    if(argc < 2)
    {
        // Se non ci sono argomenti, mostra come usare il programma
        printf("Uso: %s <valore>\n", argv[0]);
        return 1;
    }
    
    // atof() converte una stringa (argv[1]) in un numero double
    double valore = atof(argv[1]);
    
    
    int num_operazioni = sizeof(operazioni) / sizeof(operazioni[0]);
    
    printf("Valore iniziale: %.2lf\n\n", valore);
    
    for(int i = 0; i < num_operazioni; i++)
    {
        double risultato = operazioni[i](valore);
        printf("%s(%.2lf) = %.2lf\n", nomi[i], valore, risultato);
    }
    
    return 0;
}
