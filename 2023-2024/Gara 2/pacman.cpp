// @check-wrong-answer: *
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<array<int,3>> v(N);
    for(auto &[x,y,z]: v) cin >> x;
    for(auto &[x,y,z]: v) cin >> y;
    for(auto &[x,y,z]: v) cin >> z;

    bool ans = 1;

    auto check =[&](){
        sort(v.begin(), v.end());
        for(int i = 1; i < N; ++i)
            if(v[i][0] == v[i-1][0] && v[i][1] == v[i-1][1] && v[i][2] != v[i-1][2] + 1)
                ans = 0;
    };

    check();
    for(auto &[x,y,z]: v)swap(y,z);
    check();
    for(auto &[x,y,z]: v)swap(x,z);
    check();

    if(ans)cout << "YES" << endl;
    else cout << "NO" << endl;
}
