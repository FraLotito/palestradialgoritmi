#include <bits/stdc++.h>
using namespace std;

#define MAXD 1000000*1ULL
typedef unsigned long long ull;

int average(vector<ull>& P, ull sum_prod, ull NK){//O(n * logn)
    if(sum_prod<NK) return 1;//why only "1" every time?
    else if(sum_prod==NK) return 0;//why so?

    sort(P.rbegin(), P.rend());//decrescente, complexity?, why sorting?
    ull difference=sum_prod-NK;//what to use it for?
    int counter_num_changed = 0;

	for (int i = 0; i < P.size() && difference > 0; ++i){//O(n)
		ull less_then_Pi = (P[i]-1);
        ull decrement = min(difference, less_then_Pi);
        P[i] = max((P[i] - decrement), 1ULL);//explain why and what is it usefull for
        difference -= decrement;
        ++counter_num_changed;
    }
    return counter_num_changed;
}

int main() {
	ifstream cin("input.txt");
    ofstream cout("output.txt");

    ull sum_prod=0, N, K;// !!!
    //I sincerely DON'T have idea why N,K have to be ULL, else many cases'll be wrong
    //perphaps bc smtg regarding casting from int to ULL
    //... idk and ... tbh idc

    cin >> N >> K;
    vector<ull> P(N);
    for (int i = 0; i < N; ++i){
        cin >> P[i];
		sum_prod+=P[i];
	}

	ull NK= N*K;

    cout << average(P, sum_prod, NK);
	return 0;
}
