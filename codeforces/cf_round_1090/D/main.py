import sys
import math
from itertools import permutations

# def generador(n, maximo):
#     posibles = list(range(1, maximo + 1)) # Generamos todos los números posibles para la secuencia

#     # Probamos combinaciones de tamaño n
#     for secuencia in permutations(posibles, n):
#         gcds = set()
#         valido = True

#         for i in range(n - 1):
#             g = math.gcd(secuencia[i], secuencia[i + 1])
#             if g in gcds:
#                 valido = False
#                 break
#             gcds.add(g)
        
#         if valido:
#             return secuencia, gcds
    
#     return None, None

# for i in range(2, 12):
#     resultado, gcds = generador(i, 20)
#     print(f'n = {i} -> Secuencia: {resultado} | GCDs obtenidos: {gcds}')

def get_n_primes(n):
    if n <= 0:
        return []
    if n <= 5:
        return [2, 3, 5, 7, 11][:n]
    limit = int(n * (math.log(n) + math.log(math.log(n)))) + 100
    sieve = [True] * (limit + 1)
    sieve[0] = sieve[1] = False
    for p in range(2, int(limit**0.5) + 1):
        if sieve[p]:
            sieve[p*p : limit+1 : p] = [False] * len(sieve[p*p : limit+1 : p])
    primes = [p for p, is_prime in enumerate(sieve) if is_prime]
    return primes[:n]


data = sys.stdin.read().split()
it = iter(data)
primos = get_n_primes(10005)

t = int(next(it))
while t:
    n = int(next(it))
    lista = []
    for i in range(n):
        lista.append(primos[i] * primos[i + 1])
    print(' '.join(map(str, lista)))


    t -= 1