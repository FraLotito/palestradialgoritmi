# Testo:
# https://training.olinfo.it/#/task/oii_artemoderna/statement

def array_swap(V, i, j):
   while i < j:
       V[i], V[j] = V[j], V[i]
       i += 1
       j -= 1

def ordina(N, V, L):
   i = 0
   start = 0
   counter = 0

   while i < N:
       if i == N - 1 or V[i] < V[i + 1]:
           counter += 1
           array_swap(V, start, i)
           L.append(i - start + 1)
           start = i + 1
       i += 1

   for i in range(N - 1):
       if V[i] > V[i + 1]:
           return False

   return True

n = int(input())
v = list(map(int, input().split()))
l = []

if ordina(n, v, l):
    print("YES")
    print(str(len(l)))
    for val in l:
        print(str(val) + " ", end='')
else:
    print("NO")
