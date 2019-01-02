using namespace std;

#include <bitset>
#include <queue>

void Vernicia(int indice, int colore);

void Diversifica(int N, int colore[]) {
    bitset<1000001> taken;
    queue<int> q;

    for(int i=0; i<N; i++) {
        taken[colore[i]] = 1;
    }

    for (int i=1; i<=N; i++) {
        if (!taken[i]) {
            q.push(i);
        }
    }
    taken.reset();
    for (int i=0; i<N; i++) {
        if (!taken[colore[i]]) {
            taken[colore[i]] = 1;
        } else {
            Vernicia(i,q.front());
            q.pop();
        }
    }
}
