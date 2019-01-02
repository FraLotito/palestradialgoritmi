#include <fstream>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int N, M; // N numero di nodi, M numero di archi
int C, K; // C cabina del tesoro, K numero di cabine con sacche

const int MAXN = 31;
vector<int> nodi[MAXN];
int distanza[MAXN][MAXN];
bool aria[MAXN];

struct nodo {
    int numero;
    int distanza;
    int metriapnea;

    bool operator < (const nodo& o) const {
        return distanza > o.distanza;
    }
};

int bfs (){ // visita partendo dal nodo 1

    int distda1[MAXN]; // vettore delle distanze per arrivare ai nodi partendo da 1
    bool visited[MAXN];
    priority_queue<nodo> myqueue;

    for(int i = 1; i<=N; i++){
        distda1[i] = -1;
        visited[i] = false;
    }

    myqueue.push({1,0,0});

    int x, d, m;

    while(!myqueue.empty()){

        int next = (myqueue.top()).numero;
        d = (myqueue.top()).distanza;
        m = (myqueue.top()).metriapnea;
        myqueue.pop();

        if(!visited[next]){

        visited[next] = true;
        distda1[next] = d;

        for(int j = 0; j<(nodi[next]).size(); j++) {
            x = nodi[next][j];
            if(m+distanza[next][x]<21){ // se posso arrivarci in apnea
                if(aria[x] == true)
                    myqueue.push({x,d+distanza[next][x],0});
                if(aria[x] == false)
                    myqueue.push({x,d+distanza[next][x],m+distanza[next][x]});

            }
        }
        }
    }

    return distda1[C];
}

int main(){

    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> N >> M >> C >> K;

    for(int i = 1; i<=N; i++)
        aria[i] = false;

    int a;
    for(int i = 0; i<K; i++){
        in >> a;
        aria[a] = true;
    }

    int x, y, m;
    for(int i = 0; i<M; i++){
        in >> x >> y >> m;
        if(m < 21){
            // altrimenti non ha senso salvare l'arco
            nodi[x].push_back(y);
            nodi[y].push_back(x);
            distanza[x][y] = m; // metri tra x e y
            distanza[y][x] = m;
        }
    }

    a = bfs();

    cout << a << endl;
    out << a << endl;

    return 0;
}
