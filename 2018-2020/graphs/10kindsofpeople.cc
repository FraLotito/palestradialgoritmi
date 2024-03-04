#include<iostream>
using namespace std;

char m[1002][1002]; //mappa
int C[1002][1002]; //colori
int r, c; // righe e colonne

void dfs(int i, int j, char tipo, int col) {
    if(i < 0 || j < 0 || i > r || j > c) return; //fuori dalla mappa
    if(C[i][j] == 0 && m[i][j] == tipo) { 
        // per visitare il vicinato devo avere lo stesso tipo 
        // e non aver mai visitato l'entry i, j
        // se posso visitare allora assegno il mio colore e visito i vicini
        C[i][j] = col;
        dfs(i-1, j, tipo, col);
        dfs(i+1, j, tipo, col);
        dfs(i, j-1, tipo, col);
        dfs(i, j+1, tipo, col);
    }
}

int main() {

    //input mappa
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> m[i][j];
        }
    }

    //devo colorare le componenti connesse della mappa
    // itero su tutte le celle della mappa e se non ho visitato una cella allora la visito
    // con un colore nuovo
    int col = 1;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(C[i][j] == 0) {
                dfs(i, j, m[i][j], col);
                col++;
            }
        }
    }

    int n;
    cin >> n;
    // ogni query adesso può essere risposta in tempo costante
    // da una cella i,j a una cella x,y posso arrivarci solo se appartengono alla stessa cc (stesso colore)
    // poi vedo il tipo della mappa per capire se è decimal o binary
    for(int i = 0; i < n; i++) {
        int r_1, c_1, r_2, c_2;
        cin >> r_1 >> c_1 >> r_2 >> c_2;
        if(C[r_1-1][c_1-1] != C[r_2-1][c_2-1]) cout << "neither" << endl;
        else {
            if(m[r_1-1][c_1-1] == '0') cout << "binary" << endl;
            else cout << "decimal" << endl;
        }
    }

    return 0;
}