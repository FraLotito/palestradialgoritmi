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

void ordina()
{
  // implementa qui l'algoritmo di ordinamento
  // sort(D, D + N);
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