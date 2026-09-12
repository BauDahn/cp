import sys

class DSU:

    def __init__(self, nombres:set):
        self.parents = {mismo : mismo for mismo in nombres}
        self.ranks = {el : 1 for el in nombres}

    def find(self, x: str):
        if self.parents[x] == x:
            return x
        self.parents[x] = self.find(self.parents[x])
        return self.parents[x]

    def union(self, x: str, y: str):
        rx, ry = self.find(x), self.find(y)
        if rx == ry: # Hay un ciclo y la unión no se puede hacer
            return False
        self.ranks[rx] += self.ranks[ry]
        self.parents[ry] = rx
        return True

def kruskal(adj: list, nombres: set):
    adj = sorted(adj, key=lambda x: x[2])
    dsu = DSU(nombres)
    n = len(nombres)
    mst = []
    for u, v, w in adj:
        if len(mst) == n - 1:
            break
        if dsu.union(u, v):
            mst.append((u, v, w))
    
    return mst

data = sys.stdin.read().split()
it = iter(data)

n, m = int(next(it)), int(next(it))
adj = []
for i in range(m):
    adj.append((next(it), next(it), int(next(it))))

nombres = set()
for i in range(m):
    u, v, w = adj[i]
    nombres.add(u)
    nombres.add(v)

mst = kruskal(adj, nombres)
suma = 0
for i in range(len(mst)):
    suma += mst[i][2]

print(suma)
for i in range(len(mst)):
    print(' '.join(map(str, mst[i])))