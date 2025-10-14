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
    int start_1 = 0;
    int end_1 = N - 1;

    bool trovato_start_1 = true;
    while (trovato_start_1)
    {
        trovato_start_1 = false;
        for (int j = start_1 + 1; j <= end_1; j++)
        {
            if (L[j] == L[start_1])
            {
                trovato_start_1 = true;
                start_1++;
                break;
            }
        }
    }

    bool trovato_end_1 = true;
    while (trovato_end_1)
    {
        trovato_end_1 = false;
        for (int j = end_1 - 1; j >= start_1; j--)
        {
            if (L[j] == L[end_1])
            {
                trovato_end_1 = true;
                end_1--;
                break;
            }
        }
    }

    int sol_1 = end_1 - start_1 + 1;

    int start_2 = 0;
    int end_2 = N - 1;

    bool trovato_end_2 = true;
    while (trovato_end_2)
    {
        trovato_end_2 = false;
        for (int j = end_2 - 1; j >= start_2; j--)
        {
            if (L[j] == L[end_2])
            {
                trovato_end_2 = true;
                end_2--;
                break;
            }
        }
    }

    bool trovato_start_2 = true;
    while (trovato_start_2)
    {
        trovato_start_2 = false;
        for (int j = start_2 + 1; j <= end_2; j++)
        {
            if (L[j] == L[start_2])
            {
                trovato_start_2 = true;
                start_2++;
                break;
            }
        }
    }

    int sol_2 = end_2 - start_2 + 1;
    if (sol_1 < sol_2)
    {
        cout << sol_1 << endl; // print the result
        return 0;
    }
    else
    {
        cout << sol_2 << endl; // print the result
        return 0;
    }
}