# Corso base di C++

## Hello world (stampa a video)

```cpp
#include<iostream>
using namespace std;

int main() {
    cout << "Ciao mondo!" << endl;
    return 0;
}
```
## Le variabili
```cpp
#include<iostream>
using namespace std;

int main() {
    int a = 5;
    double b = 3.5;
    float c = 7.2;
    char d = 'a';
    
    cout << a << " " << b << " " << c << " " << d << endl;

    return 0;
}
```
## Lettura da tastiera
```cpp
#include<iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Inserire a: ";
    cin >> a;
    cout << "Inserire b: ";
    cin >> b;
    
    return 0;
}
```
