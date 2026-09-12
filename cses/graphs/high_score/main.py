import sys
import heapq


data = sys.stdin.read().split()
it = iter(data)

n, m = int(next(it)), int(next(it))

INF = float('inf')
adj = [[INF] * (n) for i in range(n)]

for i in range(m):
    a, b, c = int(next(it)), int(next(it)), int(next(it))
    a -= 1; b -= 1
    adj[a][b] = c
