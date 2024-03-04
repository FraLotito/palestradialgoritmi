#!/usr/bin/env python3
# @check-accepted: examples sub1 sub2 full
from sys import stdin, stdout

def rd(): return stdin.readline().strip()
def rdl(x): return map(x, rd().split())
def wt(x): stdout.write(str(x))
def wtl(x): wt(str(x) + '\n')

for qq in range(int(rd())):
  N = rd()
  if len(N) == 1:
    wtl(-1)
    continue
  if N[-2:] in {"00", "25", "50", "75"}:
    wtl(0)
    continue
  if N[-2:] in {"52", "05", "57"}:
    wtl(1)
    continue
  cnt = [0]*10
  for c in N:
    cnt[ord(c) - ord('0')] += 1
  if (N[-1] == '5' and (cnt[2] > 0 or cnt[7] > 0)) or (N[-1] == '0' and (cnt[5] > 0 or cnt[0] > 1)):
    wtl("1")
  elif (N[-2] == '2' and cnt[5] > 0) or (N[-2] == '5' and cnt[0] > 0) or (N[-2] == '7' and cnt[5] > 0) or (N[-2] == '0' and cnt[0] > 1):
    wtl("1")
  elif (cnt[5] > 0 and (cnt[0] > 0 or cnt[2] > 0 or cnt[7] > 0)) or cnt[0] >= 2:
    wtl("2")
  else:
    wtl("-1")
