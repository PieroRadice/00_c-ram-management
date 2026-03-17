#include <stdio.h>

char nome[] = "Piero";
char cognome[] = "Radice";

int main()
{
    printf("%s %s\n",nome,cognome);
    printf("%p %p\n",&nome,&cognome);
    return 0;
}
