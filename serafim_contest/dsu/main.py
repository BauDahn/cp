class DSU:

    def __init__(self, n: int):
        self.parent = list(range(n + 1))
        self.rank = [0] * (n + 1)

    def find(self, x):
        if self.parent[x] == x:
            # Hay que buscar el padre
            return x

    def union(self, x, y):
        rx, ry = self.find(x), self.find(y)
        if rx == ry: # Hay un ciclo, la unión es imposible
            return False
        # En el caso de que no haya ciclo
        if self.rank[rx] > self.rank[ry]: # Meto y como hijo de x
            self.parent[ry] = rx
        self.parent[y] = rx

        return True