from math import *
tri = [[75], [95, 64], [17, 47, 82], [18, 35, 87, 10], [20, 4, 82, 47, 65], [19, 1, 23, 75, 3, 34], [88, 2, 77, 73, 7, 63, 67], [99, 65, 4, 28, 6, 16, 70, 92], [41, 41, 26, 56, 83, 40, 80, 70, 33], [41, 48, 72, 33, 47, 32, 37, 16, 94, 29], [53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14], [70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57], [91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48], [63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31], [4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23]]

cache = []
for i in range(15):
    new = []
    for j in range(i+1):
        new.append(0)
    cache.append(new)


def go(r, c):
    if r < 0 or r > 14 or c < 0 or c > 14:
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

for i in range(15):
    go(14, i)

print(max(cache[14]))
