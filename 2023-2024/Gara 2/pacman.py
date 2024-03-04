#!/usr/bin/env python3
# @check-accepted: *

import bisect

class dsu:
    def __init__(self, n: int):
        self.p = list(range(n))
        self.r = [0] * n

    def find(self, x: int):
        if self.p[x] != x: self.p[x] = self.find(self.p[x])
        return self.p[x]

    def merge(self, x: int, y: int):
        x = self.find(x)
        y = self.find(y)
        if x == y: return False
        if self.r[x] < self.r[y]: x, y = y, x
        self.p[y] = x
        if self.r[x] == self.r[y]: self.r[x] += 1
        return True

def connected(v: list[tuple[int, int, int]]):
    d = dsu(len(v))
    cc = len(v)

    for i in range(len(v)):
        x, y, z = v[i]
        for p, q, r in [[x+1, y, z], [x, y+1, z], [x, y, z+1]]:
            j = bisect.bisect_left(v, (p, q, r))
            if j < len(v) and v[j] == (p, q, r):
                if d.merge(i, j): cc -= 1

    return cc == 1

def main():
    n = int(input().strip())

    a = list(map(int, input().strip().split()))
    b = list(map(int, input().strip().split()))
    c = list(map(int, input().strip().split()))

    v = sorted(zip(a, b, c))

    m1 = {}
    m2 = {}
    m3 = {}
    m12 = {}
    m13 = {}
    m23 = {}

    for x, y, z in v:
        m1.setdefault(x, []).append((x, y, z))
        m2.setdefault(y, []).append((x, y, z))
        m3.setdefault(z, []).append((x, y, z))
        m12.setdefault((x, y), []).append((x, y, z))
        m13.setdefault((x, z), []).append((x, y, z))
        m23.setdefault((y, z), []).append((x, y, z))

    ans = all(connected(v) for _, v in m1.items()) and \
          all(connected(v) for _, v in m2.items()) and \
          all(connected(v) for _, v in m3.items()) and \
          all(connected(v) for _, v in m12.items()) and \
          all(connected(v) for _, v in m13.items()) and \
          all(connected(v) for _, v in m23.items()) and \
          connected(v)

    print('YES' if ans else 'NO')

if __name__ == '__main__':
    main()
