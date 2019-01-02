#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<stack>
using namespace std;

class UF {
  int *id, cnt, *sz;
  public:

UF(int N) {
    cnt = N; id = new int[N]; sz = new int[N];
    for (int i = 0; i<N; i++)  id[i] = i, sz[i] = 1; }
~UF() { delete[] id; delete[] sz; }

int find(int p) {
    int root = p;
    while (root != id[root])    root = id[root];
    while (p != root) { int newp = id[p]; id[p] = root; p = newp; }
    return root;
}

void merge(int x, int y) {
    int i = find(x); int j = find(y); if (i == j) return;
    if (sz[i] < sz[j]) { id[i] = j, sz[j] += sz[i]; }
    else { id[j] = i, sz[i] += sz[j]; }
    cnt--;
}

bool connected(int x, int y) { return find(x) == find(y); }

int count() { return cnt; }
};

int N, K, T;
int sol[100002];
pair<int, int> e[1000002];
priority_queue<pair<int, int> > mst;

int fast_read_int() {

    int c, n = 0;

    do c = getchar_unlocked();

    while(c < '0' || c > '9');

    do {

    n = (n << 3) + (n << 1) + (c - '0');

    c = getchar_unlocked();

} while(c >= '0' && c <= '9');

    return n;

}

int main() {
    N = fast_read_int();
    K = fast_read_int();
    T = fast_read_int();

    N = N+1;
    UF ufind = UF(N);

    for(int i=0;i<K;i++) {
        int a,b, V;
        a = fast_read_int();
        b = fast_read_int();
        V = fast_read_int();
        e[i] = make_pair(a,b);
        mst.push(make_pair(V, i));
    }

    int ord[100002];
    int wi[100002];

    for(int t=0;t<T;t++) {
        int w;
        w = fast_read_int();
        ord[t] = w;
        wi[t] = w;
    }

    sort(wi, wi+T);

    int t = T - 1;

    for(int i=0;i<T;i++) sol[i] = -1;

    while(!mst.empty() && t >= 0) {
        pair<int, int> tmp = mst.top();
        int w = wi[t];
        if(w <= tmp.first) {
            mst.pop();
            if(ufind.find(e[tmp.second].first) != ufind.find(e[tmp.second].second)) {
                ufind.merge(e[tmp.second].first, e[tmp.second].second);
            }
        } else {
            t--;
            sol[w] = ufind.count();
        }
    }

    while(t >= 0) {
        int w = wi[t];
        t--;
        sol[w] = ufind.count();
    }


    for(int t=0;t<T;t++) cout<<sol[ord[t]] - 1<<endl;
    return 0;
}