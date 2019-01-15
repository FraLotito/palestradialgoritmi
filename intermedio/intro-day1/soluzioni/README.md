# Soluzioni Day1


* ## Trova il massimo (easy1)
### Breve spiegazione del testo
Il problema richiede di trovare il massimo di una sequenza di numeri interi compresi tra -1000 e 1000; è dato il numero di interi (N) nella sequenza contenuta nel file di input.

### Idee generali per risolvere l'esercizio
Per risolvere l'esercizio si sfrutta l'idea del massimo parziale, ovvero:
* Inizializziamo la variabile ```maxn``` con il valore del primo numero letto.
* Alla lettura dell'i-esimo numero si aggiorna il massimo del sotto-vettore [0..i] soltanto se questo è maggiore del massimo già calcolato per il sotto-vettore [0..i-1]
* Alla lettura dell'ultimo intero la variabile ```maxn``` conterrà il valore massimo dell'intera sequenza di elementi (da 0 a N-1).

### Idee alternative
Anziché calcolare il massimo parziale subito dopo la lettura di ogni numero si può usare un array per memorizzare l'intera sequenza e poi calcolare il massimo iterando sull'array. Questa soluzione è accettabile, bisogna tuttavia fare attenzione allo spreco di memoria dato dal fatto di mantenere in memoria tutti i valori, anche quando questi non sono più necessari.
Soluzioni che effettuano tutti i possibili confronti (O(n^2)) invece non sono sufficientemente efficienti, come non lo sono quelle che prevedono di stampare l'ultimo elemento dell'array precedentemente ordinato (O(n log n)).


* ## Trova la somma pari massima (easy2)
### Breve spiegazione del testo
Il problema richiede, date N coppie di numeri interi positivi, di trovare quale sia la massima somma tra i due numeri delle coppie che è anche pari. Se tale somma non esiste bisogna stampare -1.

### Idee generali per risolvere l'esercizio
La risoluzione si basa sempre sui massimi parziali, come nell'esercizio precedente. Le differenze sono:
* Inizializziamo la variabile ```maxn``` a -1 per fare in modo che se non esiste nessuna somma pari il nostro programma stampi il valore atteso dal correttore
* Prima di aggiornare la variabile che contiene il massimo effettuiamo la lettura di entrambi i numeri della coppia e controlliamo se la loro somma è pari (```(a + b) % 2 == 0```)

__NOTA:__ se non esiste alcuna somma pari allora ```(a + b) % 2 == 0``` restituirà sempre ```false``` e il valore di ```maxn``` rimarrà -1 fino alla fine del ciclo, quando la variabile viene stampata sul file.

### Idee alternative
Come in Easy 1, anche in questo caso si potevano salvare tutti i valori prima di elaborarli, le implicazioni sono le stesse già citate per il problema precedente.


* ## Trova la somma pari massima v2.0 (easy3)
### Breve spiegazione del testo
Il problema richiede, dati N numeri naturali, di trovare, per ogni possibile coppia di numeri, la somma massima che sia anche pari. Se tale somma non esiste, bisogna stampare -1.

### Idee generali per risolvere l'esercizio
Prima di tutto, una qualsiasi somma pari può essere ottenuta in due modi: dalla somma di due numeri pari o dalla somma di due numeri dispari. Quindi per avere la massima somma pari abbiamo due possibilità: questa può essere data dalla somma dei due numeri pari più grandi oppure dalla somma dei due dispari maggiori. Troviamo quindi questi valori e poi confrontiamo le due somme. 

__NOTA:__ Questa somma non esiste in poche situazioni: se non esiste nessuna coppia di numeri pari all'interno della sequenza e non esiste neanche una coppia di numeri dispari. Ovvero se ci sono al più due numeri: uno pari ed uno dispari.

### Idee alternative
Si può pensare di salvare tutti i valori in un vettore e calcolare tutte le possibili somme delle coppie (con due cicli for), controllando quando questa somma sia pari e tenendo il massimo memorizzato in una variabile. Questo è molto più costoso e rende l'algoritmo di complessità O(n^2), quando ora ha complessità O(n). 

* ## Fluttuazioni finanziare (azioni)

### Breve spiegazione del testo
Il testo richiede di trovare, data una sequenza A di N numeri interi, la massima differenza in valore assoluto tra due numeri consecutivi della sequenza stessa.

### Idee generali per risolvere l'esercizio
Applichiamo ancora lo stesso principio di risoluzione usato per Easy 1. Inizializziamo il massimo a |A[1] - A[2]|, poi calcoliamo, per ogni valore x in A[2..n-1], la differenza tra x e il precedente e andiamo ad aggiornare il massimo solo se tale differenza è maggiore di quella trovata in precedenza.

### Idee alternative
La nostra soluzione tiene in memoria di volta in volta solo il numero x e il precedente, è ovviamente ancora possibile salvare tutta la sequeza in un array e poi lavorare sulla sequenza salvata.

* ## Sequenza di Pollatz (pcollatz)

### Breve spiegazione del testo

In questo problema vengono dati due algoritmi (di Collatz e Pollatz) che, partendo da un input N, generano una sequenza di numeri seguendo alcune regole. L'algoritmo di Collaz, dato un intero positivo N, è il seguente.

(1) Se N vale 1, l’algoritmo termina.

(2) Se N è pari, dividi N per 2, altrimenti (se N è dispari) moltiplicalo per **3** e aggiungi 1.

L'algoritmo di Pollatz è analogo, ma prevede che al punto (2) si moltiplichi per **5** invece che per 3. Per tutti gli input N, il primo algoritmo termina. Per alcuni N, la lunghezza della sequenza di numeri calcolati con il secondo è minore di quella calcolata con il primo, mentre per altri N, Pollatz non termina mai. Dati due interi A e B (A ≤ B), il problema chiede quanti sono gli N, con A ≤ N ≤ B, per cui la lunghezza della sequenza di Pollatz calcolata a partire da N termina e ha lunghezza strettamente minore della corrispondente sequenza di Collatz.

### Idee generali per risolvere l'esercizio
Per semplicità indichiamo con c(N) la lunghezza della sequenza di Collatz calcolata da N e con p(N) la lunghezza di quella di Pollatz (ricordiamo che p(N) potrebbe essere infinito). Per risolvere l'esercizio, per ogni N compreso tra A e B, vogliamo calcolare c(N) e p(N) e vedere se p(N) è minore di c(N). Dato che non sappiamo se l'algoritmo di Pollatz termina, dobbiamo prima calcolare la lunghezza di quello di Collatz, c(N), e poi quella di Pollatz, fermandoci nel momento in cui questa supera c(N). 
Per calcolare questi due valori è sufficiente usare dei cicli while, ad esempio per Collatz:
```cpp
int c = 1;
while(N != 1) {
	if(N%2 == 0) N/=2;
        else N = 3*N + 1;
        c++;
}
```

### Idee alternative
Invece di un ciclo while, per calcolare la lunghezza delle sequenze di Collatz e Pollatz, si potrebbe usare una funzione ricorsiva, la complessità dell'algoritmo non cambia.

* ## La spartizione di Totò (spartizione)

### Breve spiegazione del testo

È dato un numero G di oggetti (le gemme) da spartire tra Totò e i suoi compagni, in tutto P persone. Ad ogni ciclo di spartizione i, Totò prende i gemme, mentre i suoi complici ne ricevono 1 ciascuno. Bisogna trovare quanti oggetti spettano in tutto a Totò.

### Idee generali per risolvere l'esercizio
Simuliamo la spartizione con un ciclo sul numero di gemme rimanenti e teniamo in un contatore il numero di gemme che abbiamo assegnato a Totò:
```cpp
while(G-i-P+1>=0) {
        G = G-i-P+1;
        res += i;
        i++;
    }
```

### Idee alternative
Si potrebbe implementare la risoluzione dell'equazione:

![formula](https://latex.codecogs.com/gif.latex?\sum\limits_{i=0}^k&space;i&space;&plus;&space;k(P-1)&space;=&space;\frac{k(k-1)}{2}&space;&plus;&space;k(P-1)&space;=&space;G)

Tuttavia questo richiede di gestire tutti i casi in cui il numero di gemme non può essere correttamente spartito tra i ladri.

* ## Festa di laurea (laurea)
### Breve spiegazione del testo
Il problema richiede di minimizzare il costo del trasporto di N persone da un punto A ad un punto B potendo utilizzare 4 tipologie di veicoli, che possono trasportare 2, 4, 5 o 7 persone. Il veicolo V<sub>i</sub> avrà costo P<sub>i</sub> e disponibilità D<sub>i</sub>, dati in input.

### Idee generali per risolvere l'esercizio
Una semplice idea, che prende 100 / 100, è provare tutti i modi validi per raggiungere B partendo da A e salvare quello che risulta avere il costo minore.
```cpp

M = ∞

void solve(int N, int qa, int qb, int qc, int qd, int prezzo) {
    if(N <= 0) M = min(prezzo, M);
    else {
        if(qa > 0) solve(N-2, qa-1, qb, qc, qd, prezzo + pa);
        if(qb > 0) solve(N-4, qa, qb-1, qc, qd, prezzo + pb);
        if(qc > 0) solve(N-5, qa, qb, qc-1, qd, prezzo + pc);
        if(qd > 0) solve(N-7, qa, qb, qc, qd-1, prezzo + pd);
    }
}
```

Il codice è abbastanza semplice, se abbiamo la possibilità di usare ancora il veicolo V<sub>i</sub> allora lo usiamo, e chiamiamo la funzione che risolverà il sotto-problema con (N - P<sub>i</sub>) persone, (D<sub>i</sub> - 1) disponibilità e (prezzo + P<sub>i</sub>) costo speso finora. E così via per tutti i veicoli V<sub>i</sub>. Quando vorrò risolvere un problema con N <= 0 persone, allora potrò considerare il costo speso finora come il costo totale, confrontarlo con una variabile che conterrà il miglior risultato ottenuto e prendere il minimo.


### Idee alternative
Ci sono modi migliori per risolverlo, stay tuned.


* ## Turni di guardia (turni)
### Breve spiegazione del testo
Il problema può essere visto in questo modo: avendo un intervallo `[0, K)`, bisogna riuscire a coprirlo tutto minimizzando il numero di intervallini `[A, B)` dati in input.

### Idee generali per risolvere l'esercizio
In questo problema si può arrivare molto velocemente alla soluzione se si riesce a stabilire che si tratta
di un problema di tipo greedy. Si arriva a mostrare che è così tramite le seguenti osservazioni:
* gli intervalli dei turni di guardia devono coprire completamente tutti i giorni, come da testo del
problema, quindi esiste almeno un intervallo che inizia dal primo giorno:

	* se è solo uno lo scelgo e questa scelta non può essere cambiata, perchè nessun altro intervallo
potrebbe coprire il primo giorno

	* se sono più di uno scelgo quello che ha la data di fine maggiore, perchè sceglierne un altro
comporterebbe solo un numero minore di giorni di “copertura” e nessun vantaggio. Anche
in questo caso la scelta non potrà essere modificata successivamente, perchè nessuna altra
scelta potrebbe portarmi in una situazione migliore

* a questo punto la data di fine del turno scelto sarà la nuova data di inizio per scegliere i turni
successivi, reiterando il procedimento dal punto 1, fino a quando non verrà selezionato un turno
che finisce l’ultimo giorno.

In questo modo si è arrivati alla conclusione che il problema è di tipo greedy, e quindi conviene ordinare
i turni di guardia usando come parametro per l’ordinamento il giorno di inizio, in modo da
poter implementare in maniera efficiente l’algoritmo appena descritto.

__NOTA:__ grazie al prof. Bugatti per questa spiegazione, ho usato la sua perché è chiarissima e non avrei saputo far di meglio

