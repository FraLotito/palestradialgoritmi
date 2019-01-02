# Errori che avete fatto e che dovreste cercare di non ripetere

### Array statici con dimensione variabile
__NON__ scrivete mai

```cpp
int n;
in >> n;
int v[n];
```

Sul serio, non fatelo, o chiamo Francesco a sgridarvi. Potete invece scrivere:

* Variabili globali con dimensione statica
```cpp
const int MAX_DIM = 10000;
int v[MAX_DIM];
```

* Array dinamici

```cpp
int n;
in >> n;
int *v = new int[n];
```
