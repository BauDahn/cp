import sys
from bisect import bisect_left

def sieve(n):
    if n == 0:
        return []
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    for p in range(2, int(n**0.5) + 1):
        if is_prime[p]:
            for i in range(p * p, n + 1, p):
                is_prime[i] = False

    
    return [i for i, prime in enumerate(is_prime) if prime]


data = sys.stdin.read().split()
it = iter(data)

a, b = int(next(it)), int(next(it))
l = min(a, b)
r = max(a, b)

primos = sieve(r)
# Ahora la idea es buscar los super primos en el rango [l, r]
indice_izquierda = bisect_left(primos, l)

# La idea es agarrar cada primo superior a indice_izquierda y usarlo como un índice de la lista primos para encontrar los super primos
super_primos = []
for primo in primos:
    try:
        super_primos.append(primos[primo - 1])
    except:
        break

indice_izquierda = bisect_left(super_primos, l)
print(len(super_primos) - indice_izquierda)




