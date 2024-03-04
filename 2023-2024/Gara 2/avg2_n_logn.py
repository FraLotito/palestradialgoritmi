N, K = map(int, input().split())
K *= N

sum_val = 0
v = list(map(int, input().split()))

for x in v:
    sum_val += x

if sum_val == K:
    print(str(0))
elif sum_val < K:
    print(str((K - sum_val + N - 1) // N))
else:
    upper = 10**9
    lower = 0
    while lower < upper:
        mid = (lower + upper) // 2
        
        sum = 0
        for x in v:
            sum += max(1, x - mid)
        
        if sum > K:
            lower = mid + 1
        else:
            upper = mid

    print(str(lower)) # o upper, hanno lo stesso valore