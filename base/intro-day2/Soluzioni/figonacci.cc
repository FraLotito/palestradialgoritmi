#include<fstream>
#include<iostream>
using namespace std;
int N, M;
int memo[1000002];
int v[1000002];


int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	in>>N>>M;
	memo[0] = ((-1 % M) + M) % M;
	for(int i=1;i<=N;i++) {
		v[i+1] = ((((i % M)*(v[i]%M)) % M)  - (memo[i-1] %M)) % M;
		memo[i] = ((memo[i-1] % M) + (v[i] % M)) %M;
	}
	out<<((v[N] % M) + M) %M<<endl;
	in.close();
	out.close();
}
