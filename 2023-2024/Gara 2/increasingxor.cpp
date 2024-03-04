#include <bits/stdc++.h>

using namespace std;
int n, db[31];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        bool jo=1;
        for (int j=0; j<=30; j++) {
            if (x & (1<<j)) {
                if (1ll<<(j+1)<x) {
                    db[j]++;
                } else {
                    db[j]--;
                }
            }
            if (db[j]<-1) {
                jo=0;
            }
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}