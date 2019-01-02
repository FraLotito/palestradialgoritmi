#include<iostream>
using namespace std;

int main() {
    int a, b;
    int W, N;
    int area = 0;
    cin>>W>>N;
    for(int n=0;n<N;n++) {
        cin>>a>>b;
        area += a*b;
    }
    cout<<area/W<<endl;
}
