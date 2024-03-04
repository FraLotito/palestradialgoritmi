// @check-accepted: examples K<=2 N<=16 N<=500 full
#include <fstream>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

using ll = long long ;

int n,k;
int t[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>t[i];
    t[0]=-1;
    vector<vector<ll>> dp(k+1, vector<ll>(n+1, -(1LL<<60)));
    dp[0][0]=0;
    vector<array<ll,3>> st;
    for(int j=1;j<=k;++j) {
        st.clear();
        st.push_back({t[0], dp[j-1][0], 0});
        for(int i=1;i<=n;++i) { 
            array<ll,3> curr{};
            curr[0]=t[i];
            curr[1]=dp[j-1][i-1];
            while(curr[0]<=st.back()[0]) {
                curr[1]=max(curr[1], st.back()[1]);
                st.pop_back();
            }
            curr[2]=max(st.back()[0]+st.back()[1], st.back()[2]);
            st.push_back(curr);
            
            dp[j][i]=max(st.back()[0]+st.back()[1], st.back()[2]);
        }
    }

    cout<<dp[k][n]<<"\n";

    return 0;
}
