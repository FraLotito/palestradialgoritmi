#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>

using namespace std;

using ll = long long ;

const int MAXN=1001;

int n;
int t[MAXN][MAXN];
ll ans=0;
int d0[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

bool art[MAXN][MAXN];
int vis[MAXN][MAXN], dfs_low[MAXN][MAXN], dfs_num[MAXN][MAXN], L[MAXN][MAXN], R[MAXN][MAXN], sz[MAXN][MAXN], dfs_nxt=0;
int comp[MAXN][MAXN], compsz[MAXN*MAXN], nxt_comp=0;
vector<pair<int,int>> bc_child[MAXN][MAXN];

void dfs(int x, int y, bool root=true) {
    vis[x][y]=1;
    sz[x][y]=1;
    comp[x][y]=nxt_comp;
    compsz[nxt_comp]++;

    dfs_low[x][y]=dfs_num[x][y]=++dfs_nxt;
    L[x][y]=dfs_nxt;
    int gy_cnt=0;
    for(int i=0;i<4;++i) {
        int nx=x+d0[i][0], ny=y+d0[i][1];
        if(nx>=0 && ny>=0 && nx<n && ny<n && t[nx][ny]==t[x][y]) {
            if(!vis[nx][ny])  {
                gy_cnt++;
                dfs(nx, ny, false);
                sz[x][y]+=sz[nx][ny];
                dfs_low[x][y]=min(dfs_low[x][y], dfs_low[nx][ny]);
                if(root || dfs_low[nx][ny]>=dfs_num[x][y]) {
                    bc_child[x][y].push_back({nx,ny});
                }
                if((root && gy_cnt>1) || (!root && dfs_low[nx][ny]>=dfs_num[x][y])) {
                    art[x][y]=1;
                }
            }else if(vis[nx][ny]==1) {
                dfs_low[x][y]=min(dfs_low[x][y], dfs_num[nx][ny]);
            }
        }
    }

    R[x][y]=dfs_nxt;
    vis[x][y]=2;
} 

void solve() {
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            if(!vis[i][j]) {
                nxt_comp++;
                dfs(i,j);
            }
        }
    }

    auto calc_sz=[&](int oldX, int oldY, int newX, int newY) -> ll {
        set<int> s;
        for(int l=0;l<4;++l) {
            int nX=newX+d0[l][0], nY=newY+d0[l][1];
            if(nX>=0 && nY>=0 && nX<n && nY<n && t[oldX][oldY]==t[nX][nY]) {
                if(nX!=oldX || nY!=oldY) s.insert(comp[nX][nY]);
            }
        }

        ll sz_ans=1;
        if(s.count(comp[oldX][oldY])) {
            if(!art[oldX][oldY]) {
                sz_ans--;
            }else {
                int oldsComp=comp[oldX][oldY];
                s.erase(oldsComp);
                set<int> adjs;
                for(int l=0;l<4;++l) {
                    int nnX=newX+d0[l][0], nnY=newY+d0[l][1];
                    if(nnX>=0 && nnY>=0 && nnX<n && nnY<n)
                        if(nnX!=oldX || nnY!=oldY) {
                            if(t[nnX][nnY]==t[oldX][oldY] && comp[nnX][nnY]==oldsComp) {
                                bool found=false;
                                int ind=0;
                                for(auto& [x,y]:bc_child[oldX][oldY]) {
                                    if(L[x][y]<=L[nnX][nnY] && R[nnX][nnY]<=R[x][y]) {
                                        adjs.insert(ind);
                                        found=true;
                                    }
                                    ind++;
                                }
                                if(!found) adjs.insert(-1);
                            }
                        }
                }

                map<int,int> SZ;
                SZ[-1]=compsz[oldsComp]-1;
                int ind=0;
                for(auto& [x,y]:bc_child[oldX][oldY]) {
                    SZ[-1]-=sz[x][y];
                    SZ[ind]=sz[x][y];
                    ind++;
                }
                for(auto i:adjs) {
                    sz_ans+=SZ[i];
                }
            }
        }

        for(auto i:s) sz_ans+=compsz[i];

        return sz_ans;
    };

    vector<vector<ll>> ans_h(n, vector<ll>(n-1));
    vector<vector<ll>> ans_v(n-1, vector<ll>(n));
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            if(j+1<n) {
                if(t[i][j]==t[i][j+1]) {
                    ans_h[i][j]=0;
                }else {
                    ans_h[i][j]=calc_sz(i,j,i,j+1)*calc_sz(i,j+1,i,j);
                }
            }

            if(i+1<n) {
                if(t[i][j]==t[i+1][j]) {
                    ans_v[i][j]=0;
                }else {
                    ans_v[i][j]=calc_sz(i,j,i+1,j)*calc_sz(i+1,j,i,j);
                }
            }
        }
    }
    
    for(auto& i:ans_h) {
        for(auto& j:i) cout<<j<<" ";
        cout<<"\n";
    }

    for(auto& i:ans_v) {
        for(auto& j:i) cout<<j<<" ";
        cout<<"\n";
    }

    return ;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            cin>>t[i][j];
        }
    }

    solve();

    return 0;
}
