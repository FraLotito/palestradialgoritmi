#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int N, M;

vector<int> v[31];
int vis[31];
vector<int> sol;

bool solve(int n, int s) {
    if(n == 0 && s == 1) {
        return true;
    }
        if(vis[n] == s) return false;
        else if(vis[n] == 3) return false;
        else if(vis[n] == 0) vis[n] = s;
        else vis[n] = 3;
        for(int i=0;i<v[n].size();i++) {
            int stato;
            if(s == 1) stato = 2;
            else stato = 1;
            if(solve(v[n][i], stato)) {
                sol.push_back(n);
                return true;
            }
        }
    return false;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    in>>N>>M;
    for(int i=0;i<M;i++) {
        int a,b;
        in>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    sol.push_back(0);
    solve(0, 2);
    out<<sol.size()-1<<endl;
    for(int i=sol.size()-1;i>=0;i--) out<<sol[i]<<" ";
    out<<endl;
    out.close();
    in.close();
    return 0;
}
