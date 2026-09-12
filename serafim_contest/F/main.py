import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))

while t:
    n, x = int(next(it)), int(next(it))

    if n == 1: # Caso básico
        print(x)
        t -= 1
        continue

    if n == 2:
        print(bin(x) or '1'*len(bin(x)), x ^ 11111111111)
        t -= 1
        continue

    


    t -= 1