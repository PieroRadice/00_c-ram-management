#include <stdio.h>
char *p_length;
char *nome;

int length(char *stringa){
    int i = 0;
    while(stringa[i]){
        i++;
    }
    return i;
}

int main(){
    char _nome[] = "Piero";
    nome = _nome;
    printf("lunghezza %d", length(nome));
    printf("\nlunghezza %d", length(_nome));
    printf("qui si trova la funzione: %p",length);
    p_length = (char*)length;
    //p_length = length;
    for(int i = 0; i<100; i++){
        //printf("\n%p--%02X", (p_length+i),*(p_length+i));
        printf("\n%p--%02X", (p_length+i),(unsigned char)*(p_length+i));
    }
    return 0;
}
