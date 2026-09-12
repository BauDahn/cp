import sys

data = sys.stdin.read().split()
it = iter(data)

a = next(it)
b = next(it)

lista = []
for i in range(len(a)): # Para cada caracter
    if a[i] != b[i]:
        lista.append(1)
    else:
        lista.append(0)

print(''.join(map(str, lista)))