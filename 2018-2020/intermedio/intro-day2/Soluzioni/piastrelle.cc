#include<fstream>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
int N;
string a = "[O]";
string b = "[OOOO]";

void solve(int left, string res) {
	if(left <= 0) out<<res<<endl;
	else {
		solve(left-1, res+a);
		if(left >= 2) solve(left-2, res+b);
	}
}

int main() {
	in>>N;
	solve(N, "");
	in.close();
	out.close();
}