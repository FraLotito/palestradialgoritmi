n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

rw = 0
ry = 0
rp = 0

for i in range(len(a)):
    if i % 3 == 0:
        rw += a[i]
    elif i % 3 == 1:
        ry += a[i]
    else:
        rp += a[i]

aw = 0
ay = 0
ap = 0

for i in range(len(b)):
    if i % 3 == 0:
        aw += b[i] * rw
        ay += b[i] * ry
        ap += b[i] * rp
    elif i % 3 == 1:
        ay += b[i] * rw
        ap += b[i] * ry
        aw += b[i] * rp
    else:
        ay += b[i] * rp
        ap += b[i] * rw
        aw += b[i] * ry

print(ay, ap, aw)
