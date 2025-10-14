#include <fstream>
#include <iostream>

using namespace std;

int main(){//O(T * len_S)
	ifstream cin("input.txt");
    ofstream cout("output.txt");
  
	int T;
	cin >> T;
	int alphabet[26]={0};
	bool frequance_alphabet_single[26]={false};
	bool frequance_alphabet_double[26]={false};

	for (int ii = 0; ii < T; ii++) {//O(T)
		string S;
		cin >> S;
		int S_len=S.size();
		bool lasciapassare=true;

		for (int i = 0; i < S_len; i++){//O(len_S)
			++alphabet[S[i]-'a'];
		}
		for(int i = 0; i < 26 && lasciapassare; i++){//O(1)
			if(alphabet[i]>3){
				cout<<"-1\n";
				lasciapassare=false;
			}
		}

		if(lasciapassare){//I still could have: xx ... x ... x, which is invalid so -1
			for (int i = 0; i < S_len && lasciapassare; i++){//O(len_S)
				if(i+1<S_len && S[i]==S[i+1]){//for not being out-of-bound
					//double char
					if(!frequance_alphabet_double[S[i]-'a']){
						frequance_alphabet_double[S[i]-'a']=true;
						++i;//skip ahead because I've read also the second char
					} else{
						cout<<"-1\n";
						lasciapassare=false;
					}
				} else{//--> S[i] is single and different
					if(!frequance_alphabet_single[S[i]-'a'])//means that there wasnt so far
						frequance_alphabet_single[S[i]-'a']=true;//means one found for the first time
					else{//means the char was already found, so duplicate, so print(-1)
						cout<<"-1\n";
						lasciapassare=false;
					}
				}
			}

			if(lasciapassare){//printing the valid sentence
				for (int i = 0; i < S_len; i++){//O(len_S)
					if(i<S_len && i+1<S_len && S[i]==S[i+1]){//for not being out-of-bound
						//format: xx
						cout<<S[i]<<S[i]<<" ";
						i+=1;
					} else//format: x
						cout<<S[i]<<" ";
				}
				cout<<'\n';
			}
			lasciapassare=true;
		}

		//re-init for next cycle
		for (int i = 0; i < 26; i++){//O(1)
			alphabet[i]=0;
			frequance_alphabet_single[i]=false;
			frequance_alphabet_double[i]=false;
		}
		lasciapassare=true;
	}
	return 0;
}
