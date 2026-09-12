import sys

primos = {}
def criba(n):
    lista_primos = [True] * (n + 1)
    # Los dos casos bases que tengo que sacar
    lista_primos[0] = False
    lista_primos[1] = False

    for i in range(2, int(n**0.5) + 1): # El 1 ya no es un primo

        if lista_primos[i]:
            for j in range(i*i, n + 1, i):
                lista_primos[j] = False
    
    return [primo for primo, valor in enumerate(lista_primos) if valor]

primos_lista = criba(1000010)
primos_set = set(primos_lista)

data = sys.stdin.read().split()
it = iter(data)

while True:
    n = int(next(it))
    if n == 0:
        break

    encontrado = False
    for p in primos_lista:
        if p >= n:
            break

        complemento = n - p
        if complemento in primos_set:
            print(f'{n} = {p} + {complemento}')
            encontrado = True
            break

    if not encontrado:
        print("Goldbach's conjecture is wrong.")
            
    
