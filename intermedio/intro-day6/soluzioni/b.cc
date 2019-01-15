#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n;
vector<vector<int> > grafo;
vector<int> peso;
vector<int> in_deg;

vector<int> peso_max;

vector<bool> visited;
vector<int> topological;

void tarjan(int pos)
{
	visited[pos] = true;
	for(auto it = grafo[pos].begin(); it != grafo[pos].end(); it++)
	{
		if(!visited[*it])
		{
			tarjan(*it);
		}
	}
	topological.push_back(pos);
}

void dfs(int pos)
{
	if(peso_max[pos] != -1)
	{
		return;
	}
	peso_max[pos] = peso[pos];
	for(auto it = grafo[pos].begin(); it != grafo[pos].end(); it++)
	{
		dfs(*it);
		peso_max[pos] = max(peso_max[pos], peso_max[*it]);
	}
}

int main(void)
{
	cin >> n;
	grafo.assign(n, vector<int>());
	peso.assign(n, 0);
	in_deg.assign(n, 0);
	for(int i = 0; i < n; i++)
	{
		int num;
		cin >> peso[i] >> num;
		for(int j = 0; j < num; j++)
		{
			int a;
			cin >> a;
			grafo[a-1].push_back(i);
			in_deg[i]++;
		}
	}
	
	visited.assign(n, false);
	for(int i = 0; i < n; i++)
	{
		if(!visited[i])
		{
			tarjan(i);
		}
	}
	
	peso_max.assign(n, -1);
	for(int i = n-1; i >= 0; i--)
	{
		if(peso_max[topological[i]] == -1)
		{
			dfs(topological[i]);
		}
	}
	
	int risultato = -1;
	int counter = 0;
	priority_queue<ii> pq;
	for(int i = 0; i < n; i++)
	{
		if(in_deg[i] == 0)
		{
			pq.push(ii(peso_max[i], i));
		}
	}
	
	while(!pq.empty())
	{
		ii u = pq.top();
		pq.pop();
		risultato = max(risultato, counter+peso[u.second]);
		counter++;
		for(auto it = grafo[u.second].begin(); it != grafo[u.second].end(); it++)
		{
			in_deg[*it]--;
			if(in_deg[*it] == 0)
			{
				pq.push(ii(peso_max[*it], *it));
			}
		}
	}
	cout << risultato << endl;
	
	return 0;
}
