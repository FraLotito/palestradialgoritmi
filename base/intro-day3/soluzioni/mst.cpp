#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

/*
 * References: 
 * https://it.wikipedia.org/wiki/Albero_ricoprente_minimo
 * https://it.wikipedia.org/wiki/Mfset
 * https://it.wikipedia.org/wiki/Algoritmo_di_Kruskal
 */

struct UnionFind {
	vi par, rank, size; int c;
	UnionFind(int n) : par(n), rank(n,0), size(n,1), c(n) {
		for (int i = 0; i < n; ++i) par[i] = i;
	}

	int find(int i) { return (par[i] == i ? i : (par[i] = find(par[i]))); }
	bool same(int i, int j) { return find(i) == find(j); }
	int get_size(int i) { return size[find(i)]; }
	int count() { return c; }

	void merge(int i, int j) {
		if ((i = find(i)) == (j = find(j))) return;
		c--;
		if (rank[i] > rank[j]) swap(i, j);
		par[i] = j; size[j] += size[i];
		if (rank[i] == rank[j]) rank[j]++;
	}
};

struct E {int u, v; ll weight;};

vector<E> sol;
bool operator<(const E &l, const E &r){return l.weight < r.weight;}
ll kruskal(vector<E> &edges, int V) {
	sort(edges.begin(), edges.end());
	ll cost = 0, count = 0;
	UnionFind uf(V+1);
	for (auto &e : edges) {
		if (!uf.same(e.u, e.v)) {
            sol.push_back(e);
			// (w, (u, v)) fa parte del MST
			cost += e.weight;
			uf.merge(e.u, e.v);
			if ((++count) == V - 1) break;
		}
	}
	return cost;
}

vector<E> archi;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, M; in>>N>>M;
    for(int i=0;i<M;i++) {
        int a, b; ll c;
        in>>a>>b>>c;
        archi.push_back(E{a,b,c});
    }

    out<<kruskal(archi, N)<<endl;
    for(int i=0;i<sol.size();i++) out<<sol[i].u<<" "<<sol[i].v<<endl;

    in.close();
    out.close();
    return 0;
}
