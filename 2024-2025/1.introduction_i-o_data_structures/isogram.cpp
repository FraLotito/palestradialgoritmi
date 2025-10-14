// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// input data
int N;
string S;

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N;
    cin.ignore();

    for (int i=0; i<N; i++) {
        getline(cin, S);

        // insert your code here
    }

    cout << 42 << endl; // print the result
    return 0;
}
