#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int K, N;
typedef struct persona {
        int a,b;
};
vector<persona> v;

bool cmp(persona a, persona b)
{
     if(a.a<b.a) return true;
     return false;
}

int main()
{
    fin>>K>>N;
    for(int i=0;i<N;i++) { persona p; fin>>p.a>>p.b; v.push_back(p); }
    sort(v.begin(), v.end(), cmp);
    int fine=0;
    int cont=0;
    while(fine<K)
    {
              int maxFine=0;
              for(int i=0;i<N;i++)
              {
                      if(v[i].a<=fine&&v[i].b>maxFine) maxFine=v[i].b;
              } 
              maxFine++;
              fine=maxFine;
              cont++;
    }
    fout<<cont;
    fin.close();
    fout.close();
}
