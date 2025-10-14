// includi tutte le librerie presenti
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;
int N;
bool m[MAXN][MAXN];
vector<int> g[MAXN * MAXN];

bool visitato[MAXN * MAXN];
int distanza[MAXN * MAXN];

void bfs(int start)
{
  queue<int> q;
  for (int i = 0; i < N * N; i++)
  {
    visitato[i] = false;
    distanza[i] = INT_MAX;
  }

  visitato[start] = true;
  distanza[start] = 0;
  q.push(start);

  while (!q.empty())
  {
    int x = q.front();
    q.pop();

    for (auto u : g[x])
    {
      if (visitato[u])
        continue;

      visitato[u] = true;
      distanza[u] = distanza[x] + 1;
      q.push(u);
    }
  }
}

// converti due cordinate in m in un indice di g
int id(int i, int j)
{
  return i * N + j;
}

void aggiungi_vicino(int i, int j, int k, int h)
{
  if (k > N - 1 || k < 0)
    return;
  if (h > N - 1 || h < 0)
    return;

  if (m[k][h])
  {
    g[id(i, j)].push_back(id(k, h));
    g[id(k, h)].push_back(id(i, j));
  }
}

void stampa_grafo()
{
  for (int i = 0; i < N * N; i++)
  {
    cout << i << ": ";
    for (auto u : g[i])
    {
      cout << u << ' ';
    }
    cout << '\n';
  }
}

void stampa_distanze()
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (m[i][j])
      {
        if (distanza[id(i, j)] == INT_MAX)
          cout << "* ";
        else
          cout << distanza[id(i, j)] << ' ';
      }
      else
        cout << "x ";
    }
    cout << '\n';
  }
}

void costruisci_grafo()
{

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      // ignoriamo le caselle non sicure
      if (!m[i][j])
        continue;

      // vicino a destra
      aggiungi_vicino(i, j, i + 1, j);

      // vicino in basso a destra
      aggiungi_vicino(i, j, i + 1, j + 1);

      // vicino in basso
      aggiungi_vicino(i, j, i, j + 1);

      // vicino in basso a sinistra
      aggiungi_vicino(i, j, i + 1, j - 1);
    }
  }
}

int main()
{
  // per rendere il prendere l'input piu' efficente
  ios::sync_with_stdio(0);
  cin.tie(0);
  // devia il flusso input / output nei file indicati
  freopen("input.txt", "r", stdin);   // r = read, lettura
  freopen("output.txt", "w", stdout); // w = write, scrittura

  cin >> N;
  char temp;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> temp;
      m[i][j] = temp == '*';
    }
  }

  costruisci_grafo();
  bfs(0);

  cout << distanza[id(N - 1, N - 1)] + 1;

  cout << '\n'
       << '\n';
  stampa_grafo();
  cout << '\n';
  stampa_distanze();
}