import sys

from collections import defaultdict, deque

connect = defaultdict(set)

# input
lines = [line.strip().split() for line in sys.stdin.readlines()]
for line in lines:
    name = line[0]
    # graph construction
    for other in line[1:]:
        connect[other].add(name)
        connect[name].add(other)

erdos = {}
# distanza dalla sorgente è 0
erdos['PAUL_ERDOS'] = 0

# BFS con coda
q = deque(['PAUL_ERDOS'])
while q:
    curr = q.popleft()
    for other in connect[curr]:
        if other in erdos:
            continue
        erdos[other] = erdos[curr] + 1 # la distanza è uguale alla distanza attuale + 1
        q.append(other)

for line in lines:
    if line[0] in erdos:
        print(line[0], erdos[line[0]])
    else:
        print(line[0], 'no-connection')