#include <fstream>
#include <map>
using namespace std;

int N;
int h[1002], c[1002];
map<pair<int, int>, int> memo;

int solve(int hmin, int i) {
    pair<int, int> key = make_pair(hmin, i);
    if(memo[key]) return memo[key];
    if(i<0) return 0;
    else {
        if(h[i] > hmin) memo[key] = min(c[i] + solve(h[i], i-1), solve(hmin, i-1));
        else memo[key] = solve(hmin, i-1);
        return memo[key];
    } 
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    in>>N;
    long s = 0;
    for(int i=0;i<N;i++) {
        in>>h[i]>>c[i];
        s+=c[i];
        c[i] = -c[i];
    }
    out<<s + solve(0, N-1)<<endl;
    in.close();
    out.close();
    return 0;
}