#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        unsigned long long N, K;
        cin >> N >> K;

		if(K==1) cout<<"YES\n";//why?
		else{
			unsigned long long sum_up_to_k=0;
			/*for (int j = 1; j <= K; j++)//O(K)
				sum_up_to_k+=j;
			*/
			//instead use Gauss method:
			++K;
			sum_up_to_k=(K*(K-1))/2;//O(1) and not O(K)

			if(sum_up_to_k==N || sum_up_to_k==N-1) cout<<"YES\n";
			else cout<<"NO\n";
		}
    }

    return 0;
}
