// NOTE: it is recommended to use this even if you don't understand the
// following code.

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N, C;
    cin >> N >> C;
    vector<int> L(N);
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
    }

    // insert your code here
    for (int c = 0; c <= N; c++)
    {
        for (int start = 0; start < N - c; start++)
        {
            bool trovati[C];
            for (int j = 0; j < C; j++)
                trovati[j] = false;

            for (int j = start; j < start + c; j++)
            {
                trovati[L[j]] = true;
            }

            bool trovati_tutti = true;
            for (int j = 0; j < C; j++)
            {
                if (!trovati[j])
                    trovati_tutti = false;
            }
            if (trovati_tutti)
            {
                cout << c << endl; // print the result
                return 0;
            }
        }
    }
}