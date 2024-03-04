#!/usr/bin/env python3
# NOTE: it is recommended to use this even if you don't understand the following code.

import sys

# uncomment the two following lines if you want to read/write from files
sys.stdin = open('input.txt')
sys.stdout = open('output.txt', 'w')

N = int(input().strip())

A = list(map(int, input().strip().split()))

s = sum(A)
if s % 2 != 0:
    print(str(-1))
else:
    vis = []

    # vis è una matrice in cui:
    # le righe rappresentano gli elementi di A
    # le colonne rappresentano quante parentesi ancora vanno chiuse

    for _ in range(N+1):
        riga = [0] * (s//2 + 1)
        vis.append(riga)
    
    # Oppure si può fare così
    #vis = [[0 for _ in range(s//2+1)] for _ in range(N+1)]
    
    # Le parentesi rimanenti da guardare
    rem = s

    # Nelle celle di vis ci saranno 1 oppure 2:
    # 1 se le A[i] parentesi vanno aperte
    # 2 se le A[i] parentesi vanno chiuse

    # La prima parentesi va aperta per forza
    rem -= A[0]
    vis[1][A[0]] = 1
    
    # Iniziamo a scorrere la matrice
    for i in range(1, N):
        rem -= A[i]
        for j in range(s//2+1):
            if vis[i][j] > 0:
                # j sono le parentesi da chiudere
                # se provando ad aprirne A[i] NON ne apriamo troppe
                # (non ne chiudiamo più di s//2 e nemmeno più delle rimanenti)
                # allora proviamo ad aprirne A[i] e le parentesi da chiudere aumentano (j + A[i])
                if j+A[i] <= s//2 and j+A[i] <= rem:
                    vis[i+1][j+A[i]] = 1
                # j sono le parentesi da chiudere
                # se provando a toglierne A[i] non andiamo in negativo
                # allora ne chiudiamo A[i] e le parentesi da chiudere diminuiscono (j - A[i])
                if j-A[i] >= 0:
                    vis[i+1][j-A[i]] = 2

    # Ovviamente in vis[N][0] deve esserci 2, sennò stampiamo -1
    if vis[N][0] == 2:
        ans = []
        ind, sum = N, 0
        # scorriamo la matrice dal basso verso l'alto andando a ritroso
        # Siccome andiamo a ritroso dovremmo aggiungere le parentesi davanti
        # al risultato, ma questo è costoso, quindi alla fine le stampiamo
        # al contrario
        while ind > 0:
            # se le A[ind-1] parentesi vanno aperte:
            # 1) le aggiungiamo al risultato finale
            # 2) passeremo alla riga sopra della matrice
            # 3) le parentesi da chiudere diminuiscono di A[ind -1]
            if vis[ind][sum] == 1:
                ans.append(A[ind-1] * '(')
                sum -= A[ind-1]
            # se le A[ind-1] parentesi vanno chiuse:
            # 1) le aggiungiamo al risultato finale
            # 2) passeremo alla riga sopra della matrice
            # 3) le parentesi da chiudere aumentano di A[ind -1]
            else:
                ans.append(A[ind-1] * ')')
                sum += A[ind-1]
            ind -= 1
        
        # siccome ans è una lista di parentesi, le uniamo e le stampiamo al contrario
        print(''.join(ans[::-1]))
    else:
        print(str(-1))