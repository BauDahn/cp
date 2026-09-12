import sys

data = sys.stdin.read().split()
it = iter(data)

n, m, q = int(next(it)), int(next(it)), int(next(it))

INF = float('inf')
distancias = [[INF] * n for _ in range(n)]

for i in range(n):
    distancias[i][i] = 0

for i in range(m):
    a, b, c = int(next(it)), int(next(it)), int(next(it))
    a -= 1; b -= 1
    distancias[a][b] = min(distancias[a][b], c)
    distancias[b][a] = min(distancias[b][a], c)

# Solución con Dijkstra (Demasiado Lenta)
# def shortest_path(adj: list, origen: int, destino: int):
#     if origen == destino: # Caso base por las dudas
#         print(0)
#         return
    
#     distancias = [float('inf')] * (n + 1)
#     distancias[origen] = 0
#     pq = [(0, origen)]

#     while pq:
#         c, v = heapq.heappop(pq)
#         if c > distancias[v]:
#             continue

#         if v == destino:
#             print(c)
#             return
        
#         for coste_camino, u in adj[v]: # Para cada adyacente al nodo que estemos ahora
#             if distancias[v] + coste_camino < distancias[u]:
#                 distancias[u] = distancias[v] + coste_camino
#                 heapq.heappush(pq, (distancias[u], u))
    
#     print(-1)

# Usando Floyd Warshall
# Cuál es la idea de floy-warshall
for k in range(n):
    for i in range(n):
        for j in range(n):
            if distancias[i][k] + distancias[k][j] < distancias[i][j]:
                distancias[i][j] = distancias[i][k] + distancias[k][j]


for i in range(q):
    a, b = int(next(it)), int(next(it))
    dist = distancias[a - 1][b - 1]
    if dist == INF:
        print(-1)
    else:
        print(dist)
