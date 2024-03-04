#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

int panini[10001];
int dp[10001];

int N;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> N;

    for (int i=0; i<N; i++) {
        in >> panini[i];
    }

    for (int i=0; i<N; i++) {
        dp[i] = 1;
        for (int j=0; j<i; j++) {
            if (panini[i] < panini[j]) {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    int maxlen = 0;
    for (int i=0; i<N; i++) {
        maxlen = max(maxlen,dp[i]);
    }
    out << maxlen << endl;
    return 0;
}