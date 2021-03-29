#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(void)
{
	int n, m, q, s;
	while(cin >> n >> m >> q >> s) { // input
        if(n == 0 && m == 0 && q == 0) break;
        vector<vii> grafo(n, vii()); //grafo
        for(int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            grafo[a].push_back(ii(b, c)); //grafo costruito con anche i pesi (usando una pair)
        }
        
        vector<int> distanza(n, 1000000000); //inizializzo le distanze
        distanza[s] = 0;
        priority_queue<ii, vector<ii>, greater<ii> > pq; //priority queue per dijstra
        pq.push(ii(0, s));

        //dijkstra standard
        while(!pq.empty())
        {
            ii u = pq.top();
            pq.pop();
            if(u.first > distanza[u.second]) //se arrivo con un percorso di lunghezza maggiore alla distanza minima per arrivare in un nodo, ignoro
            {
                continue;
            }
            for(auto it = grafo[u.second].begin(); it != grafo[u.second].end(); it++)
            {
                if(distanza[u.second] + (it->second) < distanza[it->first])
                {
                    distanza[it->first] = distanza[u.second] + (it->second); //aggiorno la distanza
                    pq.push(ii(distanza[it->first], (it->first)));
                }
            }
        }
        for(int i=0;i<q;i++) {
            int b;
            cin>>b;
            if(distanza[b] != 1000000000) cout<<distanza[b]<<endl;
            else cout<<"Impossible"<<endl;
        }
        cout<<endl;
    }
	
	return 0;
}
