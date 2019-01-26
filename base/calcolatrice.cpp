#include<iostream>
#include<math.h>
using namespace std;

int main(){

    int a, b;
    char op;

    cout << "Inserire primo numero: ";
    cin >> a;
    cout << "\nInserire secondo numero: ";
    cin >> b;
    cout << "\nInserire un'operazione: ";
    cin >> op;

    switch(op){
    case '+':
        cout << "\nIl risultato e': " << a+b;
        break;
    case '-':
        cout << "\nIl risultato e': " << a-b;
        break;
    case '*':
        cout << "\nIl risultato e': " << a*b;
        break;
    case '/':
        cout << "\nIl risultato e': " << a/b;
        break;
    case '%':
        cout << "\nIl risultato e': " << a%b;
        break;
    default:
        cout << "\nOperazione non conosciuta!";
    }

    return 0;
}
