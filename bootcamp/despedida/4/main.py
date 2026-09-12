import sys

# Conseguir los primos hasta el 1000
def sieve(n):
    primos = {i: True for i in range(2, n + 1)}
    for j in range(2, int(n ** 0.5) + 1):
        if primos[j]: # Si es True
            for i in range(2 * j, n + 1, j):
                primos[i] = False
    
    return [clave for clave in primos if primos[clave]]

primos = sieve(1005)

# Ingreso de datos
data = sys.stdin.read().split('\n')
it = iter(data)

next(it) # Me salteo la primera porque no la quiero
bebida = 0
comida =  0
almacen = []
i = 1
while True:
    try:
        nombre, b, c = next(it).split()
        if i in primos:
            bebida += int(b)
            comida += int(c)
        i += 1
    except ValueError:
        # Esto significa que llegamos al almacén de Diego Provencio
        while True:
            try:
                a, b, c = next(it).split()
                almacen.append((int(a), int(b), int(c)))
            except StopIteration:
                break
        break
    except StopIteration:
        break

INF = float('inf')
dp = [[INF] * (comida + 1) for _ in range(bebida + 1)]
dp[0][0] = 0


for cantidad_bebida, cantidad_comida, precio_pack in almacen:
    for b in range(bebida, -1, -1):
        for c in range(comida, -1, -1):
            if dp[b][c] == INF:
                continue
            nb = min(b + cantidad_bebida, bebida)
            nc = min(c + cantidad_comida, comida)
            dp[nb][nc] = min(dp[nb][nc], dp[b][c] + precio_pack)

print(dp[bebida][comida])