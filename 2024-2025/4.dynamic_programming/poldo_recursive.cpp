#include <bits/stdc++.h>
const int MAXN = 10004;
using namespace std;
int N;
int vini[MAXN];

int D(int i, int last)
{
  if (i >= N)
    return 0;

  int non_prendo = D(i + 1, last);

  if (vini[i] >= last)
    return non_prendo;

  int prendo = D(i + 1, vini[i]) + 1;
  return max(prendo, non_prendo);
}

int main()
{
  int i, a;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> N;
  for (i = 0; i < N; i++)
  {
    cin >> a;
    vini[i] = a;
  }

  cout << D(0, MAXN - 1);
}