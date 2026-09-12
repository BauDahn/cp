import sys

data = sys.stdin.read().split('\n')

for linea in data:
    if not linea.strip():  # Saltar líneas vacías
        continue
    lista = list(map(int, linea.split()))
    n = lista[0]
    lista = lista[1:]

    if n == 1:
        print("Jolly")
        continue

    diff = set()
    for i in range(len(lista) - 1):
        diff.add(abs(lista[i] - lista[i + 1]))
    
    if diff == set(range(1, n)):
        print("Jolly")
    else:
        print("Not jolly")
