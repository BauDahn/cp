import sys
from collections import deque

data = sys.stdin.read().split()
it = iter(data)

def son_iguales(a1, a2):
    for num in a1:
        if num in a2:
            continue
        else:
            return False
    return True

t = int(next(it))

while t:
    # n = int(next(it))
    # a = [int(next(it)) for _ in range(n)]
    # b = [int(next(it)) for i in range(n)]

    # a.sort()
    # b.sort()

    # for i in range(n):
    #     if a[i] > b[i]:


    # print(a[-1] * b[0])

    # La idea es agarrar todos los pares de numeros y meterlos en un array asi se cancelan solos y el resto son simplemente los que no esten

    n, k = int(next(it)), int(next(it))
    a = [int(next(it)) for _ in range(2*n)]


    lista1 = []
    lista2 = []
    for i in range(k):
        lista1.append(a[i])
    
    for i in range(k, 2*n):
        if a[i] in lista1 and len(lista1) <= k*2:
            lista1.append(a[i])
    
    posible = 2 * k
    for i in range(2*n):
        if a[i] in lista1:
            continue
        if len(lista2) <= posible + 1:
            lista2.append(a[i])
            posible -= 1
    
    print(' '.join(map(str, lista1)))
    print(' '.join(map(str, lista2)))
            
    t -= 1