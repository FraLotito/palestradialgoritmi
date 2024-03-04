#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

const int mod[] = {(int)1e9 + 7, (int)1e9 + 9};
const int base[] = {29, 31};
const int kN = 1e5;
int p[2][1 + kN], h[2][1 + kN];
vector<int> divs[1 + kN];

void addSelf(int &x, int y, int mod) {
  x += y;
  if (x >= mod) {
    x -= mod;
  }
}

int add(int x, int y, int mod) {
  addSelf(x, y, mod);
  return x;
}

void multSelf(int &x, int y, int mod) {
  x = (int64_t)x * y % mod;
}

int mult(int x, int y, int mod) {
  multSelf(x, y, mod);
  return x;
}

void precalc(int n) {
  for (int j = 0; j < 2; ++j) {
    p[j][0] = 1;

    for (int i = 1; i <= n; ++i) {
      p[j][i] = mult(p[j][i - 1], base[j], mod[j]);
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 2 * i; j <= n; j += i) {
      divs[j].emplace_back(i);
    }
  }
} 

pair<int, int> getHash(int l, int r) {
  int res[2];

  for (int i = 0; i < 2; ++i) {
    res[i] = add(h[i][r], mod[i] - mult(h[i][l - 1], p[i][r - l + 1], mod[i]), mod[i]);
  }

  return make_pair(res[0], res[1]);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;
  
  assert(n <= kN);

  for (const char ch : s) {
    assert('a' <= ch && ch <= 'z');
  }

  s = '$' + s;

  precalc(n);

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j) {
      h[j][i] = add(mult(h[j][i - 1], base[j], mod[j]), s[i] - 'a' + 1, mod[j]);
    }
  }

  int q;
  cin >> q;

  for (int qq = 0; qq < q; ++qq) {
    int l, r;
    cin >> l >> r;
    l++, r++;

    assert(1 <= l);
    assert(l <= r);
    assert(r <= n);

    bool ok = false;

    for (const int len : divs[r - l + 1]) {
      int groups = (r - l + 1) / len;

      if (getHash(l, r - len) == getHash(l + len, r)) {
        ok = true;
        break;
      }
    }

    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}