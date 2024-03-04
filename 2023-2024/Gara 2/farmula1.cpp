#include <iostream>
using namespace std;

int points[] = {0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	for(; t; t--)
	{
		int n;
		cin >> n;
		
		int score = 0;
		int max_score = 0;
		
		for(int i = 1; i <= n; i++)
		{
			int nr;
			cin >> nr;
			if(nr != 1)
				max_score += 25;
			else
				max_score += 18;
			if(nr <= 10)
				score += points[nr];
		}
		
		cout << (score >= max_score ? "Champion" : "Practice harder") << '\n';
	}
}

