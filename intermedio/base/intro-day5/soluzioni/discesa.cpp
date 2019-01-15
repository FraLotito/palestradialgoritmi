#include<iostream>
#include<fstream>
using namespace std;
int m[10][10];
int A;
int M = 0;

void solve(int r, int c, int s) {
    if(r<=A-1) {
        if(s > M) M = s;
        solve(r+1, c, s+m[r+1][c]);
        solve(r+1, c+1, s+m[r+1][c+1]);
    }
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    in>>A;

    for(int i=0;i<A;i++) {
        for(int j=0;j<i+1;j++){
            in>>m[i][j];
        }
    }
    solve(0,0, m[0][0]);
    out<<M<<endl;
    in.close();
    out.close();
    return 0;
}