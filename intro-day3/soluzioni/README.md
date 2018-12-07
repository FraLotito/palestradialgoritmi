# Soluzioni Day3

* ## Dijkstra e MST
### Breve spiegazione del testo
Questi due problemi sono abbastanza dei classici in teoria dei grafi: cammini minimi e albero di copertura minimo in un grafo, entrambi gli esercizi richiedono di implementare gli algoritmi.

### Idee generali per risolvere l'esercizio
Trovate delle referenze all'interno del codice delle soluzioni, sono problemi che vanno imparati e capitano abbastanza di frequente alle olimpiadi.

* ## Ponti

### Breve spiegazione del testo
E' dato in input un grafo non orientato e possibilmente non connesso. Bisogna trovare il minimo numero di archi da aggiungere per far diventare il grafo connesso.

### Idee generali per risolvere l'esercizio
Ricavare il numero di componenti connesse: scorro ogni nodo, se non l'ho visitato faccio partire una dfs e visiterò tutti i nodi della sua componente connessa, se l'ho già visitato lo ignoro.
Una volta ricavato il numero di componenti connesse, è solo questione di matematica da scuola elementare :)
