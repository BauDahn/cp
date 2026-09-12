import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    n = int(next(it))
    a = list(int(next(it)) for _ in range(n))
    a.sort()
    centro = a[n // 2]
    izq = 0
    der = n - 1
    contador = 0

    while izq < der:
        if a[izq] == centro and a[der] == centro:
            break

        contador += 1

        if a[izq] < centro and a[der] > centro:
            izq += 1
            der -= 1
        
        elif a[izq] == centro:
            der -= 1
            
        else:
            izq += 1

    print(contador)
    t -= 1
