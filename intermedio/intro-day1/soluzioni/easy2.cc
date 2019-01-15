#include<fstream>
using namespace std;

int main() {
	ifstream in("input.txt");
	ofstream fout("output.txt");
	int N, a, b, out=-1;
	in>>N;
	for(int i=0;i<N;i++) {
		in>>a>>b;
		a+=b;
		if(a%2==0) out=max(out, a);
	}
	fout<<out;
	in.close();
	fout.close();
}
