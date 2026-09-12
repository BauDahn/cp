import sys
sys.setrecursionlimit(300000)

class Node:

    __slots__ = ['children', 'cantidad_hijos']

    def __init__(self):
        self.children = []
        self.cantidad_hijos = 0

    def __repr__(self):
        return f'{self.children}'

class Tree:
    
    def __init__(self, n):
        self.nodes = [Node() for _ in range(n)]
    
    def agregar_nodo(self, jefe, empleado):
        self.nodes[jefe].children.append(self.nodes[empleado])

    def __repr__(self):
        return f'{self.nodes}'

    def solve(self):
        self._dfs(self.nodes[0])

    def _dfs(self, actual):
        for child in actual.children:
            self._dfs(child)
            actual.cantidad_hijos += (child.cantidad_hijos + 1)
        
def solve(data):
    it = iter(data)
    n = int(next(it)) # 5
    arbol = Tree(n)
    for i in range(n - 1): arbol.agregar_nodo(int(next(it)) - 1, i + 1) # [1, 1, 2, 3] --> empleado 0 (lider)
    
    arbol.solve()
    lista = [nodo.cantidad_hijos for nodo in arbol.nodes]
    print(f' '.join(map(str, lista)))
    

if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        solve(data)