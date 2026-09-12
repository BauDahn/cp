import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    n = int(next(it))
    a = [int(next(it)) for _ in range(n)]

    res = []
    suma_actual = 0
    altura_max = float('inf')
    for i in range(1, n + 1):
        actual = a[i - 1]
        suma_actual += actual

        promedio_actual = suma_actual // i

        altura_max = min(altura_max, promedio_actual)

        res.append(altura_max)
    
    print(' '.join(map(str, res)))



    t -= 1