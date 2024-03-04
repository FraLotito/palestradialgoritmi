/*
Soluzione di:
3.4) Scrivere un programma che, inserito un numero N da tastiera, stampi la somma di tutti i numeri da 1 ad N (senza usare formule già conosciute!).
*/

#include <fstream>
#include <iostream>
using namespace std;

int main(){

    int N;
    cout << "Inserire un numero (maggiore di 0): ";
    cin >> N;

    int somma = 0; // qui salvo la somma, aggiungendo man mano 1, 2, 3 ecc ... fino ad N

    for(int i = 1; i<=N; i++){
        somma = somma+i;
    }

    cout << "La somma dei numeri da 1 a " << N << " e' " << somma;

    return 0;
}
