// includi tutte le librerie presenti
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20005;
int N, M;
vector<int> g[MAXN];
// vettori globali hanno tutti i valori inizializzati a zero
int visited[MAXN];

void dfs(int s, int count)
{
  if (visited[s] != 0)
    return;
  visited[s] = count;
  for (auto u : g[s])
    dfs(u, count);
}

void stampa_grafo()
{
  for (int i = 0; i < N; i++)
  {
    cout << i << ": ";
    for (auto u : g[i])
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
  freopen("output.txt", "w", stdout); // w = write, scrittura

  cin >> N >> M;
  int a, b;
  for (int i = 0; i < M; i++)
  {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  int count = 0;
  for (int i=0; i < N; i++) {
    if (visited[i] != 0) continue;
    count++;
    dfs(i, count);
  }

  cout << count - 1;

  // cout << '\n'
  //      << '\n';
  // stampa_grafo();
}