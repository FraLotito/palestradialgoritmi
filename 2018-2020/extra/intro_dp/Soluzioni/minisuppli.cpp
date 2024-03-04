#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

int suppli[11];
int N;

bool solve(int n) {
    if (n==0) return true;
    else if (n<0) return false;
    else {
        bool solved = false;
        for (int i=0; i<N; i++) {
            solved = solved || solve(n-suppli[i]);
        }
        return solved;
    }
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    in >> N;
    for (int i=0; i<N; i++) {
        in >> suppli[i];
    }
    for (int i=100; i>=0; i--) {
        if (!solve(i)) {
            out << i << endl;
            break; 
        }
    }
    return 0;
}