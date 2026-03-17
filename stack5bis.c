#include <stdio.h>
char *nome;
char *cognome;
int lenght(char stringa[]){
    int i = 0;
    while (stringa[i]!='\0'){i++;}
    return i;
}
char *creaStringa(char stringa[]){
    char _stringa[lenght(stringa)+1];
    for (int i = 0; i<lenght(stringa); i++)
    {
        _stringa[i]=stringa[i];
    }
    printf("stringa = %s _stringa = %s\n",stringa,_stringa);
    //printf("stringa si trova in")
    return _stringa;
}

void main(){
    char pippo[30];
    pippo[0] = 'C';
    pippo[1] = 'a';
    pippo[2] = 'p';
    pippo[3] = 0;
//    printf("lunghezza stringa %s e' %d","Piero",)
    //nome = creaStringa("Piero");
    nome = pippo;
    *(&cognome[0]) = 'P';
    //cognome = creaStringa("Radice");
    printf("%s\n",nome);
    printf("%p %p\n",nome,cognome);
    //nome = creaStringa("Piero Luigi");
    printf("%s %s\n",nome,cognome);
}
