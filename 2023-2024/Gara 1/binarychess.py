#!/usr/bin/env python3
from sys import stdin, stdout


def rd(): return stdin.readline().strip()
def rdl(x): return map(x, rd().split())
def wt(x): stdout.write(str(x))
def wtl(x): wt(str(x) + '\n')


R, C, n = rdl(int)
mp, ans = [dict() for i in range(4)], 1
p, ncc = [-1 for i in range(n)], n


def get(x):
    global p
    if p[x] < 0:
        return x
    p[x] = get(p[x])
    return p[x]


def unite(x, y):
    global p, ncc
    x, y = get(x), get(y)
    if x != y:
        if p[x] < p[y]:
            x, y = y, x
        ncc = ncc - 1
        p[y] += p[x]
        p[x] = y


for i in range(n):
    r, c = rdl(int)
    if r in mp[0]:
        mp[0][r].append(i)
    else:
        mp[0][r] = [i]
    if c in mp[1]:
        mp[1][c].append(i)
    else:
        mp[1][c] = [i]
    if r - c in mp[2]:
        mp[2][r - c].append(i)
    else:
        mp[2][r - c] = [i]
    if r + c in mp[3]:
        mp[3][r + c].append(i)
    else:
        mp[3][r + c] = [i]
for vv in mp:
    for v in vv.values():
        for i in range(len(v) - 1):
            unite(v[i], v[i + 1])
wtl(pow(2, ncc, 1000000007))
