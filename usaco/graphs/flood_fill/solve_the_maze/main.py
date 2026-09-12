import sys
from collections import deque
sys.setrecursionlimit(20000)

class Laberinto:

    def __init__(self, n, m):
        self.n = n
        self.m = m
        self.laberinto = [[] * (m + 1) for i in range(n)] # Creamos un grid vacío
        self.adyacentes = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    
    def leer_laberinto(self, it): # Función para leer el laberinto
        for i in range(self.n):
            columna = next(it)
            for c in columna:
                self.laberinto[i].append(c)
    
    def __str__(self):
        return f'{self.laberinto}'

    def encerrar_malos(self):
        for i in range(len(self.laberinto)):
            for j in range(len(self.laberinto[0])):
                if self.laberinto[i][j] == 'B': # Si encontramos una mala persona
                    # Miramos sus vecinos
                    for dx, dy in self.adyacentes:
                        ady_x, ady_y = i + dx, j + dy
                        # Comprobamos que el supuesto adyacente este dentro del grid
                        if 0 <= ady_x < len(self.laberinto) and 0 <= ady_y < len(self.laberinto[0]):
                            if self.laberinto[ady_x][ady_y] == 'G': # Si es una buena persona
                                return False
                            if self.laberinto[ady_x][ady_y] == 'B':
                                continue
                            self.laberinto[ady_x][ady_y] = '#' # Reemplazamos con una pared
        return True
    
    def comprobar_caminos(self):
        # Creamos una lista de visitados
        visited = [[False] * len(self.laberinto[0]) for _ in range(len(self.laberinto))]
        # Ahora empiezo a recorrer el laberinto desde la casilla (n, m)
        q = deque()
        q.append((len(self.laberinto) - 1, len(self.laberinto[0]) - 1))

        while q:
            actual = q.popleft() # Agarro el nodo actual que vamos a revisar
            x, y = actual # Coordenadas del nodo ctual
            if self.laberinto[x][y] != '#': # Si la casilla actual no es una pared
                visited[x][y] = True
                # Lanzamos un dfs desde ahí
                if self.laberinto[x][y] == 'B':
                    return "NO"
                for dx, dy in self.adyacentes:
                    ady_x, ady_y = x + dx, y + dy
                    # Comprobamos que el supuesto adyacente este dentro del grid
                    if 0 <= ady_x < len(self.laberinto) and 0 <= ady_y < len(self.laberinto[0]):
                        if visited[ady_x][ady_y]:
                            continue
                        if self.laberinto[ady_x][ady_y] != 'B':
                            q.appendleft((ady_x, ady_y))

        for i in range(len(self.laberinto)):
            for j in range(len(self.laberinto[0])):
                if self.laberinto[i][j] == 'G':
                    if not visited[i][j]:
                        return "NO"
        
        return "YES"


def solve():
    n = int(next(it))
    m = int(next(it))
    maze = Laberinto(n, m)
    maze.leer_laberinto(it)

    if maze.encerrar_malos():
        print(maze.comprobar_caminos())
        return

    print("NO")



if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        it = iter(data)
        t = int(next(it))

        while t:
            solve()
            t -= 1