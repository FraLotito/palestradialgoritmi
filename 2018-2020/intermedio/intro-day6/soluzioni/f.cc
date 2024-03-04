#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll LLINF = 1e18 + 1;

struct Edge{ int v; ll weight; };	
struct PQ{ ll d; int v; };			
bool operator>(const PQ &l, const PQ &r){ return l.d > r.d; }
vector<ll> dijkstra(vector<vector<Edge>> &edges, int s, int t) {
	vector<ll> dist(edges.size(),LLINF);
	priority_queue<PQ,vector<PQ>,greater<PQ>> pq;
	dist[s] = 0; pq.push({0, s});
	while (!pq.empty()) {
		auto d = pq.top().d; auto u = pq.top().v; pq.pop();
		if(u==t) break;			
		if (d == dist[u])
			for(auto &e : edges[u]) if (dist[e.v] > d + e.weight)
				pq.push({dist[e.v] = d + e.weight, e.v});
	}
	return dist;
}

int P, T;
vector<vector<Edge>> v;

int main() {
    cin>>P>>T;
    v.resize(P);
    for(int i=0;i<T;i++) {
        int a,b,c; cin>>a>>b>>c;
        v.at(a).push_back(Edge{b,c});
        v.at(b).push_back(Edge{a,c});
    } 
    vector<ll> d1 = dijkstra(v, 0, P-1);
    ll lmin = d1[P-1];
    vector<ll> d2 = dijkstra(v, P-1, 0);
    ll res = 0;
    for(int i=0;i<P;i++) 
        for(int j=0;j<v[i].size();j++) 
            if(d1[i] + d2[v[i][j].v] + v[i][j].weight == lmin) res += v[i][j].weight;
    cout<<res*2<<endl;
    return 0;
}