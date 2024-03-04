#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
ifstream in("input.txt"); ofstream out("output.txt");
int N,S,C;
int nstato[10000001];
int spostamento[10000001];
int nastro[1000001];
int mem[1000001];

bool visita(int cella, int stato)
{
    if(cella==0) return true;
    if(cella<0||cella>N) return false; //esco dal nastro
    if(mem[cella*S+stato]==1) return true; //finisce
    if(mem[cella*S+stato]==2) return false; //ciclo
    mem[cella*S+stato]=2;
    if(visita(cella+spostamento[nastro[cella]*S+stato],nstato[nastro[cella]*S+stato]))
    {
        mem[cella*S+stato]=1;
        return true;
    }
    return false;
}

int main()
{
    in>>N>>S>>C;
    for(int i=0;i<C*S;i++)
    {
        int corrente, letto;
        in>>corrente>>letto;
        in>>nstato[letto*S+corrente];
        in>>spostamento[letto*S+corrente];
    }
    for(int i=0;i<N;i++) in>>nastro[i];
    int cont=0;
    mem[0]=1;
    vector<int> sol;
    for(int i=0;i<N;i++)
    {
        if(visita(i,0))
        {
            cont++;
            sol.push_back(i);
        }
    }
    out<<cont<<endl;
    for(int i=0;i<sol.size();i++) out<<sol[i]<<endl;
    in.close(); out.close();
    return 0;
}
