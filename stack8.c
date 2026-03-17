/**
 * programma: mem_segmenti_con_parametri.c
 * Scopo: mostrare la suddivisione della memoria di un processo C
 *         (TEXT, DATA, BSS, STACK) escludendo l'HEAP.
 *         In particolare si evidenzia che anche i parametri
 *         delle funzioni sono allocati nello STACK.
 *
 * Compilazione: gcc -o mem_segmenti_con_parametri mem_segmenti_con_parametri.c
 * Esecuzione: ./mem_segmenti_con_parametri
 */

#include <stdio.h>

/* ========== VARIABILI GLOBALI ========== */

int var_glob_iniz = 100;          /* INIZIALIZZATA -> segmento DATA */
int var_glob_non_iniz;             /* NON inizializzata -> segmento BSS (varrà 0) */

static int var_static_iniz = 200;  /* INIZIALIZZATA -> DATA */
static int var_static_non_iniz;    /* NON inizializzata -> BSS */

/* ========== FUNZIONI ========== */

/* funzione che riceve un parametro (x) e ne stampa l'indirizzo */
void funzione_con_parametro(int x, int y) {
    int locale_fun = 40;           /* variabile locale -> STACK */
    printf("  [funzione_con_parametro] indirizzo del parametro x  : %p\n", (void*)&x);
    printf("  [funzione_con_parametro] indirizzo del parametro y  : %p\n", (void*)&y);
    printf("  [funzione_con_parametro] indirizzo di locale_fun    : %p\n", (void*)&locale_fun);
}

void funzione_media() {
    int locale_media = 30;          /* STACK */
    printf("[funzione_media] indirizzo di locale_media      : %p\n", (void*)&locale_media);
    /* chiamata con due parametri */
    funzione_con_parametro(5, 7);
}

/* ========== MAIN ========== */

int main() {
    int locale_main1 = 10;          /* STACK */
    int locale_main2 = 20;          /* STACK */

    printf("=== INDIRIZZI DEI SEGMENTI DI MEMORIA ===\n\n");

    /* --- SEGMENTO TEXT --- */
    printf("SEGMENTO TEXT (indirizzi delle funzioni):\n");
    printf("  Indirizzo di main                    : %p\n", (void*)main);
    printf("  Indirizzo di funzione_media          : %p\n", (void*)funzione_media);
    printf("  Indirizzo di funzione_con_parametro  : %p\n\n", (void*)funzione_con_parametro);

    /* --- SEGMENTO DATA --- */
    printf("SEGMENTO DATA (variabili con valore iniziale diverso da zero):\n");
    printf("  Indirizzo di var_glob_iniz           : %p\n", (void*)&var_glob_iniz);
    printf("  Indirizzo di var_static_iniz         : %p\n\n", (void*)&var_static_iniz);

    /* --- SEGMENTO BSS --- */
    printf("SEGMENTO BSS (variabili senza inizializzazione esplicita):\n");
    printf("  Indirizzo di var_glob_non_iniz       : %p\n", (void*)&var_glob_non_iniz);
    printf("  Indirizzo di var_static_non_iniz     : %p\n", (void*)&var_static_non_iniz);
    printf("  Valore di var_glob_non_iniz          : %d\n", var_glob_non_iniz);
    printf("  Valore di var_static_non_iniz        : %d\n\n", var_static_non_iniz);

    /* --- SEGMENTO STACK (variabili locali e parametri) --- */
    printf("SEGMENTO STACK (variabili locali e parametri):\n");
    printf("  (main) indirizzo di locale_main1     : %p\n", (void*)&locale_main1);
    printf("  (main) indirizzo di locale_main2     : %p\n\n", (void*)&locale_main2);

    printf("Ora chiamiamo funzione_media() che chiama funzione_con_parametro():\n");
    funzione_media();

    return 0;
}
