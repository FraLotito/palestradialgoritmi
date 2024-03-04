// @check-accepted: examples Ntwo VKsmall Nsmall no-limits
// binary search for the answer

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N;
    long long K;
    cin >> N >> K;
    K *= N;
    
    long long sum = 0;
    vector<int> v(N);
    for(auto &x: v) {
        cin >> x;
        sum += x;
    }

    if(sum == K) {
        cout << 0 << endl;
        return 0;
    } else if(sum < K) {
        cout << (K - sum + N - 1)/N << endl;
        return 0;
    }

    int bs = 0;
    for(int i = 1<<29; i; i/=2) {
        int cur = bs + i;
        long long min_sum = 0;
        for(auto x: v)
            min_sum += max(1, x - cur);
        if(min_sum > K)bs = cur;
    }

    cout << bs + 1 << endl;
    return 0;
}
