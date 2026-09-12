import sys
sys.setrecursionlimit(20000)
from collections import deque

class Node:

    def __init__(self):
        self.children = [] # Es en verdad una lista de adyacencia camuflada
        self.cantidad_hijos = 0
        self.profundidad = 0
        self.probabilidad = 1.0
        self.parent = None

class Tree:

    def __init__(self, n):
        self.nodes = [Node() for i in range(n)]
        self.esperanza = 0
    
    def agregar_ruta(self, origen, destino):
        self.nodes[origen - 1].children.append(destino - 1)
        self.nodes[destino - 1].children.append(origen - 1)
    
    def solve(self):
        self._dfs()
        return f'{self.esperanza:.10f}'
    
    def _dfs(self):
        q = deque([self.nodes[0]])
        while q:
            actual = q.popleft()

            if len(actual.children) == 1 and actual != self.nodes[0]:
                self.esperanza += actual.profundidad * actual.probabilidad
                continue

            for child_id in actual.children:
                child = self.nodes[child_id]
                if child != actual.parent:
                    child.parent = actual
                    child.profundidad = actual.profundidad + 1
                    if actual == self.nodes[0]: # Nodo raíz
                        child.probabilidad = actual.probabilidad / len(actual.children)
                    else:
                        child.probabilidad = actual.probabilidad / (len(actual.children) - 1)
                    q.append(child)
    

def solve(data):
    it = iter(data)
    n = int(next(it))
    
    arbol = Tree(n)
    for i in range(n - 1):
        origen = int(next(it))
        destino = int(next(it))

        arbol.agregar_ruta(origen, destino)
    
    print(arbol.solve())

if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        solve(data)