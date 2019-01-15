#include<fstream>
using namespace std;

int main() {
	int N, maxn;
	ifstream in("input.txt");
	ofstream out("output.txt");
	in>>N>>maxn;
	for(int i=1;i<N;i++) {
		int a;
		in>>a;
		maxn=max(maxn,a);
	}
	out<<maxn;
	in.close();
	out.close();
}
