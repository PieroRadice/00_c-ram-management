#include <stdio.h>
int siamo_in_tre = 3;

int main(){
    static int due_arrivano = 2;
    printf("ora siamo %d\n", siamo_in_tre+due_arrivano);
    printf("la variabile siamo_in_tre e' allocata in %p\n",&siamo_in_tre);
    printf("la variabile due_arrivano e' allocata in %p\n",&due_arrivano);
    return 0;
}

