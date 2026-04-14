/**
IP address
*/
#include<string.h>
#include<stdio.h>
#define MAX_STRG 255

typedef struct
{
    char via[MAX_STRG];
    unsigned char cap[5];
    unsigned char numero_civico[9];
} Indirizzo;

typedef struct
{
    char nome[MAX_STRG];
    char cognome[MAX_STRG];
    Indirizzo indirizzo;
} Persona;

typedef struct
{
    unsigned char ip[4];
    unsigned char mask[4];
    char dominio[MAX_STRG];
    Persona *proprietario;
} IpV4_address;
/**
 * assegna_nome - Assegna un nome a una persona
 * @persona: Puntatore alla persona
 * @nome: Nome da assegnare
 */
void assegna_nome(Persona *persona, char nome[])
{
    strcpy(persona->nome, nome);
}
/**
 * assegna_cognome - Assegna un cognome a una persona
 * @persona: Puntatore alla persona
 * @cognome: Cognome da assegnare
 */
void assegna_cognome(Persona *persona, char cognome[])
{
    strcpy(persona->cognome, cognome);
}
/**
 * assegna_dominio - Assegna un dominio a un indirizzo IP
 * @ip_address: Puntatore all'indirizzo IP
 * @dominio: Dominio da assegnare
 */
void assegna_dominio(IpV4_address *ip_address, char dominio[])
{
    strcpy(ip_address->dominio, dominio);
}
void assegna_ip_da_stringa(IpV4_address *ip_address, char ip[])
{
    //tolgo gli spazi dalla stringa all'inizio e alla fine
    while (*ip == ' ') {
        ip++;
    }
    //verifico che la stringa abbia massimo 15 caratteri (ipv4) e minimo 7 caratteri
    if (strlen(ip) > 15 || strlen(ip) < 7) {
        return;
    }
    while (ip[strlen(ip) - 1] == ' ') {
        ip[strlen(ip) - 1] = '\0';
    }
    //verifico che ci siano 3 separatori fra quelli ammessi (punto,virgola, slash, backslash, spazio, pipe)   
    int separatori = 0;
    for (int i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.' || ip[i] == ',' || ip[i] == '/' || ip[i] == '\\' || ip[i] == ' ' || ip[i] == '|') {
            separatori++;
        }
    }
    if (separatori != 3) {
        return;
    }

    
    sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &ip_address->ip[0], &ip_address->ip[1], &ip_address->ip[2], &ip_address->ip[3]);
}
/**
 * assegna_ip - Assegna un IP a un indirizzo IP
 * @ip_address: Puntatore all'indirizzo IP
 * @a: Prima parte dell'IP
 * @b: Seconda parte dell'IP
 * @c: Terza parte dell'IP
 * @d: Quarta parte dell'IP
 */
void assegna_ip(IpV4_address *ip_address,unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    ip_address->ip[0]=a;
    ip_address->ip[1]=b;
    ip_address->ip[2]=c;
    ip_address->ip[3]=d;
}
/**
 * assegna_mask - Assegna una maschera a un indirizzo IP
 * @ip_address: Puntatore all'indirizzo IP
 * @a: Prima parte della maschera
 * @b: Seconda parte della maschera
 * @c: Terza parte della maschera
 * @d: Quarta parte della maschera
 */
void assegna_mask(IpV4_address *ip_address, unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    ip_address->mask[0]=a;
    ip_address->mask[1]=b;
    ip_address->mask[2]=c;
    ip_address->mask[3]=d;
}
/**
 * stampa_mask - Stampa la maschera di un indirizzo IP
 * @ip_address: Puntatore all'indirizzo IP
 */
void stampa_mask(IpV4_address *ip_address)
{
    printf("%d.%d.%d.%d\n", ip_address->mask[0], ip_address->mask[1], ip_address->mask[2], ip_address->mask[3]);
}
void stampa_ip(IpV4_address *ip_address)
{
    printf("%d.%d.%d.%d\n", ip_address->ip[0], ip_address->ip[1], ip_address->ip[2], ip_address->ip[3]);
}

int main()
{
    Persona persona;
    IpV4_address ip_address;
    
    assegna_nome(&persona, "Mario");
    assegna_cognome(&persona, "Rossi");
    assegna_dominio(&ip_address, "www.google.com");
    assegna_ip(&ip_address, 192, 168, 1, 1);
    
    stampa_ip(&ip_address);
    
    return 0;
}
