// @check-accepted: examples sub1 sub2 full
/**
 *    author:  BERNARD B.01
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef B01
#include "deb.h"
#else
#define deb(...)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    if (s.length() == 1) {
      cout << -1 << '\n';
      continue;
    }
    reverse(s.begin(), s.end());
    string d = s.substr(0, 2);
    if (d == "52" || d == "05" || d == "57" || d == "00") {
      cout << 0 << '\n';
      continue;
    }
    if (d == "25" || d == "50" || d == "75") {
      cout << 1 << '\n';
      continue;
    }
    array<int, 10> cnt = {};
    for (char c : s) {
      cnt[(int) (c - '0')] += 1;
    }
    if ((d[0] == '5' && (cnt[2] > 0 || cnt[7] > 0)) || (d[0] == '0' && (cnt[5] > 0 || cnt[0] > 1))) {
      cout << 1 << '\n';
      continue;
    }
    if ((d[1] == '2' && cnt[5] > 0) || (d[1] == '5' && cnt[0] > 0) || (d[1] == '7' && cnt[5] > 0) || (d[1] == '0' && cnt[0] > 1)) {
      cout << 1 << '\n';
      continue;
    }
    if ((cnt[5] > 0 && (cnt[0] > 0 || cnt[2] > 0 || cnt[7] > 0)) || cnt[0] >= 2) {
      cout << 2 << '\n';
      continue;
    }
    cout << -1 << '\n';
  }
  return 0;
}
// last two digits must be 25, 50, 75, or 00
