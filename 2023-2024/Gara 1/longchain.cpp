// @check-accepted: examples NVsmall Nsmall Nprettybig nolimits
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int kN = 1e5;
vector<int> g[1 + kN];

int solve_odd(vector<int> &vals, int target);

int solve_even(vector<int> &vals, int target, bool is_root) {
  if (vals.empty()) {
    return 0;
  }

  if (!is_root && vals.back() >= target) {
    int first_greater = (int)vals.size() - 1;

    while (first_greater && vals[first_greater - 1] >= target) {
      first_greater -= 1;
    }

    vector<int> vals_odd = vals;

    vals_odd.erase(vals_odd.begin() + first_greater);

    int res = solve_odd(vals_odd, target);

    if (res != -1) {
      return res;
    }
  }

  int l = 0, r = (int)vals.size() - 1;

  while (l < r) {
    if (vals[l] + vals[r] < target) {
      return -1;
    }

    l += 1;
    r -= 1;
  }

  return 0;
}

bool check(vector<int> &vals, int target, int skipped) {
  int l = 0, r = (int)vals.size() - 1;

  while (l < r) {
    if (l == skipped) {
      l += 1;
    }

    if (r == skipped) {
      r -= 1;
    }

    if (r <= l) {
      break;
    }

    if (vals[l] + vals[r] < target) {
      return false;
    }

    l += 1;
    r -= 1;
  }

  return true;
}

int solve_odd(vector<int> &vals, int target) {
  int l = 0, r = (int)vals.size() - 1, res = -1;

  while (l <= r) {
    int mid = (l + r) >> 1;

    if (check(vals, target, mid)) {
      res = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  if (res == -1) {
    return -1;
  }

  return vals[res];
}

int solve(vector<int> &vals, int target, bool is_root) {
  sort(vals.begin(), vals.end());

  if ((int)vals.size() % 2 == 0) {
    return solve_even(vals, target, is_root);
  }

  return solve_odd(vals, target);
}

int dfs(int u, int par, int len) {
  vector<int> paths;

  for (const int v : g[u]) {
    if (v != par) {
      int res = dfs(v, u, len);

      if (res == -1) {
        return -1;
      }

      paths.emplace_back(res + 1);
    }
  }

  return solve(paths, len, u == 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;

    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  int l = 1, r = n - 1, answer = 0;

  while (l <= r) {
    int mid = (l + r) >> 1;

    int res = dfs(1, 0, mid);

    if (res == 0 || res >= mid) {
      answer = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  
  cout << answer << '\n';

  return 0;
}
