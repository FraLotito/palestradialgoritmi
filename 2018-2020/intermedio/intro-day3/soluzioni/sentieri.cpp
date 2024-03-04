#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int N, A, B;
vector<pair<int,int> > v[101];
bool vis[101];
int sol[101];

void dfs(int n) {
    if(!vis[n]) {
        vis[n] = true;
        for(int i=0;i<v[n].size();i++) {
            if(sol[n]+v[n][i].second < sol[v[n][i].first]) {
                vis[v[n][i].first] = false;
                sol[v[n][i].first] = sol[n]+v[n][i].second;
            }
            dfs(v[n][i].first);
        }
    }
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    in>>N>>A>>B;
    for(int i=0;i<=N;i++)sol[i]=A+B+10;
    sol[1] = 0;
    for(int i=0;i<A;i++) {
        int a, b;
        in>>a>>b;
        v[a].push_back(make_pair(b, 0));
        v[b].push_back(make_pair(a, 0));
    }
    for(int i=0;i<B;i++) {
        int a, b;
        in>>a>>b;
        v[a].push_back(make_pair(b, 1));
        v[b].push_back(make_pair(a, 1));
    }

    dfs(1);
    out<<sol[N]<<endl;
    in.close();
    out.close();
    return 0;
}
