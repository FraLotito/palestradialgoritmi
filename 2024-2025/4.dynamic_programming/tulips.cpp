#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100003;
const int MAXK = 503;
int N, K;
ll flowers[MAXN];
ll dp_table[MAXN][MAXK];

ll dp(int i, int k)
{
  if (k == 0 && i < N)
    // avoid integer overflow
    return LONG_LONG_MIN / 2;
  if (i == N)
    return 0;

  if (dp_table[i][k] >= 0)
    return dp_table[i][k];

  ll cumulative_min_flower = flowers[i];
  ll cumulative_max_beauty = -1;
  for (int j = i; j < N; j++)
  {
    cumulative_min_flower = min(cumulative_min_flower, flowers[j]);
    cumulative_max_beauty = max(cumulative_max_beauty, dp(j + 1, k - 1) + cumulative_min_flower);
  }

  dp_table[i][k] = cumulative_max_beauty;
  return dp_table[i][k];
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
    cin >> flowers[i];
  }

  for (int i = 0; i <= N; i++)
    for (int j = 0; j <= K; j++)
      dp_table[i][j] = -1;

  cout << dp(0, K);
}