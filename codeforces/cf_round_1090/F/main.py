import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    x, y = int(next(it)), int(next(it))
    nodos = x + y
    print(f'Pares: {x}, Impares: {y}, Número total de nodos: {nodos}')


    t -= 1