# Corso base di C++

## Creare un file C++
Il programma che usiamo si chiama: CodeBlocks (se volete scaricarlo sul vostro computer ecco il link http://www.codeblocks.org/downloads/26, scaricate la versione: codeblocks-17.12mingw-setup.exe).
Per creare un nuovo file: selezionare dal menù "File" la voce "New" e quindi "Empty file". Quando lo salvate ricordate di scrivere "nomefile.cpp", perchè stiamo programmando in C++, se venisse salvato come "nomefile.c" dovremmo usare C come linguaggio. 

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
## Lettura da tastiera
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
**Esercizio**: scrivere un programma che, inseriti due numeri da tastiera, calcoli e stampi somma, differenza, prodotto, quoziente e resto della divisione del primo per il secondo.

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
**Esercizio**: scrivere un programma che, inserito un numero da tastiera, stampi se è pari o dispari.
