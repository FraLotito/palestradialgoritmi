// @check-accepted: examples QVsmall AB LettersSmall no-limits
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

const int kSigma = 52;

void testCase() {
  int q;
  cin >> q;

  vector<pair<int, char>> freq(kSigma);

  for (int i = 0; i < kSigma; ++i) {
    freq[i].first = 0;
    
    if (i < kSigma / 2) {
      freq[i].second = 'a' + i;
    } else {
      freq[i].second = 'A' + i - kSigma / 2;
    }
  }

  int length = 0;
  int64_t good_pairs = 0;

  for (int qq = 0; qq < q; ++qq) {
    int occ, ops;
    char ch;
    cin >> occ >> ch >> ops;

    assert(('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'));

    length += occ;
    good_pairs += (int64_t)occ * (occ - 1) / 2;

    for (int i = 0; i < kSigma; ++i) {
      if (freq[i].second == ch) {
        good_pairs += (int64_t)freq[i].first * occ;
        
        freq[i].first += occ;

        while (i + 1 < kSigma && freq[i + 1].first < freq[i].first) {
          swap(freq[i], freq[i + 1]);
          i += 1;
        }

        break;
      }
    }

    int64_t aux_good_pairs = good_pairs;
    int64_t prev_chg = 0;

    for (int i = 0; i < kSigma - 1 && ops > 0; ++i) {
      int change = min(freq[i].first, ops);
      ops -= change;

      aux_good_pairs -= (int64_t)change * (freq[i].first - change);
      aux_good_pairs += (int64_t)change * (freq[kSigma - 1].first + prev_chg);
      prev_chg += change;
    }

    cout << (int64_t)length * (length - 1) / 2 - aux_good_pairs << '\n';
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
