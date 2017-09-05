from math import *
tri = []

with open('p067_triangle.txt') as f:
    tri = [[int(x.lstrip("0")) for x in line.split()] for line in f]

print(tri)
cache = []
for i in range(100):
    new = []
    for j in range(i+1):
        new.append(0)
    cache.append(new)


def go(r, c):
    if r < 0 or r > 99 or c < 0 or c > 99:
        return 0
    if cache[r][c] != 0:
        return cache[r][c]
    if c == 0:
        cache[r][c] = tri[r][c] + go(r-1, c)
        return cache[r][c]
    if c == r:
        cache[r][c] = tri[r][c] + go(r-1, r-1)
        return cache[r][c]
    cache[r][c] = tri[r][c] + max(go(r-1, c-1), go(r-1, c))
    return cache[r][c]

for i in range(100):
    go(99, i)

print(max(cache[99]))
