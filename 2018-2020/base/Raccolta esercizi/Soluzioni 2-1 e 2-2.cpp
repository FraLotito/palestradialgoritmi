/*
Soluzioni degli esercizi seguenti:
2.1) Scrivere un programma che, inseriti N = 5 numeri interi, calcola quanti numeri pari sono stati inseriti.
2.2) Scrivere un programma che, inseriti N = 5 numeri interi, stampa a video il maggiore ed il minore.

Vi scrivo la versione con N inserito da tastiera (quindi non fissato a 5 necessariamente).
*/

#include <fstream>
#include <iostream>
using namespace std;

int main(){

    int N;
    cout << "Inserire N, numero di interi considerati: ";
    cin >> N;

    int num; // numero che vado a leggere man mano
    int numeripari = 0; // variabile che conta quanti pari sono stati inseriti
    int maggiore = -100000000; // variabile in cui salverò il maggiore
    int minore = 100000000; // variabile in cui salverò il minore

    int i;
    for(i = 1; i<=N; i++){
        cout << "\nInserire numero " << i << ": ";
        cin >> num;

        if(num%2 == 0){ // ho inserito un numero pari
            numeripari++;
        }

        if(num > maggiore){ // controllo se ho inserito un numero maggiore dei precedenti
            maggiore = num;
        }

        if(num < minore){ // controllo se ho inserito un numero minore dei precedenti
            minore = num;
        }
    }

    cout << "\n\nHai inserito " << numeripari << " numeri pari!";
    cout << "\n\nDei numeri inseriti " << maggiore << " e' il maggiore e " << minore << " e' il minore.";

    return 0;
}
