#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int N;
int v[MAXN];

int D(int i, int limite)
{
  if (i >= N)
    return 0;

  int non_prendo = D(i + 1, limite);

  if (v[i] < limite)
    return non_prendo;

  int prendo = D(i + 2, v[i]) + 1;

  return max(prendo, non_prendo);
}

int main()
{
  // more efficient input
  ios::sync_with_stdio(0);
  cin.tie(0);
  // file input / output
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> v[i];
  }

  cout << D(0, 0);
}