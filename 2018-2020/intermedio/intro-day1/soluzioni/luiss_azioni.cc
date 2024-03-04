#include<iostream>
#include<fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N;
    in>>N;
    int a, b;
    in>>a;
    int M = 0;
    for(int i=0;i<N;i++) {
        in>>b;
        M = max(abs(a-b), M);
        a = b;
    }
    out<<M<<endl;
    in.close();
    out.close();
}
