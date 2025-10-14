#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long f(long long N, int div, long long init)
{
  // cout << N << " " << div << " " << init << endl;
  if (N == 1)
    return init;
  if (N % 2 == 0)
    return f(N / 2, div + 1, init);
  return f(N / 2, div + 1, init + pow(2, div));
}

int main()
{
  long long Q;
  cin >> Q;
  for (int i = 0; i < Q; i++)
  {
    long long N;
    cin >> N;
    // cout << N << ": " << f(N, 1, 1) << endl;
    cout << f(N, 1, 1) << endl;
  }
  return 0;
}