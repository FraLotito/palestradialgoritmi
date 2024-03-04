n = int(input())
s = list(map(int, input().split()))
res = 0
for i in s:
    if i < 0:
        res +=1
print(res)