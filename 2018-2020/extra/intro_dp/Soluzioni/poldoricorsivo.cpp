#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

const int MAXN = 10000;
int N, peso[MAXN];

int solve(int n, int pesomax){ // n = posizione in cui mi trovo, pesomax = peso massimo che posso mangiare

    if(n==N) return 0;

    if(peso[n]<pesomax){ // posso scegliere se mangiare o no l'n-esimo panino
        return max(solve(n+1,peso[n])+1, solve(n+1,pesomax));
    }
    else{ // non posso mangiare l'n-esimo panino
        return solve(n+1,pesomax);
    }

}

int main() {

	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> N;

	for (int i=0; i<N; i++){
		in >> peso[i];
	}

    int s = solve(0, MAXN); // MAXN è anche il massimo peso che posso trovare

    out << s;

	return 0;
}

