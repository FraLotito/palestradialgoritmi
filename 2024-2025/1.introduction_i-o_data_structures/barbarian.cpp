// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    // ofstream cout("output.txt");

    int N;
    cin >> N;

    // vector<int> D(N); // il programma fornito non va bene! overflow di int
    vector<long long> D(N);
    for (int i = 0; i < N; ++i)
        cin >> D[i];

    // int infinito = INT_MAX; // il programma fornito non va bene! overflow di int
    long long infinito = LLONG_MAX;

    // controlla il vettore sia davvero ordinato. se non lo e', vuol dire alcuni valori vanno in overflow
    for (int i = 1; i < N; ++i)
    {
        if (D[i - 1] > D[i])
            throw invalid_argument("overflow of input");
        if (D[i] > infinito)
            throw invalid_argument("infinito troppo piccolo");
    }

    vector<int> ultima(N);

    // INSERT YOUR CODE HERE
    for (int partenza = 0; partenza < N; partenza++)
    {
        vector<bool> distrutta(N, false);
        int attuale = partenza;
        int attuale_precedente;

        for (int intere = N; intere > 0; intere--)
        {
            attuale_precedente = attuale;
            distrutta[attuale] = true;
            int prima = attuale - 1;
            while (prima >= 0 && distrutta[prima])
                prima--;
            int dopo = attuale + 1;
            while (dopo < N && distrutta[dopo])
                dopo++;

            // int distanza_prima = infinito;
            long long distanza_prima = infinito;
            if (prima >= 0)
                distanza_prima = D[attuale] - D[prima];
            // int distanza_dopo = infinito;
            long long distanza_dopo = infinito;
            if (dopo < N)
                distanza_dopo = D[dopo] - D[attuale];

            if (distanza_prima <= distanza_dopo)
                attuale = prima;
            else
                attuale = dopo;
        }

        ultima[partenza] = attuale_precedente;
    }

    for (int i = 0; i < N; ++i)
        cout << ultima[i] << " ";
    cout << endl;

    return 0;
}
