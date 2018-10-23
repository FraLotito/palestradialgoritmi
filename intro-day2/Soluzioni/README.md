# Soluzioni Day2

* ## Cubetti colorati
### Breve spiegazione del testo
Vengono dati in input N cubetti (numerati da 0 a N-1), ciascuno dei quali è di un certo colore (un intero tra 1 e N). Dobbiamo fare in modo, tramite una chiamata alla procedura ```Vernicia(cubetto, nuovo_colore)```, che alla fine dell'esecuzione tutti i cubetti siano di colori diversi. La soluzione deve effettuare il minimo numero di ri-colorazioni possibile.

### Idee generali per risolvere l'esercizio
Scorrendo una volta tutti i cubetti e i rispettivi colori identifichiamo tutti i colori che non sono ancora stati usati (quelli che avranno contatore di utilizzo = 0) inserendoli in una lista, andremo poi ad usarli per verniciare quei cubetti che, ad una successiva passata, risultano usare un colore ripetuto. In questo modo abbiamo la garanzia di non avere alcun colore ripetuto alla fine della procedura e di usare anche il numero minimo di riverniciature, ché andiamo a riverniciare solo quei cubetti che sono di un colore già presente nella sequenza.

### Idee alternative
L'implementazione è abbastanza libera e può fare uso delle più svariate strutture dati, in particolare:
* Per trovare i colori inutilizzati: ```std::bitset``` (dalla STL del C++ - minimizza l'uso della memoria), oppure più semplicemente un ```bool[]``` o un ```int[]``` (che conta anche il numero di occorrenze per quel colore).
* Per trovare il prossimo colore da utilizzare per la verniciatura: ```std::list```, ```std::stack``` (accesso in tempo costante al prossimo colore nella struttura), oppure più semplicemente si può riscorrere dall'inizio il vettore/la struttura dati di cui al punto precedente finché non si trova un valore 0; in ogni caso la complessità computazionale non cambia. 

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
