/**
IP address
*/
#include<string.h>
#include<stdio.h>
#define MAX_STRG 255

/**
 * Typedef per array di 4 unsigned char
 * Utilizzati per rappresentare indirizzi IP e maschere di rete IPv4
 * 
 * Vantaggi:
 * - Sintassi più leggibile e auto-documentante
 * - Facilita modifiche future (es: passaggio a IPv6)
 * - Rende esplicito il tipo di dato utilizzato
 */
typedef unsigned char IpV4[4];   /* Indirizzo IPv4: 4 ottetti (0-255) */
typedef unsigned char Mask[4];   /* Maschera di rete: 4 ottetti (0-255) */

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

/**
 * Struttura per rappresentare un indirizzo IPv4 completo
 * Utilizza i typedef IpV4 e Mask per maggiore chiarezza
 */
typedef struct
{
    IpV4 ip;              /* Indirizzo IP usando il typedef */
    Mask mask;            /* Maschera di rete usando il typedef */
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

/**
 * calcola_rete - Calcola l'indirizzo di rete dato IP e maschera
 * @ip_address: Puntatore all'indirizzo IP con maschera
 * @rete: Array dove salvare l'indirizzo di rete calcolato
 * 
 * L'indirizzo di rete si ottiene facendo AND bit a bit tra IP e maschera
 * Esempio: IP 192.168.1.130 AND mask 255.255.255.128 = 192.168.1.128
 */
void calcola_rete(IpV4_address *ip_address, IpV4 rete)
{
    for(int i = 0; i < 4; i++)
    {
        rete[i] = ip_address->ip[i] & ip_address->mask[i];
    }
}

/**
 * calcola_broadcast - Calcola l'indirizzo di broadcast dato IP e maschera
 * @ip_address: Puntatore all'indirizzo IP con maschera
 * @broadcast: Array dove salvare l'indirizzo di broadcast calcolato
 * 
 * L'indirizzo di broadcast si ottiene facendo OR tra IP e NOT della maschera
 * Esempio: IP 192.168.1.130 OR (NOT mask 255.255.255.128) = 192.168.1.255
 */
void calcola_broadcast(IpV4_address *ip_address, IpV4 broadcast)
{
    for(int i = 0; i < 4; i++)
    {
        broadcast[i] = ip_address->ip[i] | (~ip_address->mask[i]);
    }
}

/**
 * conta_bit_mask - Conta i bit a 1 nella maschera (notazione CIDR)
 * @mask: Maschera di rete
 * @return: Numero di bit a 1 (es: 255.255.255.0 -> 24)
 */
int conta_bit_mask(Mask mask)
{
    int count = 0;
    for(int i = 0; i < 4; i++)
    {
        unsigned char byte = mask[i];
        while(byte)
        {
            count += byte & 1;
            byte >>= 1;
        }
    }
    return count;
}

/**
 * determina_classe - Determina la classe dell'indirizzo IP (classless/CIDR)
 * @ip: Indirizzo IP da analizzare
 * @return: Carattere che rappresenta la classe ('A', 'B', 'C', 'D', 'E', 'P')
 * 
 * Classi IP (basate sul primo ottetto):
 * - Classe A: 0-127     (0xxxxxxx)  - Reti grandi
 * - Classe B: 128-191   (10xxxxxx)  - Reti medie
 * - Classe C: 192-223   (110xxxxx)  - Reti piccole
 * - Classe D: 224-239   (1110xxxx)  - Multicast
 * - Classe E: 240-255   (1111xxxx)  - Riservata/Sperimentale
 * - Privato: 10.x.x.x, 172.16-31.x.x, 192.168.x.x
 */
char determina_classe(IpV4 ip)
{
    unsigned char primo_ottetto = ip[0];
    
    if(primo_ottetto < 128)
    {
        return 'A';  /* 0-127: Classe A */
    }
    else if(primo_ottetto < 192)
    {
        return 'B';  /* 128-191: Classe B */
    }
    else if(primo_ottetto < 224)
    {
        return 'C';  /* 192-223: Classe C */
    }
    else if(primo_ottetto < 240)
    {
        return 'D';  /* 224-239: Multicast */
    }
    else
    {
        return 'E';  /* 240-255: Riservata */
    }
}

/**
 * is_ip_privato - Verifica se l'IP è privato (RFC 1918)
 * @ip: Indirizzo IP da verificare
 * @return: 1 se privato, 0 se pubblico
 * 
 * Range IP privati:
 * - 10.0.0.0 - 10.255.255.255 (10.0.0.0/8)
 * - 172.16.0.0 - 172.31.255.255 (172.16.0.0/12)
 * - 192.168.0.0 - 192.168.255.255 (192.168.0.0/16)
 */
int is_ip_privato(IpV4 ip)
{
    /* 10.0.0.0/8 */
    if(ip[0] == 10)
    {
        return 1;
    }
    /* 172.16.0.0/12 */
    if(ip[0] == 172 && ip[1] >= 16 && ip[1] <= 31)
    {
        return 1;
    }
    /* 192.168.0.0/16 */
    if(ip[0] == 192 && ip[1] == 168)
    {
        return 1;
    }
    return 0;
}

/**
 * stampa_info_rete - Stampa tutte le informazioni sulla rete
 * @ip_address: Puntatore all'indirizzo IP con maschera
 */
void stampa_info_rete(IpV4_address *ip_address)
{
    IpV4 rete, broadcast;
    
    calcola_rete(ip_address, rete);
    calcola_broadcast(ip_address, broadcast);
    
    char classe = determina_classe(ip_address->ip);
    int cidr = conta_bit_mask(ip_address->mask);
    int privato = is_ip_privato(ip_address->ip);
    
    printf("\n=== INFORMAZIONI RETE ===\n");
    printf("IP:           %d.%d.%d.%d\n", 
           ip_address->ip[0], ip_address->ip[1], 
           ip_address->ip[2], ip_address->ip[3]);
    printf("Maschera:     %d.%d.%d.%d\n", 
           ip_address->mask[0], ip_address->mask[1], 
           ip_address->mask[2], ip_address->mask[3]);
    printf("CIDR:         /%d\n", cidr);
    printf("Rete:         %d.%d.%d.%d\n", 
           rete[0], rete[1], rete[2], rete[3]);
    printf("Broadcast:    %d.%d.%d.%d\n", 
           broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Classe:       %c\n", classe);
    printf("Tipo:         %s\n", privato ? "Privato" : "Pubblico");
    
    /* Calcola numero di host disponibili */
    unsigned long num_host = 1;
    for(int i = 0; i < 4; i++)
    {
        num_host *= (256 - ip_address->mask[i]);
    }
    num_host -= 2;  /* Sottrai rete e broadcast */
    
    printf("Host validi:  %lu\n", num_host);
    printf("========================\n\n");
}

int main()
{
    Persona persona;
    IpV4_address ip_address;
    
    assegna_nome(&persona, "Mario");
    assegna_cognome(&persona, "Rossi");
    assegna_dominio(&ip_address, "www.google.com");
    
    /* === ESEMPIO 1: Rete classe C privata === */
    printf("\n*** ESEMPIO 1: Rete classe C privata ***\n");
    assegna_ip(&ip_address, 192, 168, 1, 130);
    assegna_mask(&ip_address, 255, 255, 255, 128);  /* /25 */
    stampa_info_rete(&ip_address);
    
    /* === ESEMPIO 2: Rete classe B privata === */
    printf("*** ESEMPIO 2: Rete classe B privata ***\n");
    assegna_ip(&ip_address, 172, 16, 50, 100);
    assegna_mask(&ip_address, 255, 255, 240, 0);  /* /20 */
    stampa_info_rete(&ip_address);
    
    /* === ESEMPIO 3: Rete classe A privata === */
    printf("*** ESEMPIO 3: Rete classe A privata ***\n");
    assegna_ip(&ip_address, 10, 20, 30, 40);
    assegna_mask(&ip_address, 255, 0, 0, 0);  /* /8 */
    stampa_info_rete(&ip_address);
    
    /* === ESEMPIO 4: IP pubblico classe A === */
    printf("*** ESEMPIO 4: IP pubblico classe A (Google DNS) ***\n");
    assegna_ip(&ip_address, 8, 8, 8, 8);
    assegna_mask(&ip_address, 255, 255, 255, 0);  /* /24 */
    stampa_info_rete(&ip_address);
    
    /* === ESEMPIO 5: Subnet piccola /30 (point-to-point) === */
    printf("*** ESEMPIO 5: Subnet /30 (point-to-point) ***\n");
    assegna_ip(&ip_address, 192, 168, 100, 5);
    assegna_mask(&ip_address, 255, 255, 255, 252);  /* /30 - solo 2 host */
    stampa_info_rete(&ip_address);
    
    return 0;
}
