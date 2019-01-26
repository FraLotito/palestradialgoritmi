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
**Esercizio**: scrivere un programma che dati due interi A e B ed un'operazione (quindi un simbolo tra +, -, * ,/) stampi a video il risultato dell'operazione (A+B oppure A-B eccetera).

## Il while
```cpp
while(condizione) { 
    istruzioni;
} 
```

**Esercizio**: scrivere un programma che faccia continuare ad inserire un numero da tastiera fino a che questo non è pari.

## Input e output su file
Se il nostro programma, invece che leggere da tastiera e stampare a video, dovesse scrivere e leggere da file (solitamente file di estensione .txt), deve usare nuovi oggetti al posto di *cin* e *cout*. Ci serve la libreria *fstream*, che contiene tutto il necessario per lavorare con oggetti di tipo *filestream*. Noi useremo *ifstream* per leggere dati da file e *ofstream* per scrivere. Prima di tutto dobbiamo creare un file di input ("nomefileinput.txt") nella stessa cartella in cui è salvato il programma. In questo file scriverete voi qui quali saranno i dati da leggere. 

Nel nostro programma possiamo aprire il file da cui leggere e un file su cui scrivere (che viene creato automaticamente), come è riportato nel programma qui sotto. Possiamo leggere da "nomefileinput.txt" e possiamo scrivere in "nomefileoutput.txt", con i comandi *in* e *out*.

```cpp
#include<fstream>
using namespace std;

int main(){
	ifstream in ("nomefileinput.txt");
	ofstream out ("nomefileoutput.txt");

	int a;
	in >> a; //inserisco quello che leggo nella variabile a

	out << "Ciao! La variabile a vale " << a;

	return 0;
}

```

