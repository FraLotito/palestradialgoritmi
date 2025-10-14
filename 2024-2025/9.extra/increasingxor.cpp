#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100003;
int N;
int v[MAXN];
bool used[MAXN];

bool possibleSubsequence(int k)
{
  for (int i = 0; i < k; i++)
  {
    used[i] = false;
  }

  int cumulative_xor = 0;
  for (int i = 0; i < k; i++)
  {
    int min_new_i = -1;

    for (int j = 0; j < k; j++)
    {
      if (used[j])
        continue;

      int new_xor = cumulative_xor xor v[j];
      if (min_new_i == -1 && new_xor > cumulative_xor)
      {
        min_new_i = j;
        continue;
      }

      int best_xor_thus_far = cumulative_xor xor v[min_new_i];
      if (new_xor < best_xor_thus_far && new_xor > cumulative_xor)
        min_new_i = j;
    }

    if (min_new_i == -1)
      return false;

    used[min_new_i] = true;
    cumulative_xor = cumulative_xor xor v[min_new_i];
  }

  return true;
}

int main()
{
  // more efficient input
  ios::sync_with_stdio(0);
  cin.tie(0);
  // file input / output
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> v[i];

  for (int k = 1; k <= N; k++)
  {
    if (possibleSubsequence(k))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}