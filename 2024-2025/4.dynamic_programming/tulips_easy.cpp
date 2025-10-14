#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100003;
int N, K;
ll flowers[MAXN];

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

  if (K == 1)
  {
    ll minim = INT32_MAX;
    for (int i = 0; i < N; i++)
      minim = min(minim, flowers[i]);
    cout << minim;
  }
  else if (K == 2)
  {
    ll max_beauty = INT32_MIN;
    for (int k = 1; k < N - 1; k++)
    {
      ll left_min = INT32_MAX, right_min = INT32_MAX;
      for (int i = 0; i < N; i++)
      {
        if (i < k)
          left_min = min(left_min, flowers[i]);
        else
          right_min = min(right_min, flowers[i]);
      }
      max_beauty = max(max_beauty, left_min + right_min);
    }
    cout << max_beauty;
  }
}