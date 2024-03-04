# Soluzioni 

## Poldo

La prima soluzione di Poldo che viene in mente, e che dovrebbe raggiungere i 35 punti quando il correttore è di buon umore, può essere scritta con una funzione ricorsiva. 

Vogliamo esaminare i panini dal primo all'ultimo, valutando ad ogni passo se mangiare o no un panino, per poi passare al successivo. La nostra funzione ricorsiva *sol* esaminerà quindi un panino in posizione n e deciderà qual è il numero massimo di panini che Poldo può mangiare dall'n-esimo panino in poi. 

Per ogni panino possono essere fatte due scelte: mangiarlo o non mangiarlo, per poi passare al panino successivo. Ogni volta che un panino viene mangiato avremo un nuovo limite sul peso dei panini da mangiare successivamente, che dovranno aver peso strettamente minore. Quindi saranno due i parametri della ricorsione: la posizione del panino che stiamo esaminando e il massimo peso che possiamo permetterci di mangiare.

Supponiamo di star guardando il panino nella posizione n e che per le scelte fatte fino ad ora il peso massimo che possiamo mangiare sia maxpeso. Allora il massimo numero di panini che possiamo mangiare dall'n-esimo in poi (cioè  *sol*(n,maxpeso)) sarà:

1) il massimo tra *sol*(n+1,peso[n])+1 (caso in cui mangio il panino) e *sol*(n+1,maxpeso) (caso in cui non lo mangio), se peso[n]<maxpeso;
2) *sol*(n+1,maxpeso), se peso[n]>=maxpeso (cioè se non posso mangiare questo panino).

La soluzione finale al nostro problema sarà *sol*(0,infinito), dove 0 è la posizione del primo panino e infinito un peso moooolto alto che evita di avere limiti iniziali quando Poldo comincia a mangiare i panini.
