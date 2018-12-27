#include<fstream>
#include<vector>
#include<iostream>
using namespace std;

std::vector<int> v;
vector<bool> valid(101);

bool valida(int n) {
	if(valid[n]) return true;
	else {
		bool tmp = false;
		for(int i=0;i<v.size();i++) {
			if(n - v[i] >= 0) tmp = valida(n - v[i]);
			if(tmp) break;
		}
		valid[n] = tmp;
	}
	return valid[n];
}

int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");

	int N;
	in>>N;
	for(int i=0;i<N;i++) {
		int tmp;
		in>>tmp;
		v.push_back(tmp);
	}
	valid[0] = true;
	for(int i=0;i<101;i++) valida(i);
	for(int i=100;i>=0;i--) {
		if(!valid[i]) {
			out<<i<<endl;
			break;
		}
	}


	in.close();
	out.close();
	return 0;
}