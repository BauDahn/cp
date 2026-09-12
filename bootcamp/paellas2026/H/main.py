import sys

class DSU:

    def __init__(self, nodos:set):
        self.padre = {mismo : mismo for mismo in nodos}
        self.tamaño = {el: 1 for el in nodos}
    
    def find(self, x):
        if self.padre[x] == x:
            # Lo encontramos
            return x
        # Todavía no lo encontramos
        self.padre[x] = self.find(self.padre[x])
        return self.padre[x]
    
    def union(self, x, y):
        x_root = self.find(x)
        y_root = self.find(y)
        if x_root != y_root: # Se pueden unir
            if self.tamaño[x_root] > self.tamaño[y_root]:
                self.tamaño[x_root] += self.tamaño[y_root]
                self.padre[y_root] = x_root
            else:
                self.tamaño[y_root] += self.tamaño[x_root]
                self.padre[x_root] = y_root
            
            return True
        return False


def kruskal(adj:list, nombres:set):
    adj = sorted(adj, key=lambda x: x[2])
    dsu = DSU(nombres)
    n = len(nombres)
    final_tree = []
    for u, v, w in adj:
        if len(final_tree) == n - 1:
            break
        if dsu.union(u,v):
            final_tree.append((u, v, w))
    
    return final_tree


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
