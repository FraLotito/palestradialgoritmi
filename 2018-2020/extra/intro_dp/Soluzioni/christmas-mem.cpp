#include <fstream>

using namespace std;

int n,b;
int values[100]; // Upper bound for N is 100
int dp[101][10001] = { 0 };

int santa(int i, int budget) {
    if (i<n) {
        if (dp[i][budget] == 0) {
            dp[i][budget] = min(santa(i+1,budget),santa(i+1,budget+values[i]));
        }
        return dp[i][budget];
    } else {
        return (budget >= b ? budget : INT32_MAX);
    }
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> n >> b;
    int sum = 0;
    for (int i=0; i<n; i++) {
        in >> values[i];
        sum += values[i];
    }
    if (sum < b) {
        out << sum << endl;
    } else {
        out << santa(0,0) << endl;
    }

    return 0;
}