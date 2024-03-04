#!/usr/bin/env python3
# @check-accepted: examples Nsmall N1000 N10000
# @check-time-limit-exceeded: no-limits
# insert brief description of the solution here


# input data
n = int(input().strip())
v = list(map(int, input().strip().split()))

if n == 1:
    print(0)
    exit()

step = [0 for i in range(n)]
step[n - 1] = n - 1

stack = [0]

for i in range(1, n-1):
    if v[i] - v[i-1] <= v[i+1] - v[i]:
        while stack[-1] > 0 and 2*v[stack[-1]] - v[stack[-1]-1] <= v[i+1]:
            stack.pop()
        step[i] = stack[-1]
    stack.append(i)

stack = [n-1]
for i in range(n-2, 0, -1):
    if v[i+1] - 2*v[i] + v[i-1] < 0:
        while stack[-1] < n-1 and v[stack[-1] + 1] - 2*v[stack[-1]] + v[i-1] < 0:
            stack.pop()
        step[i] = stack[-1]
    stack.append(i)

def find(i):
    if step[i] == i:
        return i
    step[i] = find(step[i])
    return step[i]

for i in range(n):
    print (n-1-find(i), end = ' ')
print()
