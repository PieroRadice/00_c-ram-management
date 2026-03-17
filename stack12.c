/**
    ESERCIZIO: Puntatore a funzione come parametro
    
    Questo programma dimostra come passare un puntatore a funzione come parametro.
    Abbiamo diverse operazioni matematiche e una funzione generica che le applica.
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

void applica_operazione(double numero, double (*operazione)(double))
{
    double risultato = operazione(numero);
    printf("Risultato: %.2lf\n", risultato);
}

int main()
{
    double valore = 5.0;
    
    printf("Valore iniziale: %.2lf\n\n", valore);
    
    printf("Applicando quadrato: ");
    applica_operazione(valore, quadrato);
    
    printf("Applicando cubo: ");
    applica_operazione(valore, cubo);
    
    printf("Applicando doppio: ");
    applica_operazione(valore, doppio);
    
    printf("Applicando meta: ");
    applica_operazione(valore, meta);
    
    return 0;
}
