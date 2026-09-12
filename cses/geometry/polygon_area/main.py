import sys

class Punto:

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Punto(self.x - other.x, self.y - other.y)

    def __mul__(self, other): # Defino por predeterminado el producto vectorial como la multiplicación
        return self.x * other.y - self.y * other.x

def solve():
    n = int(next(it))
    puntos = [Punto(int(next(it)), int(next(it))) for _ in range(n)]
    res = 0
    for i in range(n):
        res += puntos[i - 1] * puntos[i]

    print(abs(res))

if __name__ == '__main__':
    data = sys.stdin.read().split()

    if data:
        it = iter(data)
        solve()