def solv(a,b):
    # 3 match: G1 perde 0 partite
    if a==33 and b<=30:
        print(11,b//3)
        b -= b//3
        print(11,b//2)
        b -= b//2
        print(11,b)
    # 4 match: G1 perde 1 partita
    elif 33<=a<=43 and 11<=b<=41:
        # Tanto a G1 gli facciamo vincere 3 partite dopo
        print(a-33,11)
        b-=11
        print(11,b//3)
        b -= b//3
        print(11,b//2)
        b -= b//2
        print(11,b)
    # 5 match: G1 perde 2 partite
    elif 33<=a<=53 and 22<=b<=52:
        # Tanto a G1 gli facciamo vincere 3 partite dopo
        a-=33
        print(a//2, 11)
        print(a - a//2, 11)
        # G2 ha già vinto 2 match
        b-=22
        print(11,b//3)
        b -= b//3
        print(11,b//2)
        b -= b//2
        print(11,b)
    else:
        print('-1 -1')

t = int(input().strip())
for i in range(t):
    a,b = list(map(int, input().strip().split()))
    solv(a,b)

    