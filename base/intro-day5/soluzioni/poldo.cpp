#include<fstream>
#include<vector>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int N;
vector<int> v;
int sol[10000];

int main()
{
    in>>N;
    for(int i=0;i<N;i++){int a; in>>a; v.push_back(a);}
    for(int i=N-1;i>=0;i--)
    {
        int mas=0;
        for(int j=N-1;j>=i;j--)
        {
            if(v[i]>v[j]&&sol[j]>mas)mas=sol[j];
        }
        sol[i]=mas+1;
    }
    int mas=sol[0];
    for(int i=1;i<N;i++)if(mas<sol[i])mas=sol[i];
    out<<mas;
    in.close();
    out.close();
}
