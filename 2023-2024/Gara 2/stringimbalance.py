#!/usr/bin/env python3
# @check-accepted: examples QVsmall
# @check-time-limit-exceeded: AB LettersSmall no-limits
# passes pypy, not python

from sys import stdin
input = stdin.readline  # to read input quickly

kSigma = 52

def testcase():
    Q = int(input().strip())

    freq=[[0, 'a'], [0, 'b'], [0, 'c'], [0, 'd'], [0, 'e'], [0, 'f'], [0, 'g'], [0, 'h'], [0, 'i'], [0, 'j'], [0, 'k'], [0, 'l'], [0, 'm'], [0, 'n'], [0, 'o'], [0, 'p'], [0, 'q'], [0, 'r'], [0, 's'], [0, 't'], [0, 'u'], [0, 'v'], [0, 'w'], [0, 'x'], [0, 'y'], [0, 'z'], [0, 'A'], [0, 'B'], [0, 'C'], [0, 'D'], [0, 'E'], [0, 'F'], [0, 'G'], [0, 'H'], [0, 'I'], [0, 'J'], [0, 'K'], [0, 'L'], [0, 'M'], [0, 'N'], [0, 'O'], [0, 'P'], [0, 'Q'], [0, 'R'], [0, 'S'], [0, 'T'], [0, 'U'], [0, 'V'], [0, 'W'], [0, 'X'], [0, 'Y'], [0, 'Z']]
    
    length = 0
    good_pairs = 0

    for qq in range(Q):
        occ, ch, ops = input().strip().split()
        occ,ops=int(occ), int(ops)

        length += occ;
        good_pairs += occ*(occ-1)//2

        for i in range(kSigma):
            if freq[i][1] == ch:
                good_pairs += freq[i][0] * occ
                freq[i][0] += occ

                while i+1 < kSigma and freq[i+1][0] < freq[i][0]:
                    freq[i],freq[i+1] = freq[i+1],freq[i]
                    i += 1
                break

        aux_good_pairs = good_pairs
        prev_chg = 0

        for i in range(kSigma-1):
            if ops<=0:
                continue
            change = min(freq[i][0], ops)
            ops -= change

            aux_good_pairs -= change * (freq[i][0] - change)
            aux_good_pairs += change * (freq[kSigma-1][0] + prev_chg)
            prev_chg += change

        print(length*(length-1)//2 - aux_good_pairs)
    return

def solv():
    T = int(input().strip())
    for _ in range(T):
        input()
        testcase()
    return

solv()
