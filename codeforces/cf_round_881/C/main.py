import sys

data = sys.stdin.read().split()
it = iter(data)

t = int(next(it))
while t:
    n = int(next(it))
    suma = 0
    while n != 1:
        suma += n
        n //= 2
    
    print(suma + 1)


    t -= 1