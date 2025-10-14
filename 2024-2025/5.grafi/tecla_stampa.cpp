// includi tutte le librerie presenti
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 35;
int N, M;
vector<int> g[MAXN];

struct queue_elem
{
  int node;
  int dist;
  int prec;
};

void stampa_soluzione(vector<queue_elem> q, int i)
{
  while (true)
  {
    if (i < 0)
      return;
    // nodo che fa parte della soluzione
    queue_elem curr = q[i];

    // qua sto effettivamente stampando la soluzione al contrario, rispetto a come la ho trovata: questo perche' sono comunque in un ciclo che parte e finisce da zero, con i vertici bidirezionali. se non fosse cosi', dovrei salvarmeli prima in un vector separato e poi stamparli all'indietro nell'ordine corretto in cui li ho trovati
    cout << curr.node << " ";
    i--;
    // torno indietro in q finche' non trovo un nodo da cui son passato con la soluzione
    while (true)
    {
      if (i < 0)
        return;
      queue_elem old = q[i];
      // nodo da cui sono arrivato trovato
      if (old.node == curr.prec && old.dist == curr.dist - 1)
        break;
      i--;
    }
  }
}

void bfs_modificata()
{
  // siccome devo salvarmi tutti i nodi in cui sono stato, per tornare indietro dopo e capire che strada ho fatto, mi salvo tutto in un vector e anziche' fare pop, avanzo di indice i

  // {nodo, distanza da nodo 0, nodo da cui vengo}
  vector<queue_elem> q;
  q.push_back({0, 0, 0});
  int i = 0;

  while (true)
  {
    queue_elem curr = q[i];
    // cout << "nodo: " << curr.node << ", distanza: " << curr.dist << ", prec:" << curr.prec << '\n';
    i++;

    // guardo se il nodo a cui sono attualmente e' zero, stando attento che non sia il primo in cui capito
    if (curr.node == 0 && curr.dist != 0)
    {
      // se siamo al nodo zero in un numero pari di passi, abbiamo fatto una strada inutile
      if (curr.dist % 2 == 0)
        continue;

      // se la strada e' dispari, abbiamo trovato la strada piu' corta
      cout << curr.dist << '\n';
      // i-1 perche' sopra lo abbiamo incrementato dopo aver salvato il curr
      stampa_soluzione(q, i - 1);
      break;
    }

    for (int u : g[curr.node])
    {
      q.push_back({u, curr.dist + 1, curr.node});
    }
  }
}

void stampa_grafo()
{
  for (int i = 0; i < N; i++)
  {
    cout << i << ": ";
    for (int u : g[i])
    {
      cout << u << ' ';
    }
    cout << '\n';
  }
}

int main()
{
  // per rendere il prendere l'input piu' efficente
  ios::sync_with_stdio(0);
  cin.tie(0);
  // devia il flusso input / output nei file indicati
  freopen("input.txt", "r", stdin); // r = read, lettura
  // freopen("output.txt", "w", stdout); // w = write, scrittura

  cin >> N >> M;
  int a, b;
  for (int i = 0; i < M; i++)
  {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  bfs_modificata();

  // cout << '\n'
  //      << '\n';
  // stampa_grafo();
}