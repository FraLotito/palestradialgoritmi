#include <iostream>
#include <algorithm>
#include <math.h>

#include <chrono>
typedef std::chrono::high_resolution_clock::time_point tempo;
#define prendi_tempo() std::chrono::high_resolution_clock::now()
#define differenza_tempo(start, end) std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() * 1e-3

#define MAXN 10000000
#define FOR(i, n) for (int i = 0; i < n; i++)

using namespace std;

int N;
int D[MAXN];

void crea_numeri_casuali()
{
  FOR(i, N)
  {
    D[i] = rand() % INT_MAX;
  }
}

bool controlla_ordinamento()
{
  FOR(i, N - 1)
  {
    if (D[i] > D[i + 1])
    {
      return false;
    }
  }
  return true;
}

void merge(int arr[], int i, int m, int f)
{
  int n1 = m - i + 1;
  int n2 = f - m;

  int L[n1], R[n2];

  FOR(x, n1)
  L[x] = arr[i + x];
  FOR(y, n2)
  R[y] = arr[m + 1 + y];

  int x = 0, y = 0, z = i;

  while (x < n1 && y < n2)
  {
    if (L[x] <= R[y])
    {
      arr[z] = L[x];
      x++;
    }
    else
    {
      arr[z] = R[y];
      y++;
    }
    z++;
  }

  while (x < n1)
  {
    arr[z] = L[x];
    x++;
    z++;
  }

  while (y < n2)
  {
    arr[z] = R[y];
    y++;
    z++;
  }
}

void mergeSort(int arr[], int i, int f)
{
  if (i < f)
  {
    int m = i + (f - i) / 2;

    mergeSort(arr, i, m);
    mergeSort(arr, m + 1, f);

    merge(arr, i, m, f);
  }
}

void ordina()
{
  // implementa qui l'algoritmo di ordinamento
  // sort(D, D + N);
  mergeSort(D, 0, N - 1);
}

int main()
{
  N = 1000000;
  if (N > MAXN)
  {
    cout << "N troppo grande\n";
    return 1;
  }
  else
  {
    cout << "N = 10^" << log10(N) << "\n";
  }
  tempo before = prendi_tempo();

  crea_numeri_casuali();
  tempo start = prendi_tempo();
  cout << "Numeri generati in " << differenza_tempo(before, start) << " secondi\n";

  // modifica questa funzione
  ordina();
  tempo end = prendi_tempo();
  cout << "Array ordinato in " << differenza_tempo(start, end) << " secondi\n";

  bool ordinato = controlla_ordinamento();
  tempo after = prendi_tempo();
  cout << "Controllo ordinamento in " << differenza_tempo(end, after) << " secondi\n";

  cout << "Tempo totale: " << differenza_tempo(before, after) << " secondi\n";

  if (!ordinato)
  {
    cout << "Array non ordinato\n";
  }
  else
  {
    cout << "Array ordinato\n";
  }
}