#include<iostream>
#include<fstream>
using namespace std;

int c(int n) {
    int res = 1;
    while(n != 1) {
        if(n%2 == 0) n/=2;
        else n = 3*n + 1;
        res++;
    }
    return res;
}

bool p(int n) {
    int lim = c(n);
    int res = 1;
    while(n != 1 && res < lim) {
        if(n%2 == 0) n/= 2;
        else n = 5*n + 1;
        res++;
    }
    if(n==1 && res < lim) return true;
    else return false;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int a, b;
    int res = 0;
    in>>a>>b;
    for(int i=a;i<=b;i++) {
        if(p(i)) res++;
    }
    out<<res<<endl;
    in.close();
    out.close();
    return 0;
}



