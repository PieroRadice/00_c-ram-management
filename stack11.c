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



char const operatori[] = "+-*/%";
char const chiedi_numero[] = "Inserisci gli operandi e l'operatore separandoli con uno spazzio e poi dai enter: ";
char const comunica_risultato[] = "il risultato dell'operazione e': ";


int main()
{
    double x =0;
    double y = 0;
    char operatore = '+';


    double (*calcola)(double, double);


    printf("%s",chiedi_numero);
    scanf("%lf %lf %c", &x,&y,&operatore);
    printf("%lf %lf %c",x,y,operatore);
    switch(operatore)
    {
    case '+':
        calcola = somma;
        break;
    case '-':
        calcola = sottrazione;
        break;
    case '*':
        calcola = prodotto;
        break;
    case '/':
        calcola = divisione;
        break;
    case '%':
        calcola = resto;
        break;

    }

    printf("%s %lf",comunica_risultato,calcola(x,y));


    return 0;
}
