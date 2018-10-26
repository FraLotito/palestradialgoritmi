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




