#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    vector<int> pari;
    vector<int> dispari;
    int in, N, out=-1;
    fin>>N;
    for(int i=0;i<N;i++) {
            fin>>in;
            if(in%2==0) pari.push_back(in); else dispari.push_back(in);
    }
    sort(pari.begin(), pari.end());
    sort(dispari.begin(), dispari.end());
    if(pari.size()>=2) {
        int somma=pari[pari.size()-1]+pari[pari.size()-2];
        out=max(out, somma);
    } 
    if(dispari.size()>=2) {
        int somma=dispari[dispari.size()-1]+dispari[dispari.size()-2];
        out=max(out, somma);
    }
    fout<<out;
    fin.close();
    fout.close();
}
