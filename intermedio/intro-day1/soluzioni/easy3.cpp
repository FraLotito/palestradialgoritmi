#include <fstream>
#include <iostream>
using namespace std;

int minimo = -1000001;

int main(){

    ifstream in("input.txt");
    ofstream out("output.txt");

	int N;
	in >> N;

	int n; // in n salvo il numero che leggo ad ogni passo dal file di input
    int maxSum; // in maxSum mi salvo la somma pari massima

    int p1 = minimo, p2 = minimo; // in p1 salvo il pari maggiore di tutti, in p2 il più grande dopo p1
    int d1 = minimo, d2 = minimo; // in d1 salvo il dispari maggiore, in d2 il più grande dopo d1

	for(int i=0; i<N; i++){
		in >> n;
		if(n%2 == 0){
            if(n >= p1){ // avrò p2<=p1<=n
                p2 = p1;
                p1 = n;
            }
            else if(n > p2){ // avrò p2<n<p1
                p2 = n;
            }
		}
        else{ // n dispari
            if(n >= d1){ // avrò d2<=d1<=n
                d2 = d1;
                d1 = n;
            }
            else if(n > d2){ // avrò d2<n<d1
                d2 = n;
            }
        }
	}

	if(p2+p1 > d1+d2) maxSum = p2+p1;
	    else maxSum = d1+d2;

    /* La somma non esiste se non ho trovato nè una coppia di numeri pari, nè una coppia di numeri dispari.
    Quindi p2 e d2 saranno ancora uguali al valore "minimo = -1000001", allora maxSum (=p1+p2 oppure =d1+d2)
    sarà minore di zero. */

	if(maxSum < 0)
        maxSum = -1;

	out << maxSum;

    return 0;
}
