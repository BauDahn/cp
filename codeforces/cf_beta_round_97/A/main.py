import sys

data = sys.stdin.read().split()
it = iter(data)

n = int(next(it))
a = [int(next(it)) for _ in range(n)]

lista = [0] * (n)
for i in range(n):
    lista[a[i] - 1] = i + 1

print(' '.join(map(str, lista)))