# Gestione Memoria in C - Esempi e Esercizi

Repository didattico per l'apprendimento della gestione della memoria in C, con focus su stack, heap, puntatori e puntatori a funzione.

## 📚 Contenuti

Questo repository contiene una serie progressiva di esempi pratici che coprono:

- **Gestione della memoria**: Stack, Heap, segmenti TEXT, DATA, BSS
- **Puntatori**: Dichiarazione, utilizzo, aritmetica dei puntatori
- **Array e stringhe**: Gestione dinamica e statica
- **Puntatori a funzione**: Dichiarazione, utilizzo, array di puntatori a funzione
- **Passaggio parametri**: Per valore vs per indirizzo
- **Allocazione dinamica**: malloc(), free(), gestione della memoria heap
- **Argomenti da linea di comando**: argc, argv

## 📂 Struttura dei File

### File Principali

- **stack1.c** - Variabili globali e indirizzi di memoria
- **stack2.c** - Variabili static
- **stack3.c** - Array di caratteri e stringhe
- **stack4.c** - Puntatori e array
- **stack5.c** - Gestione puntatori a stringhe
- **stack6.c** - Funzioni per manipolazione stringhe
- **stack7.c** - Approfondimento stringhe e memoria
- **stack8.c** - Segmenti di memoria (TEXT, DATA, BSS, STACK)
- **stack9.c** - Passaggio parametri per valore e per indirizzo
- **stack10.c** - Introduzione ai puntatori a funzione
- **stack11.c** - Calcolatrice con puntatori a funzione
- **stack12.c** - Puntatore a funzione come parametro
- **stack12a.c** - Array di puntatori a funzione
- **stack12b.c** - Argomenti da linea di comando (argc, argv)
- **stack13.c** - Memoria HEAP: malloc() e free()
- **stack14.c** - Tipi di dato personalizzati (struct, typedef, enum)

### File di Supporto

- **ESERCIZI_STUDENTI.md** - Lista completa di esercizi organizzati per livello

## 🚀 Compilazione ed Esecuzione

### Compilare un singolo file

```bash
gcc -Wall -Wextra -o nome_programma nome_file.c
```

### Esempio

```bash
gcc -Wall -Wextra -o stack1 stack1.c
./stack1
```

### Compilare con debug

```bash
gcc -Wall -Wextra -g -o nome_programma nome_file.c
```

## 📖 Percorso di Studio Consigliato

1. **Livello Base** (stack1-stack5): Fondamenti di memoria e puntatori
2. **Livello Intermedio** (stack6-stack9): Funzioni, stringhe, passaggio parametri
3. **Livello Avanzato** (stack10-stack12b): Puntatori a funzione e argomenti CLI
4. **Livello Esperto** (stack13): Gestione dinamica della memoria (HEAP)

## 🎯 Esercizi

Consulta il file `ESERCIZI_STUDENTI.md` per una lista completa di esercizi organizzati in 7 livelli di difficoltà crescente.

Ogni esercizio include:
- Descrizione dettagliata
- Obiettivi di apprendimento
- Riferimenti ai file di esempio
- Suggerimenti per la risoluzione

## 🔍 Concetti Chiave

### Segmenti di Memoria

- **TEXT**: Codice eseguibile e funzioni
- **DATA**: Variabili globali/static inizializzate
- **BSS**: Variabili globali/static non inizializzate
- **STACK**: Variabili locali, parametri funzioni (gestione automatica)
- **HEAP**: Memoria dinamica allocata con malloc() (gestione manuale)

### Puntatori a Funzione

```c
// Dichiarazione
double (*operazione)(double, double);

// Assegnazione
operazione = somma;

// Chiamata
risultato = operazione(5.0, 3.0);
```

### Allocazione Dinamica

```c
// Allocazione
int *ptr = (int*)malloc(sizeof(int) * n);

// Controllo
if(ptr == NULL) {
    // Gestione errore
}

// Utilizzo
ptr[0] = 10;

// Liberazione
free(ptr);
```

## ⚠️ Best Practices

1. **Sempre controllare** il valore di ritorno di `malloc()`
2. **Liberare sempre** la memoria allocata con `free()`
3. **Non usare** memoria dopo averla liberata (dangling pointer)
4. **Non liberare** la stessa memoria due volte (double free)
5. **Compilare con warning** attivi: `-Wall -Wextra`
6. **Usare valgrind** per verificare memory leaks (su Linux/Mac)

## 🛠️ Strumenti Utili

- **gcc**: Compilatore C
- **gdb**: Debugger
- **valgrind**: Analisi memory leaks (Linux/Mac)
- **Dr. Memory**: Analisi memory leaks (Windows)

## 📝 Note

- I file sono progressivi: ogni file si basa sui concetti dei precedenti
- Leggere i commenti nel codice per comprendere i concetti
- Sperimentare modificando il codice
- Usare `printf` con `%p` per visualizzare indirizzi di memoria

## 🤝 Contributi

Questo è un repository didattico. Sentiti libero di:
- Segnalare errori
- Proporre miglioramenti
- Aggiungere esempi
- Condividere soluzioni agli esercizi

## 📄 Licenza

Materiale didattico open source per l'apprendimento della programmazione in C.

---

**Buono studio! 🎓**
