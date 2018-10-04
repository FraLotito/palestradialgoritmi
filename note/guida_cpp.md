# C++ per le Olimpiadi

## Template standard

#### I/O su file

Questo è il template che userete più spesso

```cpp
#include<fstream>
using namespace std;

int main() {
    ifstream in("input.txt"); //specifico qual è il mio file di input
    ofstream out("output.txt"); //specifico qual è il mio file di output
  
    // lettura variabile
    int a;
    in>>a;
  
    // qui la soluzione
   
    // output variabile
    out<<a;
    
    in.close(); //chiudo file di input
    out.close(); //chiudo file di output
    return 0;
}
```

#### Implementare una funzione data 

In alcune gare invece vi evitano la lettura / scrittura di dati e vi danno direttamente una funzione (con tutti i parametri necessari) da implementare. Vedremo questo caso più avanti.

## STL (Algoritmi e strutture dati già implementate)

#### Vector
Implementazione di array dinamici:
```cpp
#include<vector> //bisogna importarli

vector<int> v; //dichiarazione di un vettore di interi v

//inserisco in v il valore a
int a = 2;
v.push_back(2);

//size restituisce la dimensione del vettore, in questo caso 1 perché c'è un solo elemento
int c = v.size();

//è un array dinamico quindi posso aggiungere quanti elementi voglio (più o meno)
v.push_back(1);
v.push_back(3);
v.push_back(4);

//vale la stessa modalità di accesso degli array statici, v[0] è uguale a 2
int z = v[0];

//Se dovete dichiarare un vettore con dimensione presa in input NON FATE qualcosa del genere altrimenti vi picchio
int N;
in>>N;
int v[N];

//potete però fare
int N;
in>>N;
vector<int> v(N);

//oppure
int N;
vector<int> v;

in>>N;
v.resize(N);

```

#### Sort
Implementazione di un algoritmo di ordinamento (efficiente):
```cpp
#include<algorithms>

vector<int> v; //supponete sia riempito dai valori [1,6,5,9,10,-1,4]

sort(v.begin(), v.end()); //ordina in-place il vettore

```
Dopo l'esecuzione, v conterrà [-1,1,4,5,6,9,10]



## Cose utili

#### Operatore % (modulo)
L'operatore % mi restituisce il resto di una divisione:
```cpp
int a = 5;
int b = 2;
int c = a % b;
```
A fine esecuzione c varrà 1.

#### Funzioni max / min
Le funzioni max e min restituiscono rispettivamente il massimo e il minimo di due numeri:
```cpp
int a = 5;
int b = 2;
int c = max(a,b);
int d = min(a,b);
```
A fine esecuzione c varrà 5 e d varrà 2.

#### Funzione abs
Le funzione abs restituisce il valore assoluto di un numero:
```cpp
int a = -5;
int b = 5;
int c = abs(a); 
int d = abs(b); 
```
A fine esecuzione c varrà 5 e d varrà 5.








