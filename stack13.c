/**
 * programma: heap_introduzione.c
 * Scopo: introdurre la memoria HEAP e le funzioni malloc() e free()
 *
 * Concetti chiave:
 * - L'HEAP è un'area di memoria dinamica gestita dal programmatore
 * - malloc() alloca memoria nell'HEAP e restituisce un puntatore
 * - free() libera la memoria precedentemente allocata
 * - La memoria HEAP persiste finché non viene esplicitamente liberata
 * - Differenza tra STACK (automatica) e HEAP (manuale)
 *
 * Compilazione: gcc -o stack13 stack13.c
 * Esecuzione: ./stack13
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int var_globale = 42;

void esempio_stack_vs_heap() {
    int var_stack = 10;
    
    int *ptr_heap = (int*)malloc(sizeof(int));
    
    if(ptr_heap == NULL) {
        printf("Errore: malloc ha fallito!\n");
        return;
    }
    
    *ptr_heap = 20;
    
    printf("\n=== CONFRONTO STACK vs HEAP ===\n");
    printf("Variabile sullo STACK:\n");
    printf("  Indirizzo di var_stack: %p\n", (void*)&var_stack);
    printf("  Valore di var_stack: %d\n", var_stack);
    
    printf("\nVariabile sull'HEAP:\n");
    printf("  Indirizzo del puntatore ptr_heap (sullo stack): %p\n", (void*)&ptr_heap);
    printf("  Valore di ptr_heap (indirizzo heap): %p\n", (void*)ptr_heap);
    printf("  Valore puntato (*ptr_heap): %d\n", *ptr_heap);
    
    printf("\nVariabile GLOBALE (DATA):\n");
    printf("  Indirizzo di var_globale: %p\n", (void*)&var_globale);
    
    free(ptr_heap);
    printf("\nMemoria heap liberata con free()\n");
}

void esempio_array_dinamico() {
    int n = 5;
    
    int *array = (int*)malloc(n * sizeof(int));
    
    if(array == NULL) {
        printf("Errore: malloc ha fallito!\n");
        return;
    }
    
    printf("\n=== ARRAY DINAMICO SULL'HEAP ===\n");
    printf("Allocati %d interi sull'heap\n", n);
    printf("Indirizzo iniziale dell'array: %p\n", (void*)array);
    
    for(int i = 0; i < n; i++) {
        array[i] = (i + 1) * 10;
        printf("  array[%d] = %d, indirizzo: %p\n", i, array[i], (void*)&array[i]);
    }
    
    printf("\nSomma degli elementi: ");
    int somma = 0;
    for(int i = 0; i < n; i++) {
        somma += array[i];
    }
    printf("%d\n", somma);
    
    free(array);
    printf("Array liberato con free()\n");
}

void esempio_stringa_dinamica() {
    char input[100];
    
    printf("\n=== STRINGA DINAMICA SULL'HEAP ===\n");
    printf("Inserisci una stringa: ");
    scanf("%99[^\n]", input);
    while(getchar() != '\n');
    
    int lunghezza = strlen(input);
    
    char *stringa_heap = (char*)malloc((lunghezza + 1) * sizeof(char));
    
    if(stringa_heap == NULL) {
        printf("Errore: malloc ha fallito!\n");
        return;
    }
    
    strcpy(stringa_heap, input);
    
    printf("\nStringa copiata sull'heap: %s\n", stringa_heap);
    printf("Lunghezza: %d caratteri\n", lunghezza);
    printf("Indirizzo della stringa heap: %p\n", (void*)stringa_heap);
    printf("Memoria allocata: %d bytes\n", lunghezza + 1);
    
    free(stringa_heap);
    printf("Stringa liberata con free()\n");
}

void esempio_memoria_persistente() {
    printf("\n=== PERSISTENZA MEMORIA HEAP ===\n");
    
    int *ptr1 = (int*)malloc(sizeof(int));
    int *ptr2 = (int*)malloc(sizeof(int));
    int *ptr3 = (int*)malloc(sizeof(int));
    
    if(ptr1 == NULL || ptr2 == NULL || ptr3 == NULL) {
        printf("Errore: malloc ha fallito!\n");
        free(ptr1);
        free(ptr2);
        free(ptr3);
        return;
    }
    
    *ptr1 = 100;
    *ptr2 = 200;
    *ptr3 = 300;
    
    printf("Tre allocazioni consecutive:\n");
    printf("  ptr1: %p -> valore %d\n", (void*)ptr1, *ptr1);
    printf("  ptr2: %p -> valore %d\n", (void*)ptr2, *ptr2);
    printf("  ptr3: %p -> valore %d\n", (void*)ptr3, *ptr3);
    
    printf("\nDistanza in bytes tra allocazioni:\n");
    printf("  ptr2 - ptr1 = %ld bytes\n", (char*)ptr2 - (char*)ptr1);
    printf("  ptr3 - ptr2 = %ld bytes\n", (char*)ptr3 - (char*)ptr2);
    
    free(ptr1);
    free(ptr2);
    free(ptr3);
    printf("\nTutte le allocazioni liberate\n");
}

int main() {
    printf("=== INTRODUZIONE ALLA MEMORIA HEAP ===\n");
    printf("\nLa memoria HEAP permette di allocare memoria dinamicamente durante l'esecuzione.\n");
    printf("A differenza dello STACK, la memoria HEAP:\n");
    printf("  - Viene allocata con malloc() / calloc() / realloc()\n");
    printf("  - Deve essere liberata manualmente con free()\n");
    printf("  - Persiste finche' non viene liberata\n");
    printf("  - Ha dimensione limitata solo dalla RAM disponibile\n");
    
    esempio_stack_vs_heap();
    
    esempio_array_dinamico();
    
    esempio_stringa_dinamica();
    
    esempio_memoria_persistente();
    
    printf("\n=== REGOLE IMPORTANTI ===\n");
    printf("1. Controlla sempre se malloc() restituisce NULL\n");
    printf("2. Libera SEMPRE la memoria allocata con free()\n");
    printf("3. Non usare memoria dopo averla liberata (dangling pointer)\n");
    printf("4. Non liberare la stessa memoria due volte (double free)\n");
    printf("5. Non perdere il puntatore (memory leak)\n");
    
    return 0;
}
