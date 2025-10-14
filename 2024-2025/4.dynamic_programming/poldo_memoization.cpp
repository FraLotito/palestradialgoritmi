#include <bits/stdc++.h>
const int MAXN = 10001;
using namespace std;
int N;
int memo[MAXN][MAXN];
int vini[MAXN];

int D(int i, int last)
{
  if (i >= N)
    return 0;

  if (!memo[i][last])
  {
    int non_prendo = D(i + 1, last);

    if (vini[i] >= last)
    {
      memo[i][last] = non_prendo;
      return non_prendo;
    }
    else
    {
      int prendo = D(i + 1, vini[i]) + 1;
      memo[i][last] = max(prendo, non_prendo);
      return max(prendo, non_prendo);
    }
  }

  return memo[i][last];
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