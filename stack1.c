#include <stdio.h>
int siamo_in_tre = 3;
int due_arrivano = 2;
int main()
{
    printf("ora siamo %d\n", siamo_in_tre+due_arrivano);
    printf("la variabile siamo_in_tre e' allocata in %p\n",&siamo_in_tre);
    printf("la variabile due_arrivano e' allocata in %p\n",&due_arrivano);
    printf("Le variabili dichiarate prima del main si trovano nella memoria fissa\n. La dimensione della memoria fissa non cambia durante l'esecuzione del programma");
    return 0;
}
