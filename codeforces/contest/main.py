import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    lista = []
    n = next(it)
    if int(n) % 3 == 1: # Empieza por un 1, xd
        suma = 0
        i = 0
        while suma != int(n):
            if i % 2 == 0:
                lista.append(1)
                suma += 1
            else:
                lista.append(2)
                suma += 2
            i += 1
    else:
        suma = 0
        i = 0
        while suma != int(n):
            if i % 2 == 0:
                lista.append(2)
                suma += 2
            else:
                lista.append(1)
                suma += 1
            i += 1

    print(''.join(map(str, lista)))
    t -= 1
