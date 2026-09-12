import sys

def torres(n, origen, destino, auxiliar):
    if n == 0: return # Caso base de la recursión

    torres(n - 1, origen, auxiliar, destino) # Movemos las n - 1 naves al auxiliar

    print(origen, " ", destino)

    torres(n - 1, auxiliar, destino, origen) # Movemos las n - 1 naves del auxiliar al destino

# Entrada rápida de datos en python
data = sys.stdin.read().split()
it = iter(data)

n = int(next(it))
print((1 << n) - 1)

torres(n, 1, 3, 2)