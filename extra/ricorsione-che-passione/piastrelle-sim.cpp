using namespace std;

#include <iostream>
#include <windows.h>
int choices[25];
int N;

void color(int col);
void indenta(int c);
void stampaconf(int c);
void stampacontrol(int c);

void piastrella(int n, int c) {
    if (n < 0) {
        indenta(c);
        cout << "Configurazione non valida, la lunghezza delle piastrelle eccede N: ";
        stampaconf(c);
        stampacontrol(c);
    } else if (n == 0) {
        indenta(c);
        cout << "La configurazione corrente e' valida: ";
        stampaconf(c);
        stampacontrol(c);
    } else if (n > 0) {
        choices[c] = 1;
        indenta(c);
        cout << "Configurazione corrente: ";
        if (c > 0) stampaconf(c);
        else cout << "Ancora nessuna piastrella inserita" << endl;
        indenta(c);
        cout << "Slot liberi: " << n << endl;
        indenta(c);
        cout << "Premi invio per inserire una piastrella [O]";
        cin.get();
        cout << endl;
        piastrella(n-1,c+1);
        if (n > 1) {   
            stampacontrol(c+1);
        }
        choices[c] = 2;
        indenta(c);
        cout << "Configurazione corrente: ";
        if (c > 0) stampaconf(c);
        else cout << "Ancora nessuna piastrella inserita" << endl;
        indenta(c);
        cout << "Slot liberi: " << n << endl;
        indenta(c);
        cout << "Premi invio per inserire una piastrella [OOOO]";
        cin.get();
        cout << endl;
        piastrella(n-2,c+1);
        if (n > 2) {
            stampacontrol(c+1);
        }
    }
}

int main () {
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "                                  BENVENUTO                                      " << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Inserisci la lunghezza del corridoio: ";
    cin >> N;
    cin.get();
    cout << endl;
    cout << "Premi invio per inziare la simulazione";
    cin.get();
    cout << endl;
    cout << "---------------------------------------------------------------------------------" << endl << endl;
    piastrella(N,0);
    cout << "Hai esplorato tutto l'albero delle scelte.\n"
            << "Premi invio per terminare" << endl;
    cin.get();
    cout << "---------------------------------------------------------------------------------" << endl;
    cout << "                            FINE SIMULAZIONE                                    " << endl;
    cout << "---------------------------------------------------------------------------------" << endl;
    
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void indenta(int c) {
    for (int i=0; i<c; i++) {
        cout << "\t";
    }
}

void stampaconf(int c) {
    for (int i=0; i < c; i++) {
        if (choices[i] == 1) {
            cout << "[O]";
        } else {
            cout << "[OOOO]";
        }
    }
    cout << endl;
}

void stampacontrol(int c) {
    indenta(c);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<< (Premi invio per ritornare il controllo)";
    cin.get();
    cout << endl;
}
