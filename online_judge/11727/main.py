import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
i = 1
while t:
    lista = [int(next(it)), int(next(it)), int(next(it))]
    lista.sort()
    print(f'Case {i}: {lista[1]}')
    i += 1
    t -= 1