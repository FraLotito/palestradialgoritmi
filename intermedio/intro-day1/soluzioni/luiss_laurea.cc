#include<fstream>
#include<utility>
using namespace std;

int pa, pb, pc, pd;
int M = 1 << 30;

void solve(int N, int qa, int qb, int qc, int qd, int prezzo) {
    if(N <= 0) M = min(prezzo, M);
    else {
        if(qa > 0) solve(N-2, qa-1, qb, qc, qd, prezzo + pa);
        if(qb > 0) solve(N-4, qa, qb-1, qc, qd, prezzo + pb);
        if(qc > 0) solve(N-5, qa, qb, qc-1, qd, prezzo + pc);
        if(qd > 0) solve(N-7, qa, qb, qc, qd-1, prezzo + pd);
    }
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N, qa, qb, qc, qd;
    in>>N;

    in>>qa>>pa>>qb>>pb>>qc>>pc>>qd>>pd;

    solve(N, qa, qb, qc, qd, 0);
    
    out<<M<<endl;

    in.close();
    out.close();
    return 0;
}
