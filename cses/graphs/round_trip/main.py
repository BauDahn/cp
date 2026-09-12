import sys
from collections import defaultdict, deque

class DSU:

    def __init__(self, n: int): 
        self.parent = list(range(n + 1))
        self.rank = [0] * (n + 1) # Cuantos hijos tiene un nodo

    def find(self, x):
        while self.parent[x] != x:
            self.parent[x] = self.parent[self.parent[x]]
            x = self.parent[x]
        return x

    def union(self, x, y):
        rx, ry = self.find(x), self.find(y)
        if rx == ry: # Hay ciclo banda
            return False
        if self.rank[rx] < self.rank[ry]:
            rx, ry = ry, rx
        self.parent[ry] = rx
        if self.rank[rx] == self.rank[ry]:
            self.rank[rx] += self.rank[ry]
        return True

def find_path(adj: dict, start: int, end: int, cycle_edge: tuple):
    prev = {start: None}
    q = deque([start])

    while q:
        node = q.popleft()
        if node == end:
            break
        for neighbor in adj[node]:
            if neighbor not in prev and (node, neighbor) != cycle_edge and (neighbor, node) != cycle_edge:
                prev[neighbor] = node
                q.append(neighbor)
    
    if end not in prev:
        return None
    
    path = []
    curr = end
    while curr is not None:
        path.append(curr)
        curr = prev[curr]
    
    return path[::-1]

data = sys.stdin.read().split()
it = iter(data)

n, m = int(next(it)), int(next(it))
adj = defaultdict(list)
dsu = DSU(n)

cycle_edge = None
for i in range(m):
    a, b = int(next(it)), int(next(it))
    adj[a].append(b)
    adj[b].append(a)
    if cycle_edge is None and not dsu.union(a, b):
        cycle_edge = (a, b)

if cycle_edge == None:
    print("IMPOSSIBLE")
    exit()
    
a, b = cycle_edge
path = find_path(adj, a, b, (a, b))

if path is None or len(path) < 3:
    print("IMPOSSIBLE")
else:
    print(len(path) + 1)
    print(*path, a)

