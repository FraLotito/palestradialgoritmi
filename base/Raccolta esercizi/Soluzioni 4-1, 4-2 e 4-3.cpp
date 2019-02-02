/*
Soluzioni degli esercizi seguenti:
Usando i vettori, modificare i precedenti programmi facendo inserire il numero N di interi considerati da tastiera.
Assunzione: assumiamo che il numero N sia al massimo 1000.
4.1) Scrivere un programma che legga un intero N ed N numeri interi, li sommi e stampi a video la somma.
4.2) Scrivere un programma che legga un intero N ed N numeri interi, poi calcoli quanti numeri pari sono stati inseriti.
4.3) Scrivere un programma che legga un intero N ed N numeri interi, poi stampi a video il maggiore ed il minore.
*/

#include <fstream>
#include <iostream>
using namespace std;

int main(){

    int v[1000];
    int N;

    cout << "Inserire N, numero di interi considerati (massimo 1000): ";
    cin >> N;

    cout << "\nInserire N interi: ";

    for(int i = 0; i<N; i++){
        cin >> v[i];
    }

    int numeripari = 0; // variabile che conta quanti pari sono stati inseriti
    int maggiore = -100000000; // variabile in cui salverò il maggiore
    int minore = 100000000; // variabile in cui salverò il minore
    int somma = 0; // variabile in cui salvo la somma

    for(int i = 0; i<N; i++){
        if(v[i]%2 == 0){ // ho inserito un numero pari
            numeripari++;
        }

        if(v[i] > maggiore){ // controllo se ho inserito un numero maggiore dei precedenti
            maggiore = v[i];
        }

        if(v[i] < minore){ // controllo se ho inserito un numero minore dei precedenti
            minore = v[i];
        }

        somma = somma + v[i];
    }

    cout << "\n\nHai inserito " << numeripari << " numeri pari.";
    cout << "\n\nDei numeri inseriti " << maggiore << " e' il maggiore e " << minore << " e' il minore.";
    cout << "\n\nLa loro somma e' " << somma << ".";
    return 0;
}
