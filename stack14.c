/**
 * programma: tipi_dato_personalizzati.c (stack14.c)
 * Scopo: Introdurre i tipi di dato personalizzati in C
 *        - struct (strutture)
 *        - typedef (alias di tipo)
 *        - enum (enumerazioni)
 *
 * Concetti chiave:
 * - Le STRUCT permettono di raggruppare dati di tipo diverso sotto un unico nome
 * - TYPEDEF crea alias per semplificare la sintassi dei tipi
 * - ENUM definisce costanti intere con nomi significativi
 * - I tipi personalizzati migliorano la leggibilita' e organizzazione del codice
 *
 * Compilazione: gcc -Wall -Wextra -o stack14 stack14.c
 * Esecuzione: ./stack14
 */

#include <stdio.h>
#include <string.h>

/* Definisce la lunghezza massima per le stringhe */
#define MAX_L 255

/**
 * Funzione di utilita' per copiare una stringa
 * Equivalente a strcpy(), ma implementata manualmente per scopo didattico
 * 
 * @param destinazione: array dove copiare la stringa
 * @param origine: stringa da copiare
 */
void assegnaStringa(char destinazione[], char origine[])
{
    int i = 0;
    /* Copia carattere per carattere finche' non trova il terminatore '\0' */
    while(origine[i])
    {
        destinazione[i] = origine[i];
        i++;
    }
    /* Aggiunge il terminatore di stringa */
    destinazione[i] = 0;
}

/* ========== PARTE 1: STRUCT (STRUTTURE) ========== */

/**
 * STRUCT PERSONA - Esempio base di struttura
 * 
 * Una struct e' un tipo di dato composto che raggruppa variabili
 * di tipo diverso (chiamate "membri" o "campi") sotto un unico nome.
 * 
 * Vantaggi:
 * - Organizza dati correlati insieme
 * - Migliora la leggibilita' del codice
 * - Facilita il passaggio di dati multipli alle funzioni
 * 
 * Sintassi: struct NomeStruct { tipo1 campo1; tipo2 campo2; ... };
 */
struct Persona
{
    char nome[MAX_L];        /* Nome della persona */
    char cognome[MAX_L];     /* Cognome della persona */
    float tagliaScarpe;      /* Numero di scarpe */
};
/**
 * Funzione che stampa i dati di una Persona
 * 
 * Nota: La struct viene passata PER VALORE, quindi viene creata una copia.
 * Per struct grandi, e' piu' efficiente passare un puntatore.
 * 
 * @param persona: struct Persona da stampare
 */
void stampaPersona(struct Persona persona)
{
    /* Accesso ai campi della struct con l'operatore punto (.) */
    printf("nome %s, cognome %s, numero di scarpe %.1f\n",
           persona.nome, persona.cognome, persona.tagliaScarpe);
}
/* ========== PARTE 2: TYPEDEF CON STRUCT ========== */

/**
 * TYPEDEF ALUNNO - Struct con typedef
 * 
 * TYPEDEF crea un ALIAS per un tipo di dato esistente.
 * Quando usato con struct, elimina la necessita' di scrivere "struct" ogni volta.
 * 
 * Differenza:
 * - Senza typedef: struct Persona p;  (bisogna scrivere "struct")
 * - Con typedef:   Alunno a;          (piu' semplice e leggibile)
 * 
 * Sintassi: typedef struct { ... } NomeAlias;
 */
typedef struct
{
    char nome[MAX_L];        /* Nome dell'alunno */
    char cognome[MAX_L];     /* Cognome dell'alunno */
    float altezza;           /* Altezza in cm */
} Alunno;

/**
 * Funzione che stampa i dati di un Alunno
 * 
 * Nota: Grazie a typedef, non serve scrivere "struct Alunno",
 * basta scrivere "Alunno" direttamente.
 * 
 * @param alunno: struct Alunno da stampare
 */
void stampaAlunno(Alunno alunno)
{
    printf("nome %s, cognome %s, altezza %.1f cm\n",
           alunno.nome, alunno.cognome, alunno.altezza);
}
/* ========== PARTE 3: TYPEDEF PER TIPI PRIMITIVI ========== */

/**
 * TYPEDEF DATA - Alias per tipo primitivo
 * 
 * Typedef puo' essere usato anche per dare nomi piu' significativi
 * ai tipi primitivi (int, float, char, ecc.)
 * 
 * Vantaggi:
 * - Codice piu' leggibile e auto-documentante
 * - Facilita modifiche future (es: cambiare da int a long)
 * - Nasconde dettagli implementativi
 */
typedef int data;  /* Rappresenta il tempo come numero di secondi dal 1-1-1970 (Unix timestamp) */

/* ========== PARTE 4: ENUM (ENUMERAZIONI) ========== */

/**
 * ENUM GIORNI - Giorni della settimana
 * 
 * Un ENUM (enumerazione) e' un tipo di dato che definisce un insieme
 * di costanti intere con nomi significativi.
 * 
 * Come funziona:
 * - Il primo valore (lunedi) vale 0
 * - Il secondo (martedi) vale 1
 * - E cosi' via in sequenza
 * 
 * Vantaggi:
 * - Codice piu' leggibile: "martedi" invece di "1"
 * - Previene errori: non puoi assegnare valori non validi
 * - Auto-documentante: i nomi spiegano il significato
 * 
 * Sintassi: typedef enum { valore1, valore2, ... } NomeEnum;
 */
typedef enum
{
    lunedi,      /* 0 */
    martedi,     /* 1 */
    mercoledi,   /* 2 */
    giovedi,     /* 3 */
    venerdi,     /* 4 */
    sabato,      /* 5 */
    domenica     /* 6 */
} giorni;

/**
 * ENUM MESI - Mesi dell'anno
 * 
 * Altro esempio di enumerazione.
 * I valori vanno da 0 (gennaio) a 11 (dicembre)
 */
typedef enum
{
    gennaio,     /* 0 */
    febbraio,    /* 1 */
    marzo,       /* 2 */
    aprile,      /* 3 */
    maggio,      /* 4 */
    giugno,      /* 5 */
    luglio,      /* 6 */
    agosto,      /* 7 */
    settembre,   /* 8 */
    ottobre,     /* 9 */
    novembre,    /* 10 */
    dicembre     /* 11 */
} mesi;



/* ========== MAIN - ESEMPI PRATICI ========== */

int main()
{
    /* --- ESEMPIO 1: Uso di struct Persona --- */
    
    /* Dichiarazione di una variabile di tipo struct Persona */
    struct Persona matteo;

    
    /* Inizializzazione dei campi della struct usando l'operatore punto (.) */
    assegnaStringa(matteo.nome, "Matteo");
    assegnaStringa(matteo.cognome, "Berrettini");
    matteo.tagliaScarpe = 45.0;
    
    /* Accesso e stampa dei dati */
    printf("\n=== ESEMPIO STRUCT PERSONA ===\n");
    printf("nome %s\n", matteo.nome);
    stampaPersona(matteo);

    /* --- ESEMPIO 2: Uso di typedef Alunno --- */
    
    /* Grazie a typedef, non serve scrivere "struct" */
    Alunno gianni;

    
    /* Inizializzazione dei campi */
    assegnaStringa(gianni.nome, "Gianni");
    assegnaStringa(gianni.cognome, "Gallina");
    gianni.altezza = 175.0;
    
    printf("\n=== ESEMPIO TYPEDEF ALUNNO ===\n");
    stampaAlunno(gianni);

    /* --- ESEMPIO 3: Uso di typedef per tipo primitivo --- */
    
    /* 'data' e' un alias per 'int', ma il nome e' piu' significativo */
    data tempoCorrente = 1636568423;  /* Unix timestamp: secondi dal 1-1-1970 */
    
    printf("\n=== ESEMPIO TYPEDEF DATA ===\n");
    printf("Tempo corrente (Unix timestamp): %d secondi\n", tempoCorrente);

    /* --- ESEMPIO 4: Uso di enum giorni --- */
    
    printf("\n=== ESEMPIO ENUM GIORNI ===\n");
    
    /* Assegnazione usando il nome simbolico invece del numero */
    giorni giornoAttuale = martedi;  /* martedi vale 1 */
    printf("Oggi e' il giorno numero %d (martedi)\n", giornoAttuale);
    
    /* NOTA: enum sono internamente interi, quindi non si puo' stampare il nome
       con %s. Per stampare il nome serve un array di stringhe o uno switch. */
    
    /* Incremento del valore enum */
    giorni domani = giornoAttuale + 1;  /* mercoledi = 2 */
    printf("Domani sara' il giorno numero %d (mercoledi)\n", domani);
    
    /* Ciclo attraverso i giorni della settimana */
    printf("Giorni della settimana (valori numerici): ");
    for(giorni g = lunedi; g <= domenica; g++)
    {
        printf("%d ", g);
    }
    printf("\n");

    /* --- ESEMPIO 5: Uso di enum mesi --- */
    
    printf("\n=== ESEMPIO ENUM MESI ===\n");
    
    mesi meseAttuale = novembre;  /* novembre vale 10 */
    printf("Siamo nel mese numero %d (novembre)\n", meseAttuale);
    
    /* Confronto con enum */
    if(meseAttuale == novembre)
    {
        printf("E' novembre! Quasi fine anno.\n");
    }

    /* --- ESEMPIO 6: Typedef per array --- */
    
    printf("\n=== ESEMPIO TYPEDEF ARRAY ===\n");
    
    /* Typedef puo' creare alias anche per array */
    typedef char Titolo[255];
    Titolo titolo;  /* Equivalente a: char titolo[255]; */
    
    strcpy(titolo, "Black Mirror");
    printf("Titolo serie TV: %s\n", titolo);
    
    /* Riepilogo vantaggi typedef:
       - Sintassi piu' semplice
       - Codice piu' leggibile
       - Facilita modifiche future */
    
    printf("\n=== FINE ESEMPI ===\n");

    return 0;
}
