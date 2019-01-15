#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr ll LLINF = 1e18 + 1;

struct Edge{ int v; ll weight; };	// arco
struct PQ{ ll d; int v; };			// costo e destinazione

bool operator>(const PQ &l, const PQ &r){ return l.d > r.d; }

//https://it.wikipedia.org/wiki/Algoritmo_di_Dijkstra
ll dijkstra(vector<vector<Edge>> &edges, int s, int t) {
	vector<ll> dist(edges.size(),LLINF);
	priority_queue<PQ,vector<PQ>,greater<PQ>> pq;
	dist[s] = 0; pq.push({0, s});
	while (!pq.empty()) {
		auto d = pq.top().d; auto u = pq.top().v; pq.pop();
		if(u==t) break;			//destinazione raggiunta
		if (d == dist[u])
			for(auto &e : edges[u]) if (dist[e.v] > d + e.weight)
				pq.push({dist[e.v] = d + e.weight, e.v});
	}
	return dist[t];
}

vector<vector<Edge>> v;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N, M;
    int s, d;
    in>>N>>M;
    in>>s>>d;
    v.resize(N+3);
    for(int i=0;i<M;i++) {
        int a,b; ll c; in>>a>>b>>c;
        v[a-1].push_back(Edge{b-1, c});
    }
    out<<dijkstra(v, s-1, d-1)<<endl;;
    in.close();
    out.close();
    return 0;
}