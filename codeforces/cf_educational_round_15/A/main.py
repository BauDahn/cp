import sys

data = sys.stdin.read().split()
it = iter(data)

n = int(next(it))
a = [int(next(it)) for _ in range(n)]

maximo = 0
local = 1
for i in range(n - 1):
    if a[i] >= a[i + 1]: # Problema. La secuencia corta ahí
        maximo = max(local, maximo)
        local = 1
    else:
        local += 1

print(max(maximo, local))