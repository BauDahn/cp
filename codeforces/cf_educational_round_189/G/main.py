import sys

def crear_lista_adyacencia(n, divisores):
    adj = [[] for _ in range(n)]
    for divisor in divisores:
        for i in range(n):

            for j in range(i + divisor, n, divisor):
                adj[i].append(j)
                adj[j].append(i)

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    n, m = int(next(it)), int(next(it))
    k = [int(next(it)) for i in range(m)]




    t -= 1