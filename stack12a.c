/**
    ESERCIZIO: Array di puntatori a funzione

    Questo programma dimostra come usare un array di puntatori a funzione
    per eseguire diverse operazioni in un ciclo.
*/

#include <stdio.h>

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
char *nomi[] = {"quadrato", "cubo", "doppio", "meta"};
double (*operazioni[])(double) = {quadrato, cubo, doppio, meta};
int num_operazioni = sizeof(operazioni) / sizeof(operazioni[0]);
int main()
{
    double valore = 5.0;

    printf("Valore iniziale: %.2lf\n\n", valore);

    for(int i = 0; i < num_operazioni; i++)
    {
        double risultato = operazioni[i](valore);
        printf("%s(%.2lf) = %.2lf\n", nomi[i], valore, risultato);
    }

    return 0;
}
