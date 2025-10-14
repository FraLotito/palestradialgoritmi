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
    int counter_1[C];
    int counter_2[C];
    for (int c = 0; c < C; c++)
    {
        counter_1[c] = 0;
        counter_2[c] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        counter_1[L[i]]++;
        counter_2[L[i]]++;
    }

    while (true)
    {
        if (counter_1[L[start_1]] > 1)
        {
            counter_1[L[start_1]]--;
            start_1++;
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        if (counter_1[L[end_1]] > 1)
        {
            counter_1[L[end_1]]--;
            end_1--;
        }
        else
        {
            break;
        }
    }

    int sol_1 = end_1 - start_1 + 1;

    int start_2 = 0;
    int end_2 = N - 1;

    while (true)
    {
        if (counter_1[L[end_2]] > 1)
        {
            counter_1[L[end_2]]--;
            end_2--;
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        if (counter_1[L[start_2]] > 1)
        {
            counter_1[L[start_2]]--;
            start_2++;
        }
        else
        {
            break;
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
