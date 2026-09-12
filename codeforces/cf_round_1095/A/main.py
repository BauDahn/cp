import sys

MOD = 676767677

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))

while t:
    n = int(next(it))
    a = [int(next(it)) for _ in range(n)]

    suma = 0
    for i in range(n):
        if a[i] != 1:
            suma += a[i]
    
    if a[-1] == 1:
        print(suma + 1)
    else:
        print(suma)

    t -= 1