/**
    AREA TEXT DELLA MEMORIA VIRTUALE
    CREA UNA CALCOLATRICE CHE INSERITI DUE NUMERI CHIEDE DIA AVERE L'OPERATORE E POI LO CALCOLA
 */

#include <stdio.h>
#include <stdbool.h>\

double somma(double x, double y)
{
    return x+y;
}
double prodotto(double x, double y)
{
    return x*y;
}
double divisione(double x, double y)
{
    return x/y;
}
double resto(int x, int y)
{
    return x%y;
}
double sottrazione(double x, double y)
{
    return x-y;
}
bool check_operatore(char operatore, char *operatori)
{
    for(int i = 0; operatori[i]!='0'; i++ )
    {
        if(operatore==operatori[i])
        {
            return true;
        }
    }
    return false;
}

void *operazione_corretta(char operatore)
{
    switch(operatore)
    {
    case '+':
        return somma;
        break;
    case '-':
        return sottrazione;
        break;
    case '*':
        return prodotto;
        break;
    case '/':
        return divisione;
        break;
    case '%':
        return resto;
        break;
    }
    return somma;
}

char const operatori[] = "+-*/%";
char const chiedi_numero[] = "Inserisci gli operandi e l'operatore separandoli con uno spazio e poi dai enter: ";
char const comunica_risultato[] = "il risultato dell'operazione e': ";

int main()
{
    double x =0;
    double y = 0;
    char operatore = '+';

    printf("%s",chiedi_numero);
    scanf("%lf %lf %c", &x,&y,&operatore);

    double (*calcola)(double, double) = operazione_corretta(operatore);

    printf("%s %lf",comunica_risultato,calcola(x,y));


    return 0;
}
