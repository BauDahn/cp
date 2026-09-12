import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))

while t:
    n = int(next(it)) * 3
    lista = [0] * n
    for i in range(n - 2):
        if i % 3 == 0:
            lista[i] = (i // 3) + 1
    
    contador = lista[-3]
    for i in range(n):
        if lista[i] == 0:
            lista[i] = contador + 1
            contador += 1
    
    print(' '.join(map(str, lista)))
    t -= 1

