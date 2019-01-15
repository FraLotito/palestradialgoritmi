#include<fstream>
#include<vector>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
int N;
int v[100];
int maxv=0;

int calc(int p, int quanti, int valore)
{
	if(quanti>maxv)maxv=quanti;
	for(int i=p;i<N;i++)
	{
		if(valore<=v[i])calc(i+2, quanti+1, v[i]);
	}
}


int main()
{
	in>>N;
	for(int i=0;i<N;i++)in>>v[i];
	calc(0,0,0);
	out<<maxv;
	in.close();
	out.close();
}





