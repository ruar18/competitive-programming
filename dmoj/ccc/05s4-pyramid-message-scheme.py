from collections import defaultdict

L = int(input())
for _ in range(L):
    g = defaultdict(list)
    n = int(input())
    vis = {}
    q = [None] * n
    f = -1
    for _ in range(n // 2):
        cur = input()
        snd = input()
        g[cur].append(snd)
        g[snd].append(cur)
    vis[snd] = True
    q[0] = snd
    b = 0
    tot = 0
    dis = {}
    dis[snd] = 0
    while f != b:
        cur = q[f + 1]
        f += 1
        for v in g[cur]:
            if v not in vis or not vis[v]:
                q[b + 1] = v
                b += 1
                vis[v] = True
                dis[v] = dis[cur] + 1
    max_dist = 0
    for k, v in dis.items():
        if v > max_dist: max_dist = v
    print(n * 10 - max_dist * 20)
