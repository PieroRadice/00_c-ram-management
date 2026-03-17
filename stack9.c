/**
 * programma: passaggio_parametri.c
 * Scopo: mostrare la differenza tra passaggio per valore e per indirizzo,
 *        visualizzando gli indirizzi di memoria delle variabili e dei parametri.
 *
 * Concetti chiave:
 * - Le variabili locali e i parametri risiedono nello STACK.
 * - Nel passaggio per valore si riceve una COPIA: il parametro ha un indirizzo diverso.
 * - Nel passaggio per indirizzo si riceve l'INDIRIZZO della variabile originale,
 *   quindi tramite il puntatore si può modificare la variabile originale.
 *
 * Compilazione: gcc -o passaggio_parametri passaggio_parametri.c
 * Esecuzione: ./passaggio_parametri
 */

#include <stdio.h>

/* Funzione con passaggio per VALORE */
void per_valore(int x) {
    /* x è un parametro formale: è una variabile LOCALE alla funzione,
       allocata nello STACK, che contiene una COPIA del valore passato. */
    printf("  [per_valore] indirizzo del parametro x (locale): %p\n", (void*)&x);
    printf("  [per_valore] valore iniziale di x = %d\n", x);
    x = 100;  // modifica la copia locale
    printf("  [per_valore] dopo modifica, x = %d\n", x);
    // al termine, x viene distrutta (la modifica non influisce sul chiamante)
}

/* Funzione con passaggio per INDIRIZZO (usa un puntatore) */
void per_indirizzo(int *p) {
    /* p è un parametro formale: variabile LOCALE allo stack,
       che contiene l'INDIRIZZO della variabile passata dal chiamante. */
    printf("  [per_indirizzo] indirizzo del parametro p (locale): %p\n", (void*)&p);
    printf("  [per_indirizzo] p contiene l'indirizzo: %p\n", (void*)p);
    printf("  [per_indirizzo] valore della variabile puntata (*p) = %d\n", *p);
    *p = 200;  // modifica la variabile ORIGINALE (quella il cui indirizzo è stato passato)
    printf("  [per_indirizzo] dopo modifica, *p = %d\n", *p);
    // p viene distrutto, ma la modifica alla variabile originale rimane
}

int main() {
    int a = 10;           // variabile locale nel main -> STACK
    int b = 99;           // un'altra variabile locale (per osservare lo stack)

    printf("=== INDIRIZZI NEL MAIN ===\n");
    printf("Indirizzo di a (main): %p\n", (void*)&a);
    printf("Indirizzo di b (main): %p\n\n", (void*)&b);

    /* --- Passaggio per VALORE --- */
    printf("--- CHIAMATA per_valore(a) ---\n");
    per_valore(a);                // passiamo a per valore (copia)
    printf("Dopo chiamata per_valore, a nel main vale: %d (NON modificata!)\n\n", a);

    /* --- Passaggio per INDIRIZZO --- */
    printf("--- CHIAMATA per_indirizzo(&a) ---\n");
    per_indirizzo(&a);             // passiamo l'indirizzo di a
    printf("Dopo chiamata per_indirizzo, a nel main vale: %d (MODIFICATA!)\n\n", a);

    /* Mostriamo che anche i parametri sono sullo stack,
       osservando gli indirizzi delle variabili locali nelle funzioni.
       Per farlo, richiamiamo le funzioni una dopo l'altra e notiamo
       come gli indirizzi dei parametri sono vicini a quelli delle altre variabili locali.
    */
    printf("--- CONFRONTO INDIRIZZI SULLO STACK ---\n");
    printf("Per vedere che i parametri sono nello stack, chiamiamo le funzioni in sequenza:\n");
    per_valore(5);          // chiamata con costante
    per_indirizzo(&b);      // passiamo l'indirizzo di b
    printf("Indirizzo di b (main) dopo le chiamate: %p\n", (void*)&b);
    printf("Osserva come gli indirizzi dei parametri sono vicini a quelli delle\n");
    printf("variabili locali delle funzioni e del main (tutti nella zona STACK).\n");

    return 0;
}
