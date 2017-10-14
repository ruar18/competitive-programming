from queue import *

changes = [[-2,-1],[-1,-2],[2,1],[1,2],[1,-2],[-1,2],[2,-1],[-2,1]]

a, b = map(int, input().split())
first = [a,b]
a, b = map(int, input().split())
last = [a,b]
def BFS(start, end):
    q = Queue(maxsize=0)
    dis = {}
    vis = {}
    q.put(start)
    dis[tuple(start)] = 0
    vis[tuple(start)] = True
    while not q.empty():
        cur = q.get()
        for i in range(8):
            new = []
            new.append(cur[0] + changes[i][0])
            new.append(cur[1] + changes[i][1])
            if new[0] < 1 or new[0] > 8 or new[1] < 1 or new[1]>8:
                continue
            if tuple(new) not in vis:
                q.put(new)
                vis[tuple(new)] = True
                dis[tuple(new)] = dis[tuple(cur)] + 1
    return dis[tuple(end)]

print(BFS(first, last))