# Nota: // è la divisione con risultato intero, quindi arrotonda automaticamente per difetto

# input data
N = int(input().strip())

# I numeri da 1 a 9 non sono eccellenti
if N<2:
    print('-1')
else:
    # Se N è pari possiamo spammare 15, visto che la somma dei numeri sarà
    # sempre multipla di 6 e quindi divisibile per 3 :)
    if N%2==0:
        print('15'*(N//2))
    # Se N è dispari anteponiamo 111 e poi spammiamo 15,
    # visto che la somma dei numeri sarà sempre divisibile per 3 :)
    else:
        print('111'+'15'*((N-3)//2))
