#include <bits/stdc++.h>
#define MAXN 100005
#define MAXK 10005

using namespace std;

typedef long long ll;

int n;
ll tulips[MAXN];
ll memo[2][MAXN];
int next_lowers[MAXN];

/**
 * Finds the first value which is smaller than the current one
 */
int find_next_lower(vector<pair<ll, int>> &next_mins, ll value) {
    // binary search
    int left = 0, right = next_mins.size() - 1, res = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (next_mins[mid].first <= value) {
            res = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return next_mins[res].second;
}

/**
 * Finds the farthest index contained in the next_mins array,
 * This is the best value we can get if we can ignore the penalty given by
 * choosing a worse tulip for the current basket
 */
int find_farthest(vector<pair<ll, int>> &next_mins, int max_index) {
    // binary search
    int left = 0, right = next_mins.size() - 1, res = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (next_mins[mid].second <= max_index) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return next_mins[res].second;
}

/**
 * Pushes the element <value, next_index> at the back of the array, but first
 * removes any irrelevant value, see min (or max) queue
 */
void push_lower(vector<pair<ll, int>> &next_mins, ll value, int new_index) {
    // assumes the first value is smaller than any valid value
    while (next_mins.back().first >= value) {
        next_mins.pop_back();
    }

    assert(next_mins.size() > 0);
    next_mins.push_back({value, new_index});
}

/**
 * k % 2 is a trick to save on memory, only 2 elements are needed at any point
 * the current k and k - 1, we access [k - 1] by doing (k + 1) % 2
 * The solutions are considered in order k = 0, ..., k = K
 */
void solve(int k) {
    memo[k % 2][n] = 0;

    if (k == 0) {
        fill(memo[k % 2], memo[k % 2] + n, LLONG_MIN >> 1);
        return;
    }

    // <value of tulip, index> TODO this can be cached
    vector<pair<ll, int>> memo_next_mins;
    memo_next_mins.push_back({LLONG_MIN >> 1, n});  // 0

    for (int i = n - 1; i >= 0; i--) {
        int next_lower = next_lowers[i];
        assert(tulips[i] >= tulips[next_lower]);

        // create a basket with just this tulip, or copy the solution of the
        // next one
        memo[k % 2][i] = max(memo[(k + 1) % 2][next_lower] + tulips[i],
                             memo[k % 2][next_lower]);

        // until next_lower, tulips[i] is the min,
        // pick the best of memo[k - 1][i + 1 <= j < next_lower]
        if (i + 1 < next_lower) {
            int farthest = find_farthest(memo_next_mins, next_lower - 1);
            ll best = memo[(k + 1) % 2][farthest];
            memo[k % 2][i] = max(memo[k % 2][i], best + tulips[i]);
        }

        push_lower(memo_next_mins, -memo[(k + 1) % 2][i], i);
    }
}

/**
 * We can precompute all the "next lower" indexes
 */
void compute_next_lower() {
    // <value of tulip, index>
    vector<pair<ll, int>> next_mins;
    next_mins.push_back({-1, n});

    for (int i = n - 1; i >= 0; i--) {
        int next_lower = find_next_lower(next_mins, tulips[i]);

        next_lowers[i] = next_lower;

        push_lower(next_mins, tulips[i], i);
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> tulips[i];
    }

    compute_next_lower();

    for (int i = 0; i <= k; i++) {
        solve(i);
    }

    cout << memo[k % 2][0] << "\n";
}
