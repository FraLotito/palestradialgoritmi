/*
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <fstream>
#include <iostream>
#define FOR(i) for (int i = 0; i < 15; i++)

using namespace std;

// input data
long long V[15];
long long sol[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
long long monete[15] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000};

int main()
{
    //  uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    FOR(i)
    {
        cin >> V[i];
    }

    // insert your code here
    long long totale = 0;
    FOR(i)
    {
        totale += monete[i] * V[i];
    }

    for (int i = 14; i >= 0; i--)
    {
        sol[i] = totale / monete[i];
        totale = totale % monete[i];
    }

    FOR(i)
    {
        cout << sol[i] << " ";
    }
    cout << endl;
    return 0;
}
