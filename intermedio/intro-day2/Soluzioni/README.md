# Soluzioni Day2

* ## Grand Prix
### Breve spiegazione del testo
Il problema richiede, data una sequenza di interi, che definisce l'ordine di partenza delle vetture, e una serie di sorpassi tra le auto (coppie _(sorpassante, sorpassato)_) di trovare quale sia il pilota in testa alla fine della gara.

### Idee generali per risolvere l'esercizio
Simuliamo i vari sorpassi, uno dopo l'altro, invertendo nella classifica (nel vettore delle posizioni) le auto coinvolte. Nello specifico dobbiamo, per ogni coppia, cercare i valori nel vettore e scambiarli (usiamo una terza variabile d'appoggio, procedura standard). Al termine dell'esecuzione il vincitore della corsa occupa la prima posizione dell'array.

### Idee alternative
A me non ne viene in mente nessuna, ma se voi ne avete trovate altre siamo ben lieti di sentirle :wink:

* ## Sommelier
![Wine](https://i.pinimg.com/originals/c0/ef/1b/c0ef1ba1c53b3cc1dc07d63dafa68ad0.jpg)
### Breve spiegazione del testo
Sono dati in input N numeri interi, ciascuno dei quali rappresenta la gradazione alcolica di un certo vino. Il problema richiede di trovare la lunghezza della massima sottosequenza di questi numeri tale che:
* La sottosequenza è crescente
* Non ci possono essere nella sottosequenza due numeri che sono contigui nella sequenza iniziale dei valori.

### Idee generali per risolvere l'esercizio
Usiamo la tecnica del backtracking (ricorsivo): proviamo tutte le sottosequenza possibili. Per fare ciò, consideriamo per ogni vino la massima sottosequenza che possiamo ottenere
* scegliendo questo vino ```assaggia(i+2,assaggiati+1,a[i])``` (notare come in questo caso ci spostiamo avanti di due posizioni nella sequenza dei vini)
* passando direttamente al prossimo ```assaggia(i+1,assaggiati,ultimo)``` (senza dunque incrementare il numero dei vini assaggiati).

Nel caso in cui il vino che stiamo considerando non possa essere inserito nella sequenza di scelte correnti (ovvero quando ```a[i] < ultimo```), l'unica possibile azione che possiamo effettuare è passare al prossimo vino. Finiti i vini da assaggiare, ritorniamo alla funzione chiamante il numero di vini effettivamente considerati dalla sequenza di scelte che ha portato fino a quel punto; al ritorno dalla ricorsione i-esima viene scelto il valore più alto tra scelgo/non scelgo il vino i.

### Idee alternative
In questo caso, visto il numero ridotto di vini nella sequenza, si può tranquillamente applicare la tecnica del backtracking, che ha costo computazionale _O(2^N)_; tuttavia se la quantità di vini coinvolti fosse maggiore sarebbe conveniente ridurre la complessità con la tecnica di __programmazione dinamica__, o nella forma ricorsiva (_Memoization_) o in quella iterativa: "l'implementazione è lasciata al lettore come esercizio".

* ## Piastrelle
### Breve spiegazione del testo
Abbiamo 2 diverse tipologia di piastrelle da piazzare, rispettivamente di lunghezza 1 e 2. Dobbiamo stampare tutti i possibili modi di piazzare le piastrelle in modo che la somma delle lunghezze sia uguale ad N (acquisito in input).

### Idee generali per risolvere l'esercizio
Semplicemente proviamo tutti i possibili modi di piazzare le piastrelle (backtrack) e stampiamo i modi validi (lunghezza == N).

### Idee alternative
Non ce ne sono.

* ## Interrogazioni
### Breve spiegazione del testo
Abbiamo N quesiti diversi ognuno con difficoltà D<sub>i</sub>, dobbiamo selezionare un sottoinsieme S di K quesiti tale che la differenza d tra max(S) e min(S) sia la minore possibile, dobbiamo poi stampare in output d.

### Idee generali per risolvere l'esercizio
Ordiniamo gli N quesiti per difficoltà crescente, facciamo scorrere una finestra di lunghezza K sul vettore delle difficoltà D. In questo modo abbiamo che l'elemento con indice i avrà difficoltà minima e l'elemento con indice i+K-1 avrà difficoltà massima nel sottoinsieme S di K elementi considerato. A questo punto la risposta è ```min(D[i+K-1] - D[i])``` per i compreso tra 0 ed N-K.


* ## Domino massimale
### Breve spiegazione del testo
Sono date N tessere di domino, contenenti due numeri tra 0 e 6. Due tessere possono essere concatenate se messe a contatto con lo stesso numero (e per essere concatenate possono essere ruotate). Il problema chiede di trovare il maggior numero di tessere concatenabili. 

### Idee generali per risolvere l'esercizio
Dato che abbiamo in input al massimo 10 tessere, l'idea più semplice, cioè provare tutte le combinazioni possibili, funziona. L'idea quindi è quella di provare ad usare una tessera ad un certo punto della catena, proseguire e vedere a che lunghezza si arriva; poi provare a non usarla. Per fare ciò usiamo un vettore booleano per memorizzare se ogni tessera è stata usata o meno. Usiamo una funzione ricorsiva ```solve(int tessera, int len)```, che cerca di aggiungere una tessera ad una catena lunga ```len``` e che termina con valore ```tessera```. Nella funzione ricorsiva scorriamo tra le tessere libere, se ne troviamo una compatibile (da un lato e/o dall'altro) la proviamo ad unire (ci segnamo di averla usata), richiamiamo la funzione solve e dopo la chiamata la torniamo a segnare come libera. Così facendo esaminiamo tutte le possibili scelte. Per trovare la soluzione, tra tutti i valori ```len``` nella funzione ```solve```, memorizziamo il massimo.

Nota: nel main avremo un ciclo for che esamina tutte le possibilità per le tessere di partenza (girate da un lato o dall'altro), prova con una tessera (la segna usata), chiama la funzione solve e poi la libera.

### Idee alternative
Nella soluzione che vi proponiamo le tessere sono memorizzate in un vettore di coppie di interi ```pair<int, int>```, può essere usata anche una matrice Nx2.


* ## Numeri di Figonacci
### Breve spiegazione del testo
I numeri di Figonacci sono costruiti così. L'(n+1)-esimo numero G(n+1), eccetto per G(0) = −1 e G(1) = 0 dati inizialmente, si calcola come:

G(n+1) = (G(n) − G(n-1)) + (G(n) − G(n-2)) + . . . + (G(n) − G(2)) + (G(n) − G(1)) + (G(n) − G(0)). 

Dati in input due interi N ed M, vogliamo calcolare l'N-esimo numero di Figonacci G(N) modulo M.

### Idee generali per risolvere l'esercizio
Semplifichiamo prima di tutto l'espressione per calcolare G(n+1):

G(n+1) = nG(n) − (G(n-1) + G(n-2) + ... + G(0)).

Ci accorgiamo così che è molto comodo avere memorizzata la somma dei primi n-1 numeri di Figonacci per calcolare l'(n+1)-esimo. Usiamo un vettore per memorizzare i numeri di Figonacci che calcoliamo man mano e uno per memorizzare le somme parziali S(n-1) = G(n-1) + G(n-2) + ... + G(0) della sequenza di Figonacci. Partendo da G(0) = −1 e G(1) = 0, con un ciclo for calcoliamo G(2) e S(0), G(3) e S(1), eccetera, usando la formula. Per calcolare G(n+1) servirà S(n-1), memorizzata al passo precedente. Per ogni numero G(n) che calcoliamo, invece che memorizzare l'intero numero, salviamo il resto dato da G(n) diviso per M (lo stesso per le somme S(n)). Lo facciamo perchè nel risultato finale ci interessa solo G(N) modulo M. Salvare ad ogni passo G(n)%M o calcolare solamente alla fine G(N)%M è la stessa cosa, ma ci permette di memorizzare in memoria numeri più piccoli.
