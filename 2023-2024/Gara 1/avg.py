n, k = map(int, input().split())

p = list(map(int, input().split()))

somma = sum(p)

# se la media è già uguale non dobbiamo modificare prodotti
if somma == n * k:
    print(0)
# se la media è minore possiamo aumentare il prezzo del primo prodotto all'infinito
elif somma < n * k:
    print(1)
# se la media è maggiore dobbiamo togliere prodotti
else:
    # ordiniamo in ordine decrescente
    p = sorted(p, reverse=True)
    ris = 0
    rimanente = somma - n * k
    # iniziamo a ridurre il più possibile, partendo dai prodotti più costosi
    for i in range(n):
        da_togliere = min(p[i] - 1, rimanente)
        if da_togliere > 0:
            ris += 1
            rimanente -= da_togliere

    print(ris)