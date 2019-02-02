/*
Soluzioni degli esercizi seguenti:
3.2) Scrivere un programma che dica se un numero inserito da tastiera è primo.
3.3) Scrivere un programma che, inserito un numero da tastiera, dica quanti divisori ha.
*/

#include <fstream>
#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Inserire un numero (maggiore di 1): ";
    cin >> n;

    int div = 2; // proviamo a controllare se è divisibile per tutti i numeri da 2 a n
    int numerodiv = 2; // qui salviamo il numero di divisori (partiamo da 2, perchè sicuramente n è divisibile per 1 e se stesso)

    while(div<n){
        if(n%div == 0){ // ho trovato un divisore
            numerodiv++;
        }
        div++;
    }

    if(numerodiv == 2){
        cout << "\nIl numero inserito e' primo!";
    }else{
        cout << "\nIl numero inserito non e' primo ed ha " << numerodiv << " divisori!";
    }

    return 0;
}
