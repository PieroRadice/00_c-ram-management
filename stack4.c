#include <stdio.h>

char nome[] = "Piero";
char ffff[] = {'c','i','a','o',0);
char cognome[] = "Radice";

int main(){
    //facciamo dei tentativi con printf per capire che cosa sono i puntatori
    printf("%d %d\n",nome,cognome);
    printf("%p %p\n",&nome,&cognome);
    //char *p_nome_1 = &nome;
    char *p_nome = &nome[0];
    char *p_cognome = & cognome[0];
    printf("--&__nome-s-%s\n", nome);
    printf("--&__nome-c-%c\n", nome);
    printf("--&__nome-c-%c\n", nome[0]);
    printf("--&__nome-p-%p\n",&nome);
    printf("--p__nome-p-%p\n", p_nome);
    printf("--&p_nome-p-%p\n",&p_nome);
    printf("--*p_nome-c-%c\n",*p_nome);
    printf("\n");

    //provo a cambiare i valori contenuti nel nome
    char nuovoNome[] = "Piero Luigi";
//    for(int i = 0 ; i<sizeof(nuovoNome)/sizeof(nuovoNome[0]) ; i++){
//        nome[i] = nuovoNome[i];
//        printf("....%c %c\n",nome[i],nuovoNome[i]);
//    }
//    printf("+++++%s\n",nome);
//    printf("+++++%s %s\n",nome, cognome);
    printf("+++++%s %s\n",p_nome, p_cognome);
    p_nome = &nuovoNome[0];
    //in questo modo se il puntatore è la variabile che può contenere il nome posso cambiarne il valore anche se spreco la memoria della variabile nome

    printf("-----%s %s\n",p_nome, p_cognome);

    return 0;
}
