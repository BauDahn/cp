import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    n = int(next(it))
    a = [int(next(it)) for i in range(n)]
    maximo = 0

    for i in range(n):
        for j in range(n):
            maximo = max(maximo, a[i] ^ a[j])


    print(maximo)

    t -= 1