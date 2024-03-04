# Testo:
# https://training.olinfo.it/#/task/ois_police2/statement

N = int(input().strip())
V = list(map(int, input().strip().split()))
visited = [False] * N
maxRes = 0

for i in range(N):
    j = i
    x = i
    resSoFar = 0
    while visited[j] == False:
        visited[j] = True
        j = V[j]
        resSoFar += 1
    while x != j:
        x = V[x]
        resSoFar -= 1

    maxRes = max(maxRes, resSoFar)

print(maxRes)