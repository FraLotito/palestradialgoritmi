#include<fstream>
#include<vector>
#include<iostream>
using namespace std;

int N, M;
vector<int> g[10002];
int label = 1;
int vis[10002];

void dfs(int n) {
	if(vis[n] == 0) {
		vis[n] = label;
		for(int i=0;i<g[n].size();i++) dfs(g[n][i]);
	}
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	in>>N>>M;
	for(int i=0;i<M;i++) {
		int a,b;
		in>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for(int i=0;i<N;i++) {
		if(vis[i] == 0) {
			dfs(i);
			label++;
		}
	}
	label--;

	out<<label - 1<<endl;


	in.close();
	out.close();
	return 0;
}