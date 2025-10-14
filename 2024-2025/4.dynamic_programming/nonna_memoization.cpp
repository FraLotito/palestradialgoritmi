#include <bits/stdc++.h>
using namespace std;

#define MAXN 5000
#define MAXP 1000000

int N, K;
int memo[MAXN][MAXN];
int P[MAXN];

int D(int i, int k)
{
  if (k <= 0)
    return 0;

  if (i >= N)
    return MAXP * 2;

  if (!memo[i][k])
  {
    int non_prendo = D(i + 1, k);
    int prendo = D(i + 1, k - P[i]) + P[i];

    memo[i][k] = min(prendo, non_prendo);
  }
  return memo[i][k];
}

int main()
{
  // more efficient input
  ios::sync_with_stdio(0);
  cin.tie(0);
  // file input / output
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> N >> K;
  for (int i = 0; i < N; i++)
  {
    cin >> P[i];
  }

  cout << D(0, K);
}