#include<fstream>
#include<iostream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int G, P;
    in>>G>>P;
    int i=1;
    int res = 0;
    while(G-i-P+1>=0) {
        G = G-i-P+1;
        res += i;
        i++;
    }
    res += G;
    out<<res<<endl;
    in.close();
    out.close();
    return 0;
}
