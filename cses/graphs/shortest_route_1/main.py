import sys
from collections import defaultdict
import heapq

data = sys.stdin.read().split()
it = iter(data)

n, m = int(next(it)), int(next(it))
conexiones = defaultdict(list)
for i in range(m):
    a, b, c = int(next(it)), int(next(it)), int(next(it))
    conexiones[a].append((c, b))

# conexiones funciona como un diccionario de adyacencia
heap = [(0, 1)]

dist = [float('inf')] * (n + 1)
dist[1] = 0

while heap:
    coste_actual, origen = heapq.heappop(heap)

    if coste_actual > dist[origen]:
        continue

    for (coste, destino) in conexiones[origen]:
        nuevo_coste = coste + coste_actual
        if nuevo_coste < dist[destino]:
            dist[destino] = nuevo_coste
            heapq.heappush(heap, (nuevo_coste, destino))


print(' '.join(map(str, dist[1:])))
