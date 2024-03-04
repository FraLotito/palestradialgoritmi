#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

void testCase() {
  int n;
  cin >> n;

  vector<int64_t> a(n + 1);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  int q;
  cin >> q;

  vector<vector<pair<int, int>>> queries(n + 1);

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    
    queries[r].emplace_back(l, i);
  }

  vector<int> aib(n + 1);

  auto update = [&](int index) {
    for (int i = index; i <= n; i += i & -i) {
      aib[i] += 1;
    }
  };

  auto query = [&](int l, int r) -> int64_t {
    int64_t res = 0;

    for (int i = r; i > 0; i = i & (i - 1)) {
      res += aib[i];
    }

    for (int i = l - 1; i > 0; i = i & (i - 1)) {
      res -= aib[i];
    }

    return res;
  };
  
  vector<int64_t> sol(q);

  vector<int> prev_lengths, curr_lengths;

  for (int r = 1; r <= n; ++r) {
    curr_lengths.clear();
    curr_lengths.emplace_back(1);
    update(r);

    for (const int &len : prev_lengths) {
      if (a[r] % (len + 1) == 0) {
        curr_lengths.emplace_back(len + 1);
        update(r - len);
      }
    }

    prev_lengths = curr_lengths;

    for (const auto &it : queries[r]) {
      int l, index;
      tie(l, index) = it;

      sol[index] = query(l, r);
    }
  }

  for (const int &it : sol) {
    cout << it << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int tests;
  cin >> tests;

  for (int tc = 0; tc < tests; ++tc) {
    testCase();
  }

  return 0;
}