#include<iostream>
#include<fstream>
using namespace std;

int solve(int n){
    if(n == 1) {
        return 1;
    }
    if(n%2 == 0) {
        return solve(n/2)+1;
    }
    else {
        return solve(3*n+1)+1;
    }
}

int main (){
	ifstream in("input.txt");
	ofstream out("output.txt");

	int N;
	in >> N;

	out << solve(N);

	return 0;
}
