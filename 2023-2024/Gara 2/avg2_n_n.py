N, K = map(int, input().split())
K *= N
v = list(map(int, input().split()))

# Il testo ci dice che il prezzo di
# ogni prodotto è massimo 1_000_000_000
max_val = 10**9
sum_val = 0

for x in v:
    sum_val += x

if sum_val == K:
    print(str(0))
else:
    if sum_val < K:
        print(str((K - sum_val + N - 1) // N))
    else:
        i = 1
        while i <= max_val:
            sum = 0
            for x in v:
                sum += max(1, x - i)
            if sum <= K:
                print(str(i))
                exit()
            i += 1







