#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

void dfs(int partenza, const vvi &diretti, vi &sottoposti)
{
    for (int dipendente : diretti[partenza])
    {
        dfs(dipendente, diretti, sottoposti);
        sottoposti[partenza] += sottoposti[dipendente] + 1;
    }
}

int coppie(int N, int *C)
{
    vvi diretti(N);
    int direttore = -1;

    for (int i = 0; i < N; i++)
    {
        if (C[i] == -1)
        {
            direttore = i;
        }
        else
        {
            diretti[C[i]].push_back(i);
        }
    }
    vi sottoposti(N, 0);
    dfs(direttore, diretti, sottoposti);

    int result = 0;
    for (int i = 0; i < N; i++)
    {
        result += sottoposti[i];
    }
    return result;
}
