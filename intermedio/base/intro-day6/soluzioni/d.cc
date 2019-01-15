#include<iostream>
using namespace std;

int N, M;
int v[401];
bool first = true;
int main() {
    while(cin>>N>>M) {
        if(!first) cout<<endl;
        first = false;
        for(int i=0;i<401;i++)v[i] = 0;
        for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) v[i+j] = v[i+j] + 1;
        int m = 0;
        for(int i=2;i<M+N+1;i++) if(v[i] > m) m = v[i];
        for(int i=2;i<M+N+1;i++) if(v[i] == m) cout<<i<<endl;
    }
    return 0;
}
