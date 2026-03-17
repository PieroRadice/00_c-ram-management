 /**
AREA TEXT DELLA MEMORIA VIRTUALE
 */

#include <stdio.h>

void saluta()
{
    printf("ciao\n");
}
int x = 10;
void (*p)() = saluta;

int main() {

    void (*f)() = saluta;
    p();
    f();

    printf("\n%p valore di p ",p);
        printf("\n%p valore di f ",f);
    printf("\n%p indirizzo di p",&p);
    printf("\n%p indirizzo di f",&f);
    printf("\n%p indirizzo di x",&x);

    return 0;
}
