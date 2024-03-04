# Corso base di C++

## Creare un file C++
Il programma che usiamo si chiama **CodeBlocks**. Se volete scaricarlo sul vostro computer ecco il link: http://www.codeblocks.org/downloads/26, scaricate la versione codeblocks-17.12mingw-setup.exe.

Per creare un nuovo file selezionate dal menù "File" la voce "New" e quindi "Empty file". Quando lo salvate ricordate di scrivere "nomefile.cpp", perchè stiamo programmando in C++, se fosse salvato come "nomefile.c", dovremmo usare C come linguaggio. 

**Nota:** C++ è un estensione del linguaggio C.

## Hello world (stampa a video)

```cpp
#include<iostream>
using namespace std;

int main() {
    cout << "Ciao mondo!";
    return 0;
}
```
Per stampare un messaggio a video si usa l'istruzione cout, *cout << "Messaggio"*; oppure *cout << nomediunavariabile;*

**NB:** Tutto il codice va scritto dentro al main e prima del return (per ora, poi vedremo cosa può essere scritto fuori).

## Le variabili

**Esempio:**
```cpp
#include<iostream>
using namespace std;

int main() {
    int a = 5;
    double b = 3.5;
    float c = 7.2;
    char d = 'a';
    
    cout << a << " " << b << " " << c << " " << d;

    return 0;
}
```
Ci sono quattro tipi principali di variabili: int (numeri interi), double e float (numeri decimali), char (caratteri). I caratteri vengono sempre rappresentati tra apici, come nell'esempio: 'a'.

Per quanto riguarda la stampa a video, ricordo che (ad esempio) con *cout << a;* viene stampato il valore che ha la variabile a in questo punto preciso del programma.

## Input e output

**Esempio:**
```cpp
#include<iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Inserire a: ";
    cin >> a;
    cout << "\nInserire b: ";
    cin >> b;
    
    return 0;
}
```
L'istruzione *cin >> a* legge il numero inserito da tastiera e lo salva nella variabile a.

## Operazioni con le variabili

**Esempio:**
```cpp
#include<iostream>
using namespace std;

int main() {
    int a = 3, b = 2;
    int somma = a+b;
    int differenza = a-b;
    int prodotto = a*b;
    int rapporto = a/b;
    int resto = a%b;

    cout << somma << " " << differenza << " " << prodotto << " " << rapporto << " " << resto;
    
    return 0;
}
```
**Esercizio**: scrivere un programma che, inseriti due numeri da tastiera, calcoli e stampi somma, differenza, prodotto, quoziente e resto della divisione del primo per il secondo. Potete calcolare anche la radice: basta aggiungere la libreria *math.h* (quindi all'inizio mettere *#include<math.h>*) e usare l'operazione *sqrt()*.

## Le istruzioni if e else

**Esempio:**
```cpp
#include<iostream>
using namespace std;

int main() {
    int a = 3, b = 2;
    if(a>b){
        cout << "a e' maggiore di b";
    }else{
        cout << "a e' minore (o uguale) di b";
    }
    
    return 0;
}
```
In generale l'istruzione if controlla la *condizione*, se è vera esegue le *istruzioni 1*, altrimenti esegue le *istruzioni 2*: 

```cpp
if(condizione){
    istruzioni1;
}else{
    istruzioni2;
}
```

**Esercizio**: scrivere un programma che, inserito un numero da tastiera, stampi se è pari o dispari.

## Lo switch
```cpp
switch(espressione intera) { 
case (valore costante 1): 
    istruzioni1;
    break; 
case (valore costante 2):
    istruzioni2;
    break;  
...
default:    // è opzionale 
    istruzioni default;
 } 
```
Lo switch si usa per eseguire istruzioni diverse a seconda del valore di una precisa espressione. Per lo stesso scopo potrebbero essere utilizzati svariati if con molte condizioni, ma in queste situazioni l'uso dello switch semplifica di molto il codice. Lo switch valuta il valore dell'espressione passata come parametro e se il valore corrisponde ad uno di quelli specificati nei *case* viene eseguito il blocco di istruzioni corrispondente. Se il blocco individuato termina con un'istruzione break allora il programma esce dallo switch, altrimenti, vengono eseguiti anche i blocchi successivi finchè non viene trovato un *break* o non si raggiunge l'ultimo blocco dello switch. Se nessun blocco corrisponde al parametro passsato allora viene eseguito il blocco default, se presente. 

**Esercizio (la calcolatrice)**: scrivere un programma che dati due interi A e B ed un'operazione (quindi un simbolo tra +, -, * ,/) stampi a video il risultato dell'operazione (A+B oppure A-B eccetera).

## Input e output su file
Se il nostro programma, invece che leggere da tastiera e stampare a video, dovesse scrivere e leggere da file (solitamente file di estensione .txt), deve usare nuovi oggetti al posto di *cin* e *cout*. Ci serve la libreria *fstream*, che contiene tutto il necessario per lavorare con oggetti di tipo *filestream*. Useremo *ifstream* per leggere dati da file e *ofstream* per scrivere. 

Prima di tutto dobbiamo creare un file di input (ad esempio "input.txt") nella stessa cartella in cui è salvato il programma. In questo file scriviamo i dati da leggere. 

Ora nel nostro programma possiamo aprire il file da cui leggere e il file su cui scrivere (se non esiste viene creato automaticamente).
Con il comando ***ifstream in ("input.txt");*** andiamo ad aprire "input.txt", da cui possiamo leggere con il comando *in* (che funziona allo stesso modo del *cin*). Con ***ofstream out ("output.txt");*** viene creato o aperto (se già esistente) un file "output.txt" su cui possiamo scrivere con il comando *out* (analogo al *cout*).

```cpp
#include<fstream>
using namespace std;

int main(){
	ifstream in ("input.txt");
	ofstream out ("output.txt");

	int a;
	in >> a; //inserisco quello che leggo nella variabile a

	out << "Ciao! La variabile a vale " << a;
	
	in.close();
	out.close();
    
	return 0;
}

```

## Il ciclo while
```cpp
while(condizione) { 
    istruzioni;
} 
```
Il while serve per eseguire ripetutamente un insieme di istruzioni, finchè una certa condizione è vera. La condizione rappresenta un controllo booleano (vero/falso) che viene effettuato ad ogni iterazione (cioè ad ogni "giro", "ciclo"). All'inizio di ogni iterazione viene fatto un controllo: se la condizione è falsa il while termina, se è vera vengono eseguite le istruzioni e poi viene controllata nuovamente la condizione, e così via...

**Esempio:**

```cpp
#include<iostream>
using namespace std;

int main(){
	int a = 10;
	while(a>0){
		cout << " a = " << a << endl;
		a--;
	}
    
	return 0;
}

```


**Esercizio**: scrivere un programma che faccia continuare ad inserire un numero da tastiera fino a che questo non è pari.

## Il ciclo for
```cpp
int i;
for(i = valore iniziale; condizione; incremento della variabile i) { 
  istruzioni; 
} 
```
I cicli for seguono un meccanismo simile al while, vengono solitamente usati quando si conosce il numero di iterazioni da fare (mentre il while solitamente quando questo numero non è conosciuto).

Il for fa uso di una variabile, in questo caso la variabile i, come contatore del numero di iterazioni. Come prima cosa, a questa variabile viene dato un valore iniziale. Finchè il valore di i rispetta la condizione, vengono eseguite le istruzioni contenute tra la parentesi graffe. Eseguito il blocco di istruzioni, la variabile i, viene incrementata secondo l'incremento e, se la condizione è soddisfatta, il ciclo viene ripetuto. 

**Esempio:**

```cpp
#include<iostream>
using namespace std;

int main(){
	int i;
	for(i = 0; i<10; i++){
		cout << " i = " << i << endl;
	}
    
	return 0;
}

```
