#include<fstream>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;

std::vector<bool> usate;
vector< pair<int, int> > v;
int N;
int M;

void solve(int tessera, int len) {
	if(len > M) M = len;
	for(int i=0;i<N;i++) {
		if(!usate[i]) {
			if(tessera == v[i].first) {
				usate[i] = true;
				solve(v[i].second, len+1);
				usate[i] = false;
			}
			else if(tessera == v[i].second) {
				usate[i] = true;
				solve(v[i].first, len+1);
				usate[i] = false;
			}
		}
	}
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	in>>N;
	usate.resize(N);
	v.resize(N);
	int a,b;
	for(int i=0;i<N;i++) {
		in>>a>>b;
		v[i] = make_pair(a,b);
		usate[i] = false;
	}
	for(int i=0;i<N;i++) {
		usate[i] = true;
		solve(v[i].first, 1);
		solve(v[i].second, 1);
		usate[i] = false;
	}
	out<<M<<endl;

	in.close();
	out.close();
	return 0;
}