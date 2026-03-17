# LISTA ESERCIZI - Gestione Memoria e Puntatori in C

## Livello 1: Fondamenti di Memoria

### Esercizio 1.1 - Indirizzi di Memoria
Scrivi un programma che:
- Dichiara 3 variabili globali di tipo `int`, `double` e `char`
- Dichiara 3 variabili locali nel `main` degli stessi tipi
- Stampa gli indirizzi di tutte le variabili
- Osserva e commenta le differenze tra gli indirizzi delle variabili globali e locali

**Riferimento**: `stack1.c`

### Esercizio 1.2 - Variabili Static
Scrivi un programma che:
- Dichiara una variabile globale normale
- Dichiara una variabile globale `static`
- Dichiara una variabile locale `static` dentro una funzione
- Stampa gli indirizzi e spiega dove vengono allocate (DATA, BSS, STACK)

**Riferimento**: `stack2.c`, `stack8.c`

---

## Livello 2: Array e Stringhe

### Esercizio 2.1 - Array di Caratteri
Scrivi un programma che:
- Dichiara un array di caratteri globale con una stringa
- Dichiara un array di caratteri locale nel `main`
- Stampa l'indirizzo del primo elemento di entrambi gli array
- Prova a modificare i caratteri degli array e osserva cosa succede

**Riferimento**: `stack3.c`

### Esercizio 2.2 - Puntatori a Stringhe
Scrivi un programma che:
- Dichiara un puntatore a `char` globale
- Nel `main`, assegna al puntatore l'indirizzo di un array locale
- Prova a stampare la stringa dopo che il `main` ha chiamato una funzione
- Spiega perché si verifica un comportamento inaspettato

**Riferimento**: `stack5.c`, `stack6.c`

### Esercizio 2.3 - Funzione per Lunghezza Stringa
Implementa una funzione `int lunghezza(char *str)` che:
- Conta i caratteri di una stringa (escluso `\0`)
- Restituisce la lunghezza
- Nel `main`, testa la funzione con diverse stringhe

**Riferimento**: `stack6.c`

---

## Livello 3: Segmenti di Memoria

### Esercizio 3.1 - Visualizzazione Segmenti
Scrivi un programma completo che mostra tutti i segmenti di memoria:
- **TEXT**: stampa gli indirizzi di almeno 3 funzioni
- **DATA**: dichiara 2 variabili globali inizializzate
- **BSS**: dichiara 2 variabili globali non inizializzate
- **STACK**: dichiara variabili locali in `main` e in una funzione
- Stampa tutti gli indirizzi con etichette chiare

**Riferimento**: `stack8.c`

### Esercizio 3.2 - Parametri sullo Stack
Scrivi un programma che:
- Definisce una funzione che accetta 3 parametri `int`
- Dichiara una variabile locale nella funzione
- Stampa gli indirizzi dei 3 parametri e della variabile locale
- Nel `main`, stampa l'indirizzo delle variabili locali
- Osserva come i parametri sono allocati nello STACK

**Riferimento**: `stack8.c`

---

## Livello 4: Passaggio Parametri

### Esercizio 4.1 - Passaggio per Valore
Scrivi un programma con una funzione `void raddoppia_valore(int x)` che:
- Moltiplica `x` per 2
- Stampa l'indirizzo di `x` dentro la funzione
- Nel `main`, chiama la funzione con una variabile `a`
- Stampa il valore di `a` prima e dopo la chiamata
- Spiega perché `a` non viene modificata

**Riferimento**: `stack9.c`

### Esercizio 4.2 - Passaggio per Indirizzo
Scrivi un programma con una funzione `void raddoppia_indirizzo(int *p)` che:
- Moltiplica `*p` per 2
- Stampa l'indirizzo contenuto in `p` e l'indirizzo di `p` stesso
- Nel `main`, chiama la funzione passando l'indirizzo di una variabile
- Verifica che la variabile originale viene modificata

**Riferimento**: `stack9.c`

### Esercizio 4.3 - Confronto Passaggi
Scrivi un programma che:
- Definisce due funzioni: `void incrementa_valore(int x)` e `void incrementa_indirizzo(int *p)`
- Entrambe incrementano di 1 il parametro
- Nel `main`, testa entrambe le funzioni sulla stessa variabile
- Stampa tutti gli indirizzi coinvolti e spiega le differenze

**Riferimento**: `stack9.c`

---

## Livello 5: Puntatori a Funzione

### Esercizio 5.1 - Puntatore a Funzione Base
Scrivi un programma che:
- Definisce una funzione `void stampa_messaggio()` che stampa "Ciao!"
- Dichiara un puntatore a funzione globale che punta a `stampa_messaggio`
- Nel `main`, chiama la funzione tramite il puntatore
- Stampa l'indirizzo della funzione e l'indirizzo del puntatore

**Riferimento**: `stack10.c`

### Esercizio 5.2 - Puntatore a Funzione con Parametri
Scrivi un programma che:
- Definisce 3 funzioni matematiche: `int somma(int a, int b)`, `int prodotto(int a, int b)`, `int differenza(int a, int b)`
- Dichiara un puntatore a funzione `int (*operazione)(int, int)`
- Nel `main`, usa un `switch` per assegnare al puntatore una delle 3 funzioni
- Esegui l'operazione scelta e stampa il risultato

**Riferimento**: `stack11.c`

### Esercizio 5.3 - Puntatore a Funzione come Parametro
Scrivi un programma che:
- Definisce funzioni: `double triplo(double x)`, `double radice_quadrata_approssimata(double x)` (usa `x/2` come approssimazione)
- Definisce una funzione `void esegui_operazione(double num, double (*func)(double))` che applica la funzione passata
- Nel `main`, chiama `esegui_operazione` con diverse funzioni

**Riferimento**: `stack12.c`

### Esercizio 5.4 - Array di Puntatori a Funzione
Scrivi un programma che:
- Definisce 4 funzioni matematiche che accettano un `int` e restituiscono un `int`
- Crea un array di puntatori a funzione contenente tutte e 4 le funzioni
- Nel `main`, usa un ciclo `for` per eseguire tutte le funzioni su un valore
- Stampa i risultati con etichette descrittive

**Riferimento**: `stack12a.c`

### Esercizio 5.5 - Calcolatrice con Array di Puntatori
Scrivi un programma che:
- Definisce funzioni per le 4 operazioni base: `+`, `-`, `*`, `/`
- Crea un array di puntatori a funzione
- Crea un array parallelo con i simboli delle operazioni (`char simboli[] = "+-*/"`)
- Chiede all'utente due numeri e un operatore
- Usa l'array per trovare ed eseguire l'operazione corretta

**Riferimento**: `stack11.c`, `stack12a.c`

---

## Livello 6: Argomenti da Linea di Comando

### Esercizio 6.1 - argc e argv Base
Scrivi un programma che:
- Stampa il numero di argomenti ricevuti (`argc`)
- Stampa tutti gli argomenti uno per uno usando un ciclo
- Testa il programma passando diversi argomenti da linea di comando

**Riferimento**: `stack12b.c`

### Esercizio 6.2 - Conversione Argomenti
Scrivi un programma che:
- Accetta 3 argomenti da linea di comando: due numeri e un operatore
- Converte i primi due argomenti in `double` usando `atof()`
- Esegue l'operazione indicata dal terzo argomento
- Gestisce il caso in cui non vengono forniti abbastanza argomenti

**Riferimento**: `stack12b.c`, `stack11.c`

### Esercizio 6.3 - Calcolatrice Completa da CLI
Scrivi un programma che:
- Accetta argomenti: `./programma <numero1> <operatore> <numero2>`
- Usa un array di puntatori a funzione per le operazioni
- Valida gli input (controlla che l'operatore sia valido)
- Gestisce la divisione per zero
- Stampa un messaggio di errore chiaro se gli argomenti sono sbagliati

**Riferimento**: `stack12b.c`, `stack11.c`, `stack12a.c`

---

## Livello 7: Progetti Integrati

### Progetto 7.1 - Analizzatore di Memoria
Crea un programma completo che:
- Dichiara variabili in tutti i segmenti (TEXT, DATA, BSS, STACK)
- Usa puntatori a funzione
- Passa parametri per valore e per indirizzo
- Stampa una mappa completa della memoria con tutti gli indirizzi
- Calcola e mostra le distanze in byte tra i vari segmenti

**Riferimento**: tutti i file `stack8.c`, `stack9.c`, `stack10.c`

### Progetto 7.2 - Sistema di Callback
Crea un programma che:
- Definisce diverse funzioni di "callback" (es: `on_success`, `on_error`, `on_warning`)
- Crea una funzione `void esegui_con_callback(int codice, void (*callback)())` che esegue la callback appropriata
- Nel `main`, simula diverse situazioni e chiama `esegui_con_callback` con la callback corretta
- Usa un array di puntatori a funzione per gestire multiple callback

**Riferimento**: `stack12.c`, `stack12a.c`

### Progetto 7.3 - Mini-Framework di Testing
Crea un programma che:
- Definisce una struttura per i test: nome del test e puntatore a funzione
- Crea un array di test da eseguire
- Implementa una funzione `void esegui_tutti_i_test()` che esegue tutti i test nell'array
- Ogni test restituisce 1 (successo) o 0 (fallimento)
- Stampa un report finale con il numero di test passati/falliti

**Riferimento**: `stack12a.c`, `stack12b.c`

---

## Note per gli Studenti

- Compila sempre con `gcc -Wall -Wextra` per vedere tutti i warning
- Usa `printf` con `%p` per stampare indirizzi di memoria
- Ricorda di fare il cast a `(void*)` quando stampi indirizzi
- Sperimenta modificando il codice per capire meglio i concetti
- Disegna diagrammi della memoria per visualizzare stack, heap, data, text

## Suggerimenti di Studio

1. Inizia dagli esercizi di Livello 1 e procedi in ordine
2. Per ogni esercizio, prima leggi il file di riferimento
3. Prova a risolvere l'esercizio senza guardare la soluzione
4. Compila ed esegui il programma
5. Analizza gli indirizzi di memoria stampati
6. Confronta con il file di riferimento se hai dubbi
