#include <stdio.h>
#include <assert.h>
#include <algorithm>

#define MAXN 10000

using namespace std;

int interroga(int N, int K, int D[]) {
    sort(D, D+N);
    int m = D[N-1] - D[0];
    for(int i=0;i<=N-K;i++) m = min(m , D[i+K-1] - D[i]);
    return m;
}

int D[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(2 == fscanf(fr, "%d%d", &N, &K));
    for (i = 0; i < N; i++)
        assert(1 == fscanf(fr, "%d", &D[i]));

    fprintf(fw, "%d\n", interroga(N, K, D));
    fclose(fr);
    fclose(fw);
    return 0;
}