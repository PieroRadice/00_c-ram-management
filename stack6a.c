#include <stdio.h>


int main()
{
    int data_nascita[] = {2, 9, 2009};
    int *giorno = &data_nascita[0];
    //char *_giorno = &data_nascita[0];
    char *_giorno = (char*)(&data_nascita[0]);
    printf("giorno %d mese %d anno %d", data_nascita[0], data_nascita[1], data_nascita[2]);
    printf("\ngiorno %p mese %p anno %p", &data_nascita[0], &data_nascita[1], &data_nascita[2]);
    printf("\ngiorno %p mese %p anno %p", giorno, giorno + 1, giorno + 2);
    printf("\ngiorno %d mese %d anno %d", *giorno, *(giorno + 1), *(giorno + 2));
    printf("\ngiorno %p mese %p anno %p", _giorno, _giorno + 1, _giorno + 2);
    printf("\n");
    for (int i=0; i<12; i++)
    {
        printf("\n%d",*(_giorno+i));
    }
    for (int i = 0; i < 12; i++)
    {
        unsigned char byte = (unsigned char)*(_giorno + i);
        printf("\nByte %2d: %3u  -> ", i, byte);
        for (int i = 7; i >= 0; i--)
        {
            printf("%d", (byte >> i) & 1);
        };
    }

    return 0;
}
