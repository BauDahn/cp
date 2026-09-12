import sys
from collections import deque

data = sys.stdin.read().split()
it = iter(data)

n, m = int(next(it)), int(next(it))

grid = [[int(next(it)) for i in range(m)] for i in range(n)]
visited = [[False for i in range(m)] for i in range(n)]

islas = 0

direcciones = [(1, 0),
               (-1, 0),
               (0, 1),
               (0, -1),
               (1, 1),
               (-1, -1),
               (1, -1),
               (-1, 1)]

def bfs(i, j):
    q = deque([(i, j)])
    visited[i][j] = True

    while q:
        x, y = q.popleft()
        for dx, dy in direcciones:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m: # Estamos adentro del grid
                if grid[nx][ny] == 1 and not visited[nx][ny]: # Si encuentra una nueva isla
                    visited[nx][ny] = True
                    q.append((nx, ny))
                    

for i in range(n):
    for j in range(m):
        if grid[i][j] == 1 and not visited[i][j]:
            islas += 1
            bfs(i, j)

print(islas)
            