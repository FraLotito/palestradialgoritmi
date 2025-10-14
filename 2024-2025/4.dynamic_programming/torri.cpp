#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int N;
int h[MAXN];
int c[MAXN];

map<pair<int, int>, int> memory;

int D(int i, int limite)
{
  if (i >= N)
    return 0;

  pair<int, int> key = make_pair(i, limite);
  if (memory[key])
    return memory[key];

  int abbatto = D(i + 1, limite) + c[i];

  if (h[i] > limite)
    memory[key] = abbatto;
  else
  {
    int non_abbatto = D(i + 1, h[i]);
    memory[key] = min(abbatto, non_abbatto);
  }

  return memory[key];
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
    cin >> h[i] >> c[i];
  }

  cout << D(0, INT_MAX);
}